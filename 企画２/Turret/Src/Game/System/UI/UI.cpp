#include "UI.h"
#include "../../../Lib/Admin/Data.h"
#include "../../../Common.h"


void CUI::Init()
{
	m_Hndl = -1;
}

void CUI::Load()
{
	if (m_Hndl == -1) {
		m_Hndl = LoadGraph("Data/Player/Cross-Hair.png");
	}
}

void CUI::Draw()
{
	DrawRotaGraph(WINDOW_SENTER_X, WINDOW_SENTER_Y, 0.5f, 0.0f, m_Hndl, TRUE);
}

void CUI::Exit()
{
	if (m_Hndl != -1) {
		DeleteGraph(m_Hndl);
		m_Hndl = -1;
	}
}

