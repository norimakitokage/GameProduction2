#include "Player.h"
#include "../../Lib/Math/ActorMove.h"
#include "../../Common.h"
#include "../../Lib/Collision/Collision.h"
#include "Input/Input.h"
#include "PlayerStatus.h"

const VECTOR PLAYER_MODEL_SIZE = VGet(0.008f, 0.008f, 0.008f);

void CPlayer::Init()
{
	CActor::Init();
	this->SetScale(PLAYER_MODEL_SIZE);
	m_NowWallFrame = WALL_MID;
	m_DefaultShotTime = 0;
}

void CPlayer::Load()
{
	LoadModel("Data/Player/Turret.mv1");
}

void CPlayer::Step(CShotMnager& shot, CCameraManager camera)
{
	// 移動処理
	Move();
	// 弾の発射
	Shot(shot, camera);
}

void CPlayer::Update(VECTOR rot)
{
	m_Rot.y = rot.y;
	m_Pos = VAdd(m_Pos, m_MoveVec);
	m_MoveVec = ZERO;
	CObject::Update();
}

void CPlayer::Exit()
{
	CObject::DeleteModel();
}

void CPlayer::Draw()
{
	CObject::Draw();
}

void CPlayer::Move()
{
	CInput* input = CInput::GetInstance();

	// 一番近いフレームを探す処理
	float memLen = 10000000.0f;
	int memNum = -1;
	for (int i = 0; i < WALL_NUM; i++) {
		VECTOR memVec = VSub(m_WallFramePos[i], m_Pos);
		float len = VSize(memVec);
		if (len < memLen) {
			memLen = len;
			memNum = i;
		}
	}
	m_NowWallFrame = (tagWallFrame)memNum;

	// 左に移動
	if (input->IsPush(INPUT_LEFT)) {
		switch (m_NowWallFrame)
		{
		case WALL_LEFT: {
			float pPosX = m_Pos.x;
			float pPosZ = m_Pos.z;
			float wPosX = m_WallFramePos[WALL_LEFT].x;
			float wPosZ = m_WallFramePos[WALL_LEFT].z;
			// 端にたどり着いていないか確認
			if (!CColl::CircleToDot(VGet(wPosX, wPosZ, 0.0f), PLAYER_MOVE_SPD, VGet(pPosX, pPosZ, 0.0f))) {
				m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT], PLAYER_MOVE_SPD);
			}
		}
			break;
		case WALL_LEFT1:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT], PLAYER_MOVE_SPD);
			break;
		case WALL_LEFT2:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT1], PLAYER_MOVE_SPD);
			break;
		case WALL_MID:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT2], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT2:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_MID], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT1:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT2], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT1], PLAYER_MOVE_SPD);
			break;
		}
	}
	// 右に移動
	else if (input->IsPush(INPUT_RIGHT)) {
		switch (m_NowWallFrame)
		{
		case WALL_LEFT:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT1], PLAYER_MOVE_SPD);
			break;
		case WALL_LEFT1:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_LEFT2], PLAYER_MOVE_SPD);
			break;
		case WALL_LEFT2:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_MID], PLAYER_MOVE_SPD);
			break;
		case WALL_MID:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT2], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT2:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT1], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT1:
			m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT], PLAYER_MOVE_SPD);
			break;
		case WALL_RIGHT: {
			float pPosX = m_Pos.x;
			float pPosZ = m_Pos.z;
			float wPosX = m_WallFramePos[WALL_RIGHT].x;
			float wPosZ = m_WallFramePos[WALL_RIGHT].z;
			// 端にたどり着いていないか確認
			if (!CColl::CircleToDot(VGet(wPosX, wPosZ, 0.0f), PLAYER_MOVE_SPD, VGet(pPosX, pPosZ, 0.0f))) {
				m_MoveVec = CActorMove::GetMoveVec(m_Pos, m_WallFramePos[WALL_RIGHT], PLAYER_MOVE_SPD);
			}

		}
			break;
		}
	}
}

void CPlayer::Shot(CShotMnager& shot, CCameraManager camera)
{
	CInput* input = CInput::GetInstance();
	CPlayerStatus* status = CPlayerStatus::GetInstance();

	m_DefaultShotTime++;
	// 射撃ボタンが押されているかつ、インターバルが過ぎている時
	if (input->IsPush(INPUT_SHOT) && m_DefaultShotTime >= status->GetStatus(DEFAULT_SHOT_INTERVAL)) {
		shot.Request(SHOT_DEFAULT, MV1GetFramePosition(m_Hndl,SHOT_FRAME_NUM), camera.GetDirVector());
		m_DefaultShotTime = 0;
	}
}

void CPlayer::SetWallFramePosition(VECTOR* vecArray)
{
	for (int i = 0; i < WALL_NUM; i++) {
		m_WallFramePos[i] = vecArray[i];
	}
}
