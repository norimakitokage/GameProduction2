#pragma once
#include "../ShotBase.h"

const float DEFAULT_SHOT_SPD = 10;
const int DEFAULT_SHOT_ACTIVE_TIME = 120;

class CDefaultShot : public CShotBase {
private:
	// ’e‚Ì‘¬“x
	//float m_Speed;

public:
	void Step();
	void Update();

	// ’e‚ÌŒÄ‚Ño‚µ
	//  VECTOR  moveVec	: ³‹K‰»‚µ‚Ä‚ ‚é’e‚ª”ò‚ñ‚Å‚¢‚­•ûŒü
	void Request(VECTOR moveVec);
};
