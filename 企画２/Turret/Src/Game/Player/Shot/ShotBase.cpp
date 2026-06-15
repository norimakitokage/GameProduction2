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
}
