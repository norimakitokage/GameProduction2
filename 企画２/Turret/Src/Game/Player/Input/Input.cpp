#include "Input.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Controll/Mouse/Mouse.h"

CInput* CInput::m_Instance = nullptr;

CInput* CInput::GetInstance()
{
	if (m_Instance == nullptr) {
		m_Instance = new CInput;
	}
	return m_Instance;
}

void CInput::DeleteInstance()
{
	delete m_Instance;
}

void CInput::Init()
{
	for (int i = 0; i < tagInputButton::INPUT_NUM; i++) {
		m_IsPush[i] = false;
	}
}

void CInput::Step()
{
	// ショットボタンの確認
	m_IsPush[INPUT_SHOT] = CMouse::Trg(MOUSE_INPUT_LEFT);
	
	// 左移動のボタン確認
	if (CKey::Trg(KEY_INPUT_A) || CKey::Trg(KEY_INPUT_LEFT)) {
		m_IsPush[INPUT_LEFT] = true;
	}
	else {
		m_IsPush[INPUT_LEFT] = false;
	}

	// 右移動のボタン確認
	if (CKey::Trg(KEY_INPUT_D) || CKey::Trg(KEY_INPUT_RIGHT)) {
		m_IsPush[INPUT_RIGHT] = true;
	}
	else {
		m_IsPush[INPUT_RIGHT] = false;
	}

}

bool CInput::IsPush(tagInputButton botton)
{
	return m_IsPush[botton];
}
