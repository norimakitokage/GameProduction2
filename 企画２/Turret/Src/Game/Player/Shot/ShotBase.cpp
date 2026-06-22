#include "ShotBase.h"
#include "../../../Common.h"

CShotBase::CShotBase()
{
	Init();
}

CShotBase::~CShotBase()
{
}

void CShotBase::Init()
{
	m_ActiveFlag = false;
	m_MoveVec = ZERO;
	m_ActiveTime = 0;
}

void CShotBase::Draw()
{
}

void CShotBase::Request(VECTOR pos, VECTOR moveVec, int time)
{
	m_Pos = pos;
	m_MoveVec = moveVec;
	m_ActiveTime = time;
	m_ActiveFlag = true;
}

bool CShotBase::GetActiveFlag()
{
	return m_ActiveFlag;
}

void CShotBase::SetActiveFlag(bool flag)
{
	m_ActiveFlag = flag;
}
