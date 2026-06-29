#pragma once
#include "../../Lib/Model/Actor.h"
#include "../../Common.h"

const int CORE_DEFAULT_HP = 500;
const VECTOR CORE_SIZE = VGet(0.02f, 0.02f, 0.02f);
const float CORE_RADIUS = 3.0f;

class CProtectCore : public CActor
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

	VECTOR GetCenter();
};

