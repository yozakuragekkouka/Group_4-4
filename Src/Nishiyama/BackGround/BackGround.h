#pragma once
#include "../Shapes/Shapes.h"

constexpr int BACK_GROUND_NUM = 3;
constexpr int BACK_GROUND_SPEED = 3;

class BackGround
{
private:
	Rect_Data BG_Image[BACK_GROUND_NUM];

public:
	BackGround();
	~BackGround();

	void Init();
	void Step();
	void Draw();
	void Fin();


};