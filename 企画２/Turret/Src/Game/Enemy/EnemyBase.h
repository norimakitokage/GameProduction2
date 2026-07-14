#pragma once
#include "../../Lib/Model/Actor.h"
#include "../../Common.h"

enum tagEnemyType {
	// ’n•\‚©‚çUŒ‚‚·‚é“G
	ENEMY_DEFAULT,
	// ‹ó‚©‚çUŒ‚‚·‚é“G
	ENEMY_SKY,
	// —£‚ê‚½ˆÊ’u‚©‚çUŒ‚‚·‚é“G
	ENEMY_RANGE,

	// “G‚Ìí—Ş‚Ì‘”
	ENEMY_NUM
};

// “G‚Ì”¼Œa
const float ENEMY_RADIUS = 3.0f;


class CEnemyBase : public CActor 
{
protected:
	tagEnemyType m_Type;

	// ˆÚ“®ƒxƒNƒgƒ‹
	VECTOR m_MoveVec;

	// ¶‘¶ƒtƒ‰ƒO
	bool m_ActiveFlag;

	// HP
	int m_Hp;

	// UŒ‚—Í
	int m_Power;

	// ˆÚ“®‘¬“x
	float m_Speed;

	// ŠŒoŒ±’l
	int m_Exp;

public:
	virtual void Init() = 0;
	virtual void Load(int model);
	virtual void Step();
	virtual void Update();
	virtual void Draw();

public:
	void Request(int model);
	bool GetActiveFlag();
	void SetActiveFlag(bool flag);
	VECTOR GetCenterPos();
	tagEnemyType GetType();
	void MinusHp(int dmg);
	int GetPower();
};

