#pragma once
#include "Scene.h"
#include "../../Player/player.h"

class ScenePlay : public SceneBase
{
private:
	Player player;
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};