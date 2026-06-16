#include "ShotBase.h"
#include "../../../Common.h"

CShotBase::CShotBase()
{
	Init();
}

void CShotBase::Init()
{
	m_ActiveFlag = false;
	m_MoveVec = ZERO;
	m_ActiveTime = 0;
}

bool CShotBase::GetActiveFlag()
{
	return m_ActiveFlag;
}

void CShotBase::SetActiveFlag(bool flag)
{
	m_ActiveFlag = flag;
}
