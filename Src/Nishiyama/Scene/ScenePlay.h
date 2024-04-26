#pragma once
#include "Scene.h"
#include "../../Player/player.h"
#include "../BackGround/BackGround.h"

class ScenePlay : public SceneBase
{
private:
	Player player;
	BackGround back;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};