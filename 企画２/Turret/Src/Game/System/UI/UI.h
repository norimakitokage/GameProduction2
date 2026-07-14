#pragma once
#include <DxLib.h>
#include "../../Object/ProtectCore.h"


class CUI
{
private:
	// 照準表示用ハンドル
	int m_TargetHndl;
	
	
public:
	void Init();
	void Load();
	void Draw(CProtectCore& core);
	void Exit();

};

