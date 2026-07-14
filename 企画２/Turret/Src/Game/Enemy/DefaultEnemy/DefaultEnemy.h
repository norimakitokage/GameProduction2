#pragma once
#include "../EnemyBase.h"

const int DEFAULT_ENEMY_POWER = 5;
const float DEFAULT_ENEMY_SPEED = 0.8f;
const int DEFAULT_ENEMY_HP = 10;
const int DEFAULT_ENEMY_EXP = 5;

class CDefaultEnemy : public CEnemyBase 
{
private:

public:
	void Init() override;
	void Draw();
};
