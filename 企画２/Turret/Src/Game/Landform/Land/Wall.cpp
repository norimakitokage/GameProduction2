#include "Wall.h"

// “V‹…‚Ì‘å‚«‚³
const VECTOR WALL_SIZE = VGet(0.03f, 0.03f, 0.03f);


void CWall::Load()
{
	LoadModel("Data/Landform/Land/Wall.mv1");
	SetScale(WALL_SIZE);
	Update();
}

VECTOR CWall::GetFramePositon(tagWallFrame frameType)
{
	return MV1GetFramePosition(m_Hndl,WALL_FRAME_NUMBER[(int)frameType]);
}
