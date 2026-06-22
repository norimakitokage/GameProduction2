#pragma once
#include "../../Lib/Model/Actor.h"
#include "../Landform/Land/Wall.h"
#include "Shot/ShotManager.h"
#include "../Camera/CameraManager.h"

const float PLAYER_MOVE_SPD = 0.8f;

const int SHOT_FRAME_NUM = 7;

class CPlayer : public CActor
{
private:
	// 壁のボーン座標
	VECTOR m_WallFramePos[tagWallFrame::WALL_NUM];
	// 現在、1番近いボーン番号
	tagWallFrame m_NowWallFrame;

	// 移動ベクトル
	VECTOR m_MoveVec;

	// 通常弾の発射間隔
	int m_DefaultShotTime;

public:
	void Init() override;
	void Load();
	void Step(CShotMnager& shot, CCameraManager camera);
	void Update(VECTOR rot);
	void Exit() override;
	void Draw() override;

private:
	// 移動
	void Move();
	// 弾の発射
	void Shot(CShotMnager& shot, CCameraManager camera);

public:
	void SetWallFramePosition(VECTOR* vecArray);

};


