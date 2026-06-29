#pragma once
#include "../ShotBase.h"

const float DEFAULT_SHOT_SPD = 5.0f;
const int DEFAULT_SHOT_ACTIVE_TIME = 120;
const float DEFAULT_SHOT_RADIUS = 0.5f;

class CDefaultShot : public CShotBase {
private:
	// ’e‚Ì‘¬“x
	//float m_Speed;

public:
	CDefaultShot();

	void Step();
	void Update();
	void Draw() override;

};
