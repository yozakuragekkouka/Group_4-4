#pragma once
#include "Scene.h"

//シーン情報
class SceneTitle : public SceneBase
{
private:
	int handle[3];
	int y;
	int alpha;
	bool alphaFlag;
	bool moveFlag;
public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};