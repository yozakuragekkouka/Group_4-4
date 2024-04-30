#pragma once
#include "Scene.h"
#include "../NumberFont/NumberFont.h"

class SceneResult : public SceneBase
{
private:
	c_Number ScoreNumber;

public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};