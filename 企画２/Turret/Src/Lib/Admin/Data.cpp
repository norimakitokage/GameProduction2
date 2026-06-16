#include "data.h"

CData* CData::m_instance = nullptr;

CData::CData(){
	m_Score = 0;
}

CData::~CData()
{
}

CData* CData::GetInstance() {
	if (m_instance == nullptr) m_instance = new CData;

	return m_instance;
}

void CData::DeleteInstance() {
	if (m_instance != nullptr) {
		delete m_instance;
		m_instance = nullptr;
	}
}

int CData::GetScore()
{
	return 0;
}

void CData::SetScore(int num)
{
}

void CData::AddScore(int num)
{
}

