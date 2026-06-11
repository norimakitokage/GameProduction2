#include "Sky.h"

// “V‹…‚Ì‘å‚«‚³
const VECTOR SKY_SIZE = VGet(90.0f, 90.0f, 90.0f);

void CSky::Load()
{
	LoadModel("Data/Landform/Sky/sky.mv1");
	SetScale(SKY_SIZE);
	Update();
}
