#include "DefaultEnemy.h"
#include "../../../Lib/Math/Getrand.h"

const VECTOR SPORN_POS = VGet(0.0f, 0.0f, -200.0f);
const float SPOERNWIDE = 50.0f;

void CDefaultEnemy::Init()
{
	m_Type = tagEnemyType::ENEMY_DEFAULT;
	m_Power = DEFAULT_ENEMY_POWER;
	m_Speed = DEFAULT_ENEMY_SPEED;
	m_ActiveFlag = true;
	m_Pos.z = SPORN_POS.z;
	m_Pos.y = SPORN_POS.y;
	m_Pos.x = CRand::Rand(SPORN_POS.x - SPOERNWIDE, SPORN_POS.x + SPOERNWIDE);
	m_Hp = DEFAULT_ENEMY_HP;
	m_Exp = DEFAULT_ENEMY_EXP;
}

void CDefaultEnemy::Draw()
{
	CEnemyBase::Draw();
	DrawSphere3D(GetCenterPos(), ENEMY_RADIUS, 16, RED, RED, TRUE);
}

