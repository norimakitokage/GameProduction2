#include "SceneGame.h"
#include <DxLib.h>
#include "../../../Common.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Fade/Fade.h"
#include "../Scene.h"



void CSceneGame::Draw()
{
	switch (m_State)
	{
	case CSceneBase::STARTWAIT:
	case CSceneBase::STEP:
	case CSceneBase::UPDATE:
	case CSceneBase::ENDWAIT:
		m_Land.Draw();

		m_Player.Draw();

		break;
	}
}


void CSceneGame::Init()
{
	m_State = LOAD;
	
	m_Camera.Init();
	m_Player.Init();
	m_Land.Init();

}

void CSceneGame::Load()
{
	m_Player.Load();
	m_Land.Load();

	m_Player.SetPosition(m_Land.GetWallPosition(WALL_MID));

	CFade::RequestFadeIn();
	m_State = STARTWAIT;
}

void CSceneGame::StartWait()
{
	m_Camera.Step(m_Player.GetPosition());
	m_Camera.Update();

	if (CFade::IsEndFadeIn()) {
		
		VECTOR* vec;
		vec = m_Land.GetAllWallPosition();
		m_Player.SetWallFramePosition(vec);

		m_State = STEP;
	}
}

void CSceneGame::Step()
{
	m_Camera.Step(m_Player.GetPosition());
	m_Player.Step();

	if (CKey::Rep(KEY_INPUT_RETURN)) {
		CFade::RequestFadeOut();
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneGame::Update()
{
	m_Camera.Update();
	m_Player.Update();

	m_State = STEP;
}

void CSceneGame::EndWait()
{
	if (CFade::IsEndFadeOut()) {
		m_State = EXIT;
	}
}

void CSceneGame::Exit()
{
	m_Player.Exit();
	m_Land.Exit();

	CScene::SetSceneType(tagSceneType::TITLE);

	m_State = INIT;
}
