#pragma once
#include "ShotBase.h"
#include <vector>
#include "DefaultShot/DefaultShot.h"


using namespace std;

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
	vector<CShotBase*> GetVector();
};