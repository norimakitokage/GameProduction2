#pragma once
#include "../../../Lib/Model/Object.h"

class CShotBase : public CObject {
protected:
	// 生存フラグ
	bool m_ActiveFlag;
	// 移動ベクトル
	VECTOR m_MoveVec;
	// 生存時間
	int m_ActiveTime;
public:
	CShotBase();
	void Init();
	virtual void Step() = 0;

public:
	bool GetActiveFlag();
	void SetActiveFlag(bool flag);
};
