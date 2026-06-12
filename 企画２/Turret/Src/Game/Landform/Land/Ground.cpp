#include "Ground.h"

const VECTOR GROUND_SIZE = { 0.1f,0.1f,0.1f };

void CGround::Load() {
	LoadModel("Data/Landform/Land/Ground.mv1");
	Update();
}