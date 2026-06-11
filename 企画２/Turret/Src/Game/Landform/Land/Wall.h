#pragma once
#include "../../../Lib/Model/Object.h"

// 壁のボーン番号
enum tagWallFrame
{
	WALL_LEFT,		// 壁の一番左
	WALL_LEFT1,		// ↓左から1番目
	WALL_LEFT2,		// ↓左から2番目
	WALL_MID,		// 壁の真ん中
	WALL_RIGHT2,	// ↑右から2番目
	WALL_RIGHT1,	// ↑右から1番目
	WALL_RIGHT,		// 壁の一番右

	WALL_NUM
};

// 壁のフレーム番号
const int WALL_FRAME_NUMBER[WALL_NUM] = {
	13,
	11,
	9,
	7,
	15,
	17,
	19
};


class CWall : public CObject
{
public:
	void Load();

	// 任意の壁のボーンの位置を取得
	VECTOR GetFramePositon(tagWallFrame frameType);
	
};
