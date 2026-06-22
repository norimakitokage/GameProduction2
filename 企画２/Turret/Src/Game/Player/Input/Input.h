#pragma once

enum tagInputButton 
{
	INPUT_SHOT,
	INPUT_LEFT,
	INPUT_RIGHT,

	INPUT_NUM
};

class CInput 
{
private:
	static CInput* m_Instance;

public:
	static CInput* GetInstance();
	static void DeleteInstance();

private:
	// ボタンが押されているかを確認
	bool m_IsPush[tagInputButton::INPUT_NUM];

public:
	void Init();
	void Step();

public:
	bool IsPush(tagInputButton botton);

};
