#include "EnemyManager.h"
#include "DefaultEnemy/DefaultEnemy.h"

const char* ENEMY_HNDL_PATH[] = {
	"",
	"",
	""
};


void CEnemyManager::Init()
{
	for (int i = 0; i < tagEnemyType::ENEMY_NUM; i++) {
		m_ArrivalFlag[i] = false;
		m_OrgModel[i] = -1;
		m_WaitTime[i] = ENEMY_WAIT_TIME[i];
	}

	m_ArrivalFlag[tagEnemyType::ENEMY_DEFAULT] = true;

	m_Enemy.clear();
}

void CEnemyManager::Load()
{
	for (int i = 0; i < tagEnemyType::ENEMY_NUM; i++) {
		m_OrgModel[i] = MV1LoadModel(ENEMY_HNDL_PATH[i]);
	}
}

void CEnemyManager::Step()
{
	Request();

	if (m_Enemy.empty()) return;

	for (auto enemy = m_Enemy.begin(); enemy != m_Enemy.end();) {
		(*enemy)->Step();
		if (!(*enemy)->GetActiveFlag()) {
			enemy = m_Enemy.erase(enemy);
		}
		else {
			++enemy;
		}
	}
}

void CEnemyManager::Update()
{
	for (auto enemy = m_Enemy.begin(); enemy != m_Enemy.end();) {
		(*enemy)->Update();
		++enemy;
	}
}

void CEnemyManager::Exit()
{
	for (auto enemy = m_Enemy.begin(); enemy != m_Enemy.end();) {
		(*enemy)->Exit();
		++enemy;
	}
}

void CEnemyManager::Draw()
{
	for (auto enemy = m_Enemy.begin(); enemy != m_Enemy.end();) {
		(*enemy)->Draw();
		++enemy;
	}
}

void CEnemyManager::Request()
{
	for (int i = 0; i < tagEnemyType::ENEMY_NUM; i++) {
		if (m_ArrivalFlag[i]) {
			m_WaitTime[i]--;
			if (m_WaitTime[i] <= 0) {
				CEnemyBase* enemy;
				switch (i)
				{
				case 0:
					enemy = new CDefaultEnemy;
					enemy->Request(m_OrgModel[i]);
					break;
				case 1:
					enemy = new CDefaultEnemy;
					enemy->Request(m_OrgModel[i]);
					break;
				case 2:
					enemy = new CDefaultEnemy;
					enemy->Request(m_OrgModel[i]);
					break;
				}
				m_Enemy.push_back(enemy);

				m_WaitTime[i] = ENEMY_WAIT_TIME[i];
			}
		}
	}
}

vector<CEnemyBase*> CEnemyManager::GetVector()
{
	return m_Enemy;
}
