#pragma once
#include "ShotBase.h"
#include <vector>

using namespace std;


enum tagShotType {
	// 通常弾
	SHOT_DEFAULT,
	// レーザー
	SHOT_BEAM,
	// ミサイル
	SHOT_MISSILE,

	// 総数
	SHOT_NUM
};

class CShotMnager {
private:
	vector<CShotBase*> m_Shot;

	int m_Hndl[tagShotType::SHOT_NUM];

public:
	void Init();
	void Load();
	void Step();
	void Update();
	void Exit();
	void Draw();

public:

	void Request(tagShotType type, VECTOR shotPos, VECTOR moveVec);
};