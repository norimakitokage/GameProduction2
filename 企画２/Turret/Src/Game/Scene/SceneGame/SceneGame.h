#pragma once
#include "../SceneBase.h"
#include "../../Player/Player.h"
#include "../../Camera/CameraManager.h"
#include "../../Landform/LandformManager.h"
#include "../../Player/Shot/ShotManager.h"
#include "../../Object/ProtectCore.h"
#include "../../Enemy/EnemyManager.h"
#include "../../System/UI/UI.h"

enum tagGameState
{
	GAME_PLAY,
	GAME_LEVELUP,
};

class CSceneGame : public CSceneBase
{
private:
	static tagGameState m_GameState;

private:
	CPlayer m_Player;

	CCameraManager m_Camera;

	CLandformManager m_Land;

	CShotMnager m_Shot;

	CProtectCore m_Core;

	CEnemyManager m_Enemy;

	CUI m_Ui;
public:

	void Draw();

	void SetGameState(tagGameState state);

private:
	void Init();
	void Load();
	void StartWait();
	void Step();
	void Update();
	void EndWait();
	void Exit();
};
