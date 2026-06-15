#pragma once
#include "../../../Lib/Model/Object.h"

class CShotBase : public CObject {
protected:
	// 生存フラグ
	bool m_ActiveFlag;
	// 移動ベクトル
	VECTOR m_MoveVec;
public:
	CShotBase();
	void Init();
	virtual void Step() = 0;
};
