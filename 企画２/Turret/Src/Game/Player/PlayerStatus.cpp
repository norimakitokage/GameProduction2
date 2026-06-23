#include "PlayerStatus.h"

CPlayerStatus* CPlayerStatus::m_instance = nullptr;

CPlayerStatus::CPlayerStatus() {
	// ‰Šú”’l‚ğ“ü—Í
	for (int i = 0; i < tagStatus::STATUS_NUM; i++) {
		m_Status[i] = DEFAULT_STATUS[i];
	}

	for (int i = 0; i < tagWeapon::WEAPON_NUM; i++) {
		m_Weapon[i] = false;
	}
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

