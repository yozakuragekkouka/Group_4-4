#pragma once
#include "Scene.h"

//�V�[�����
class SceneTitle : public SceneBase
{
private:
	int handle[2];
	int alpha;
	bool alphaFlag;
public:
	void Init();

	void Step();

	void Draw();

	void Fin();
};