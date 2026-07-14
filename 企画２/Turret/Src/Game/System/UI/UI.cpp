#include "UI.h"
#include "../../../Lib/Admin/Data.h"
#include "../../../Common.h"


void CUI::Init()
{
	m_TargetHndl = -1;
}

void CUI::Load()
{
	if (m_TargetHndl == -1) {
		m_TargetHndl = LoadGraph("Data/Player/Cross-Hair.png");
	}
}

void CUI::Draw(CProtectCore& core)
{
	// 照準表示
	DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 0.5f, 0.0f, m_TargetHndl, TRUE);

	// コアの残りHP表示
	DrawBox(WINDOW_SENTER_X - 300, 80, WINDOW_SENTER_X + 300, 150, BLACK, FALSE);
	DrawBox(WINDOW_SENTER_X - 300, 80, WINDOW_SENTER_X + 300, 150, RED, TRUE);
	float f = (float)core.GetHp() / (float)CORE_DEFAULT_HP;
	int x = (int)(f * 600);
	DrawBox(WINDOW_SENTER_X - 300, 80, x + WINDOW_SENTER_X - 300, 150, GREEN, TRUE);

}

void CUI::Exit()
{
	if (m_TargetHndl != -1) {
		DeleteGraph(m_TargetHndl);
		m_TargetHndl = -1;
	}
}

