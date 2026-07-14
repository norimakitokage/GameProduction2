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

	// プレイヤーの経験値
	int m_Exp;

	// 獲得経験値量保存
	int m_MemExp;

	// プレイヤーのレベル
	int m_Level;

public:
	// データの計算
	void Step();

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

	// 経験値を取得した時
	//  addNum	:	追加する経験値の値
	void AddExp(int addNum);

private:
	// レベルアップできるか確認
	void CheckLevelUp();

};

