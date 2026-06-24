#include "ProtectCore.h"


void CProtectCore::Init()
{
	m_Hp = CORE_DEFAULT_HP;
	m_ActiveFlag = false;
	m_Pos = CORE_DEFAULT_POS;
	m_Scale = CORE_SIZE;
}

void CProtectCore::Load()
{
	CObject::LoadModel("Data/ActiveObject/ProtectCore.mv1");
	CObject::Update();
	CActor::RequestLoop(0, 1.0f);
}

void CProtectCore::Step()
{
	if (m_Hp <= 0) {
		m_ActiveFlag = false;
	}
}

void CProtectCore::Exit()
{
}

void CProtectCore::Draw()
{
	CObject::Draw();
}

bool CProtectCore::GetIsActive()
{
	return m_ActiveFlag;
}

void CProtectCore::MinusHp(int minus)
{
	m_Hp -= minus;
}

void CProtectCore::AddHp(int plus)
{
	m_Hp += plus;
}
