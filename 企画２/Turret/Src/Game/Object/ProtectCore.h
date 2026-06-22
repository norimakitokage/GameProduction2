#pragma once
#include "../../Lib/Model/Object.h"

const int CORE_DEFAULT_HP = 500;
const VECTOR CORE_DEFAULT_POS = VGet(0.0f, 0.0f, 10.0f);

class CProtectCore : public CObject
{
private:
	// 生存フラグ
	bool m_ActiveFlag;
	// 体力
	int m_Hp;

public:
	void Init();
	void Load();
	void Step();
	void Exit();
	void Draw();

public:
	// 生存フラグ取得
	bool GetIsActive();

	// HPの減算処理
	//  minus	:	減算する値
	void MinusHp(int minus);

	// HPの加算処理
	//  plus	:	追加する値
	void AddHp(int plus);
};

