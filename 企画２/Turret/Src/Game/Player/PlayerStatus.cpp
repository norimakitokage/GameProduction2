#include "PlayerStatus.h"
#include "../Scene/SceneGame/SceneGame.h"

CPlayerStatus* CPlayerStatus::m_instance = nullptr;

const int DEFAULT_MAX_EXP = 100;

CPlayerStatus::CPlayerStatus() {
	// 初期数値を入力
	for (int i = 0; i < tagStatus::STATUS_NUM; i++) {
		m_Status[i] = DEFAULT_STATUS[i];
	}

	for (int i = 0; i < tagWeapon::WEAPON_NUM; i++) {
		m_Weapon[i] = false;
	}

	m_Exp = 0;
	m_Level = 1;
	m_MemExp = 0;
}

CPlayerStatus::~CPlayerStatus()
{
}

CPlayerStatus* CPlayerStatus::GetInstance() {
	if (m_instance == nullptr) m_instance = new CPlayerStatus;

	return m_instance;
}

void CPlayerStatus::DeleteInstance() {
	if (m_instance != nullptr) {
		delete m_instance;
		m_instance = nullptr;
	}
}

void CPlayerStatus::Step()
{
	if (m_MemExp > 0) {
		if (m_MemExp >= 50) {
			m_Exp += 50;
			m_MemExp -= 50;
		}
		else if (m_MemExp >= 10) {
			m_Exp += 10;
			m_MemExp -= 10;
		}
		else {
			m_Exp += 1;
			m_MemExp -= 1;
		}
	}


}

int CPlayerStatus::GetStatus(tagStatus type)
{
	return m_Status[type];
}

void CPlayerStatus::SetStatus(tagStatus type, int val)
{
	m_Status[type] = val;
}

int CPlayerStatus::GetWeapon(tagWeapon type)
{
	return m_Weapon[type];
}

void CPlayerStatus::SetWeapon(tagWeapon type, bool flag)
{
	m_Weapon[type] = flag;
}

void CPlayerStatus::AddExp(int addNum)
{
	m_MemExp = addNum;


	// レベルアップに必要な経験値はレベル×基本の上限
	if (m_Exp >= (m_Level * DEFAULT_MAX_EXP)) {
		int remeinder = m_Exp % (m_Level * DEFAULT_MAX_EXP);
		int div = m_Exp / (m_Level * DEFAULT_MAX_EXP);
		m_Exp = remeinder;
		
	}
}

void CPlayerStatus::CheckLevelUp()
{

}

