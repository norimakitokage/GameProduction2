#include "LandformManager.h"



void CLandformManager::Init()
{
	m_Sky.Init();
	m_Wall.Init();
}

void CLandformManager::Load()
{
	m_Sky.Load();

	m_Wall.Load();
}

void CLandformManager::Exit()
{
	m_Sky.Exit();
	m_Wall.Exit();
}

void CLandformManager::Draw()
{
	m_Sky.Draw();


	m_Wall.Draw();
}

VECTOR CLandformManager::GetWallPosition(tagWallFrame frameType)
{
	return m_Wall.GetFramePositon(frameType);
}

VECTOR* CLandformManager::GetAllWallPosition()
{
	VECTOR array[WALL_NUM];
	for (tagWallFrame i = WALL_LEFT; i < WALL_NUM;) {
		array[i] = m_Wall.GetFramePositon(i);
		i = (tagWallFrame)(i + 1);
	}

	return array;
}
