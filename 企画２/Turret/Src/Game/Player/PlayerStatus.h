#pragma once

// ステータスの種類
enum tagStatus
{
	//	力
	POWER,
	// 通常弾の発射間隔
	DEFAULT_SHOT_INTERVAL,

	STATUS_NUM
};

// ステータスの初期値
const int DEFAULT_STATUS[tagStatus::STATUS_NUM] = {
	// 力
	5,
	// 通常弾発射の間隔
	45,
};

// 武器の種類
enum tagWeapon
{
	// ミサイル
	MISSILE,
	// ビーム
	BEAM,

	WEAPON_NUM
};

class CPlayerStatus {
private:	// シングルトン関連

	static CPlayerStatus* m_instance;

public:
	CPlayerStatus();
	~CPlayerStatus();

	//インスタンス取得
	static CPlayerStatus* GetInstance();

	static void DeleteInstance();

private:	// ステータス関連

	// ステータス保存配列
	int m_Status[tagStatus::STATUS_NUM];

	// 武器のフラグ配列
	bool m_Weapon[tagWeapon::WEAPON_NUM];

public:

	// ステータスを取得
	//  type	:	ステータスの種類
	int GetStatus(tagStatus type);

	// ステータスを設定
	//  type	:	ステータスの種類
	//  val		:	セットする値
	void SetStatus(tagStatus type, int val);

	// 武器のフラグ取得
	//  type	:	武器の種類
	int GetWeapon(tagWeapon type);

	// 武器のフラグ設定
	//	type	:	武器の種類
	//	flag	:	trueがオン,falseがオフ
	void SetWeapon(tagWeapon type, bool flag);

};

