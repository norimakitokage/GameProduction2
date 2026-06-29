#include "Ground.h"

const VECTOR GROUND_SIZE = { 3.0f,3.0f,3.0f };

void CGround::Load() {
	LoadModel("Data/Landform/Land/Ground.mv1");
	CObject::SetScale(GROUND_SIZE);
	Update();
}