#include "SceneGame.h"
#include <DxLib.h>
#include "../../../Common.h"
#include "../../../Lib/Controll/Keyboard/Key.h"
#include "../../../Lib/Fade/Fade.h"
#include "../Scene.h"
#include "../../Player/Input/Input.h"
#include "../../HitCheck/HitCheck.h"


tagGameState CSceneGame::m_GameState;

void CSceneGame::Draw()
{
	switch (m_State)
	{
	case CSceneBase::STARTWAIT:
	case CSceneBase::STEP:
	case CSceneBase::UPDATE:
	case CSceneBase::ENDWAIT:
		switch (m_GameState)
		{
		case GAME_PLAY:
			m_Land.Draw();

			m_Player.Draw();

			m_Shot.Draw();

			m_Core.Draw();

			m_Enemy.Draw();

			m_Ui.Draw(m_Core);

		case GAME_LEVELUP:
			break;
		
		}
		break;
	}
}

void CSceneGame::Init()
{
	m_State = LOAD;

	m_GameState = GAME_PLAY;

	CInput* input = CInput::GetInstance();
	input->Init();
	
	m_Camera.Init();
	m_Player.Init();
	m_Land.Init();
	m_Shot.Init();
	m_Core.Init();
	m_Enemy.Init();
	m_Ui.Init();

}

void CSceneGame::Load()
{
	m_Player.Load();
	m_Land.Load();
	m_Shot.Load();
	m_Core.Load();
	m_Enemy.Load();
	m_Ui.Load();

	m_Player.SetPosition(m_Land.GetWallPosition(WALL_MID));

	CFade::RequestFadeIn();
	m_State = STARTWAIT;
}

void CSceneGame::StartWait()
{
	m_Camera.Step(m_Player.GetPosition());
	m_Camera.Update();
	m_Player.Update(m_Camera.GetCamRot());

	if (CFade::IsEndFadeIn()) {
		
		VECTOR* vec;
		vec = m_Land.GetAllWallPosition();
		m_Player.SetWallFramePosition(vec);

		m_State = STEP;
	}
}

void CSceneGame::Step()
{
	CInput* input = CInput::GetInstance();
	input->Step();

	switch (m_GameState)
	{
	case GAME_PLAY:

		m_Camera.Step(m_Player.GetPosition());
		m_Player.Step(m_Shot, m_Camera);
		m_Shot.Step();
		m_Core.Step();
		m_Enemy.Step();

		// “–‚½‚è”»’è
		CHitCheck::EnemyToDefaultShot(m_Shot, m_Enemy);
		CHitCheck::CoreToEnemy(m_Core, m_Enemy);
		break;
	case GAME_LEVELUP:

		break;
	}
	

	if (!m_Core.GetIsActive()) {
		CFade::RequestFadeOut();
		m_State = ENDWAIT;
		return;
	}

	m_State = UPDATE;
}

void CSceneGame::Update()
{
	m_Camera.Update();
	m_Player.Update(m_Camera.GetCamRot());
	m_Shot.Update();
	m_Core.Update();
	m_Enemy.Update();

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
	m_Shot.Exit();
	m_Core.Exit();
	m_Enemy.Exit();
	m_Ui.Exit();

	CScene::SetSceneType(tagSceneType::TITLE);

	m_State = INIT;
}

void CSceneGame::SetGameState(tagGameState state)
{
	m_GameState = state;
}



