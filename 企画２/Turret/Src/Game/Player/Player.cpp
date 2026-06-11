#include "Player.h"
#include "../../Lib/Controll/Keyboard/Key.h"

const VECTOR PLAYER_MODEL_SIZE = VGet(0.008f, 0.008f, 0.008f);

void CPlayer::Init()
{
	CActor::Init();
	this->SetScale(PLAYER_MODEL_SIZE);
}

void CPlayer::Load()
{
	LoadModel("Data/Player/Turret.mv1");
}

void CPlayer::Step()
{
	if (CKey::Trg(KEY_INPUT_A)) {

	}
	else if (CKey::Trg(KEY_INPUT_D)) {

	}
}

void CPlayer::Update()
{
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
