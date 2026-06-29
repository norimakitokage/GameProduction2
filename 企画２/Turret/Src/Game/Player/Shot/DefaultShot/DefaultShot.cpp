#include "DefaultShot.h"
#include "../../Common.h"

CDefaultShot::CDefaultShot()
{
	CShotBase::Init();
	m_Type = tagShotType::SHOT_DEFAULT;
}

void CDefaultShot::Step()
{
	m_ActiveTime--;
	if (m_ActiveTime <= 0 || m_Pos.y < -5.0f) {
		m_ActiveFlag = false;
	}
}

void CDefaultShot::Update()
{
	m_Pos = VAdd(m_Pos, m_MoveVec);
	CShotBase::Update();
}

void CDefaultShot::Draw()
{
	DrawSphere3D(m_Pos, DEFAULT_SHOT_RADIUS, 16, BLUE, BLACK, TRUE);
	CShotBase::Draw();
}


