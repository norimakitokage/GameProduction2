#pragma once
#include <DxLib.h>

// 0`10‚Ìƒnƒ“ƒhƒ‹”
const int COUNT_HNDL_NUM = 10;

// 1‚Â1‚Â‚Ì‰æ‘œ‚Ì‘å‚«‚³
const int COUNT_HNDL_SIZE_X = 16;
const int COUNT_HNDL_SIZE_Y = 32;

// ‰¡‚Ì–‡”
const int COUNT_HNDL_X_NUM = 10;
// c‚Ì–‡”
const int COUNT_HNDL_Y_NUM = 1;

// ŠÔ‚ğŠ„‚é”
const int TIME_DIV = 60;

class CCount 
{
private:
	// 
	int m_MiliSecond;
	int m_Second;
	int m_Minute;
	int m_Hour;

	int m_Hndl[COUNT_HNDL_NUM];

public:
	void Init();
	void Load();
	void Step();
	void Draw();
	void Exit();
};
