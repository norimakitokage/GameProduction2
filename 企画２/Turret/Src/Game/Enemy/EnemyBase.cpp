#include "EnemyBase.h"

void CEnemyBase::Load(int model)
{
	CActor::LoadDuplicateModel(model);
}

void CEnemyBase::Step()
{
	if (m_Hp <= 0) {
		m_ActiveFlag = false;
	}
}

void CEnemyBase::Update()
{
	m_Pos = VAdd(m_Pos, m_MoveVec);
	CActor::Update();
}

void CEnemyBase::Draw()
{
	CActor::Draw();
}

void CEnemyBase::Request(int model)
{
	// 初期化
	Init();
	// モデルの読み込み
	Load(model);
	// コアへと向かう移動ベクトルを設定
	VECTOR vec = VSub(CORE_DEFAULT_POS, m_Pos);
	vec = VScale(VNorm(vec), m_Speed);
	m_MoveVec = vec;
}

bool CEnemyBase::GetActiveFlag()
{
	return m_ActiveFlag;
}

void CEnemyBase::SetActiveFlag(bool flag)
{
	m_ActiveFlag = flag;
}

VECTOR CEnemyBase::GetCenterPos()
{
	return VGet(m_Pos.x, m_Pos.y + ENEMY_RADIUS, m_Pos.z);
}

tagEnemyType CEnemyBase::GetType()
{
	return m_Type;
}

void CEnemyBase::MinusHp(int dmg)
{
	m_Hp -= dmg;
}
