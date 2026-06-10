#include "LandformManager.h"

const VECTOR SKY_SIZE = VGet(100.0f, 100.0f, 100.0f);

const VECTOR WALL_SIZE = VGet(0.001f, 0.001f, 0.001f);

void CLandformManager::Init()
{
	m_Sky.Init();
	m_Wall.Init();
}

void CLandformManager::Load()
{
	m_Sky.LoadModel("Data/Landform/Sky/sky.mv1");
	m_Sky.SetScale(SKY_SIZE);
	m_Sky.Update();

	m_Wall.LoadModel("Data/Landform/Wall/wall.mv1");
	m_Wall.SetScale(WALL_SIZE);
	m_Wall.Update();
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
