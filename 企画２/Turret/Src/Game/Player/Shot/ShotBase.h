#pragma once
#include "../../../Lib/Model/Object.h"

enum tagShotType {
	// 通常弾
	SHOT_DEFAULT,
	// レーザー
	SHOT_BEAM,
	// ミサイル
	SHOT_MISSILE,

	// 総数
	SHOT_NUM
};

class CShotBase : public CObject {
protected:
	// 生存フラグ
	bool m_ActiveFlag;
	// 移動ベクトル
	VECTOR m_MoveVec;
	// 生存時間
	int m_ActiveTime;
	// 種類
	tagShotType m_Type;

public:
	CShotBase();
	virtual ~CShotBase();

	void Init();
	virtual void Step() = 0;
	virtual void Draw();

public:
	// 玉の呼び出し
	//  pos		:	初期座標
	//  moveVec	:	移動ベクトル
	//  time	:	時間
	void Request(VECTOR pos, VECTOR moveVec, int time);

	// 移動ベクトルの設定
	void SetMoveVec();

	// 生存フラグを取得
	bool GetActiveFlag();
	// 生存フラグのセット
	void SetActiveFlag(bool flag);

	tagShotType GetType();
};
