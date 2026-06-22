#include "ProtectCore.h"

void CProtectCore::Init()
{
	m_Hp = CORE_DEFAULT_HP;
	m_ActiveFlag = false;
}

void CProtectCore::Load()
{
	CObject::LoadModel("");
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
