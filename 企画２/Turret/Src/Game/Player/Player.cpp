#include "Player.h"
#include "../../Lib/Controll/Keyboard/Key.h"
#include "../../Lib/Math/ActorMove.h"
#include "../../Common.h"

const VECTOR PLAYER_MODEL_SIZE = VGet(0.008f, 0.008f, 0.008f);

void CPlayer::Init()
{
	CActor::Init();
	this->SetScale(PLAYER_MODEL_SIZE);
	m_NowWallFrame = WALL_MID;
	
}

void CPlayer::Load()
{
	LoadModel("Data/Player/Turret.mv1");
}

void CPlayer::Step()
{
	// ˆê”Ô‹ß‚¢ƒtƒŒ[ƒ€‚ğ’T‚·ˆ—
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

	// ¶‚ÉˆÚ“®
	if (CKey::Trg(KEY_INPUT_A)) {
		switch (m_NowWallFrame)
		{
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
	// ‰E‚ÉˆÚ“®
	else if (CKey::Trg(KEY_INPUT_D)) {
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
		}
	}
}

void CPlayer::Update()
{
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

void CPlayer::SetWallFramePosition(VECTOR* vecArray)
{
	for (int i = 0; i < WALL_NUM; i++) {
		m_WallFramePos[i] = vecArray[i];
	}
}
