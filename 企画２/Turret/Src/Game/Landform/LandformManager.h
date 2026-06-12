#pragma once
#include "Sky/Sky.h"
#include "Land/Wall.h"
#include "Land/Ground.h"

class CLandformManager
{
private:
	CSky m_Sky;
	CWall m_Wall;
	CGround m_Ground;

private:
	//VECTOR m_WallFramePos[tagWallFrame::WALL_NUM];

public:
	void Init();
	void Load();
	void Exit();
	void Draw();

public:
	VECTOR GetWallPosition(tagWallFrame frameType);
	VECTOR* GetAllWallPosition();
};