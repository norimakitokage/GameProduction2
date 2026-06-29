#include "HitCheck.h"
#include <vector>
#include "../../Lib/Collision/Collision.h"

using namespace std;

void CHitCheck::EnemyToDefaultShot(CShotMnager& shot, CEnemyManager& enemy)
{
	vector<CShotBase*> p_shot = shot.GetVector();
	vector<CEnemyBase*> p_enemy = enemy.GetVector();

	for (auto s : p_shot) {
		if (s->GetType() != tagShotType::SHOT_DEFAULT) continue;

		bool flag = false;
		for (auto e : p_enemy) {
			flag = CColl::SphereToSphere(e->GetCenterPos(), ENEMY_RADIUS, s->GetPosition(), DEFAULT_SHOT_RADIUS);
			if (flag) {
				s->SetActiveFlag(false);
				e->MinusHp(5);
			}
		}
	}
}

void CHitCheck::CoreToEnemy(CProtectCore& core, CEnemyManager& enemy)
{
	vector<CEnemyBase*> p_enemy = enemy.GetVector();
	for (auto e : p_enemy) {
		bool flag = false;
		flag = CColl::SphereToSphere(core.GetCenter(), CORE_RADIUS, e->GetCenterPos(), ENEMY_RADIUS);
		if (flag) {

		}
	}
	
}
