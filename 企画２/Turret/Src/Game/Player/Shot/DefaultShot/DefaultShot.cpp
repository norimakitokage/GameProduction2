#include "DefaultShot.h"


void CDefaultShot::Step()
{
	m_ActiveTime--;
	if (m_ActiveTime <= 0) {
		m_ActiveFlag = false;
	}
}

void CDefaultShot::Update()
{
	m_Pos = VAdd(m_Pos, m_MoveVec);
	CShotBase::Update();
}

void CDefaultShot::Request(VECTOR moveVec)
{
	m_MoveVec = VScale(moveVec, DEFAULT_SHOT_SPD);
	m_ActiveTime = DEFAULT_SHOT_ACTIVE_TIME;
	m_ActiveFlag = true;
}
