#pragma once
#include "Scene.h"
#include "../../Player/player.h"
#include "../BackGround/BackGround.h"
#include "../Block/BlockManager.h"
#include "../NumberFont/NumberFont.h"

class ScenePlay : public SceneBase
{
private:
	Player player;
	BackGround back;
	BlockManager block;
	c_Number ScoreNumber;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};