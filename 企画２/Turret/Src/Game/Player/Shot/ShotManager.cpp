#include "ShotManager.h"
#include "DefaultShot/DefaultShot.h"

const char* SHOT_MODEL_PATH[tagShotType::SHOT_NUM] = {
	"",
	"",
	"",
};

void CShotMnager::Init()
{
	for (int i = 0; i < tagShotType::SHOT_NUM; i++) {
		m_Hndl[i] = -1;
	}

	m_Shot.clear();
}

void CShotMnager::Load()
{
	for (int i = 0; i < tagShotType::SHOT_NUM; i++) {
		m_Hndl[i] = MV1LoadModel(SHOT_MODEL_PATH[i]);
	}
}

void CShotMnager::Step()
{
	if (m_Shot.empty()) return;
	
	for (auto shot = m_Shot.begin(); shot != m_Shot.end();) {
		(*shot)->Step();
		if (!(*shot)->GetActiveFlag()) {
			shot = m_Shot.erase(shot);
		}
		else {
			++shot;
		}
	}
}

void CShotMnager::Update()
{
	for (auto shot = m_Shot.begin(); shot != m_Shot.end();) {
		(*shot)->Update();
		++shot;
	}
}

void CShotMnager::Exit()
{
}

void CShotMnager::Draw()
{
	if (m_Shot.empty()) return;

	for (auto shot = m_Shot.begin(); shot != m_Shot.end();) {
		(*shot)->Draw();
		++shot;
	}
}

void CShotMnager::Request(tagShotType type, VECTOR shotPos, VECTOR moveVec)
{
	CShotBase* shot;

	switch (type)
	{
	case SHOT_DEFAULT:
		shot = new CDefaultShot();
		shot->Request(shotPos, VScale(moveVec, DEFAULT_SHOT_SPD), DEFAULT_SHOT_ACTIVE_TIME);
		shot->LoadDuplicateModel(m_Hndl[tagShotType::SHOT_DEFAULT]);
		
		m_Shot.push_back(shot);
		break;
	case SHOT_BEAM:
		break;
	case SHOT_MISSILE:
		break;
	}
}
