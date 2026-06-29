#pragma once
#include "EnemyBase.h"
#include <vector>

using namespace std;

const int ENEMY_WAIT_TIME[tagEnemyType::ENEMY_NUM] = {
	120,
	180,
	240
};


class CEnemyManager
{
private:
	// 敵クラスを動かすベクター
	vector<CEnemyBase*> m_Enemy;

	// 敵を出現させるフラグ
	bool m_ArrivalFlag[tagEnemyType::ENEMY_NUM];

	// それぞれの敵の出現待機時間
	int m_WaitTime[tagEnemyType::ENEMY_NUM];

	// 敵の種類ごとのオリジナルモデル
	int m_OrgModel[tagEnemyType::ENEMY_NUM];

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Exit();
	void Draw();

private:
	void Request();

public:
	vector<CEnemyBase*> GetVector();
};
