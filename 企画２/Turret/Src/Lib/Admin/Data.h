#pragma once

class CData{
private:
	int m_Score;			//ゲームのスコア

public:
	CData();
	~CData();

	//インスタンス取得
	static CData* GetInstance();
	
	static void DeleteInstance();

	//スコア操作
	int GetScore();
	void SetScore(int num);
	void AddScore(int num);

private:
	static CData* m_instance;

	
};


