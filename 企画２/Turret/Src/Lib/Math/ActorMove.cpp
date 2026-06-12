#include <math.h>
#include "actorMove.h"
#include "../../common.h"


//アクターの移動量を計算する関数
VECTOR CActorMove::GetMoveVec(float rotY, float spd) {
	VECTOR vec = ZERO;
	vec.x = spd * sinf(rotY);
	vec.z = spd * cosf(rotY);

	return vec;
}

// 座標から次の移動ベクトルを取得
VECTOR CActorMove::GetMoveVec(VECTOR nowPos, VECTOR nextPos, float speed)
{
	VECTOR vec = VSub(nextPos, nowPos);
	vec = VNorm(vec);
	vec = VScale(vec, speed);

	return vec;
}

