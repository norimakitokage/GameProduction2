#pragma once

enum tagStatus
{
	POWER,
	SHOT_INTERVAL,

	NUM
};

const int DEFAULT_STATUS[tagStatus::NUM] = {
	5,
	60,
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
	int m_Status[tagStatus::NUM];

public:

	// ステータスを取得
	//  type	:	ステータスの種類
	int GetStatus(tagStatus type);

	// ステータスを設定
	//  type	:	ステータスの種類
	//  val		:	セットする値
	void SetStatus(tagStatus type, int val);
};

