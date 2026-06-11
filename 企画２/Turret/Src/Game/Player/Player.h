#pragma once
#include "../../Lib/Model/Actor.h"
#include "../Landform/Land/Wall.h"

class CPlayer : public CActor
{
private:
	// 壁のボーン座標
	VECTOR m_WallFramePos[tagWallFrame::WALL_NUM];
	// 現在、1番近いボーン番号
	tagWallFrame m_NowWallFrame;

public:
	void Init() override;
	void Load();
	void Step();
	void Update() override;
	void Exit() override;
	void Draw() override;

public:
	void SetWallFramePosition(VECTOR* vecArray);
};


