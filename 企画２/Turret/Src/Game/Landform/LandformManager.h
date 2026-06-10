#pragma once
#include "Sky/Sky.h"
#include "Land/Wall.h"

class CLandformManager
{
private:
	CSky m_Sky;
	CWall m_Wall;

private:
	VECTOR m_WallFramePos[tagWallFrame::WALL_NUM];

public:
	void Init();
	void Load();
	void Exit();
	void Draw();

};