#include "Count.h"

void CCount::Init()
{
	// 全部の初期化
	m_MiliSecond = 0;
	m_Second = 0;
	m_Minute = 0;
	m_Hour = 0;

	for (int i = 0; i < COUNT_HNDL_NUM; i++) {
		m_Hndl[i] = -1;
	}
}

void CCount::Load()
{
	LoadDivGraph("", COUNT_HNDL_NUM, COUNT_HNDL_X_NUM, COUNT_HNDL_Y_NUM,
		COUNT_HNDL_SIZE_X, COUNT_HNDL_SIZE_Y, m_Hndl);
}

void CCount::Step()
{
	m_MiliSecond++;
	// 毎フレームのカウントを60で割った数を秒数とする
	if (m_MiliSecond >= 60) {
		m_Second++;
		m_MiliSecond = 0;
	}
	if (m_Second >= 60) {
		m_Minute++;
		m_Second = 0;
	}
	if (m_Minute >= 60) {
		m_Hour++;
		m_Minute = 0;
	}
}

void CCount::Draw()
{
	
}

void CCount::Exit()
{
	for (int i = 0; i < COUNT_HNDL_NUM; i++) {
		if (m_Hndl[i] != -1) {
			DeleteGraph(m_Hndl[i]);
			m_Hndl[i] = -1;
		}
	}
}
