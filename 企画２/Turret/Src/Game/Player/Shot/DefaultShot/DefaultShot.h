#pragma once
#include "../ShotBase.h"

class CDefaultShot : public CShotBase {
private:

public:
	void Step();
	void Update();
	void Request(VECTOR moveVec);
};
