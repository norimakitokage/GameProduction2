#pragma once
#include <DxLib.h>

class CActorMove {
public:
	//アクターの向いている方向から移動量を計算する関数
	// float	:	対象のY軸回転値
	// float	:	移動速度
	static VECTOR GetMoveVec(float rotY, float spd);

	// 2点の座標から移動ベクトルを計算する関数
	// VECTOR	:	現在の座標
	// VECTOR	:	行きたい座標
	// float	:	向かう速度
	static VECTOR GetMoveVec(VECTOR nowPos, VECTOR nextPos, float speed);
};

