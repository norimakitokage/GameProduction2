#pragma once
#include "../Player/Shot/ShotManager.h"
#include "../Enemy/EnemyManager.h"
#include "../Object/ProtectCore.h"

class CHitCheck
{
public:
	static void EnemyToDefaultShot(CShotMnager& shot, CEnemyManager& enemy);

	static void CoreToEnemy(CProtectCore& core, CEnemyManager& enemy);
};
