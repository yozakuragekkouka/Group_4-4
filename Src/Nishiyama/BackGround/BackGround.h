#pragma once
#include "../Shapes/Shapes.h"

constexpr int BACK_GROUND_NUM = 3;
constexpr int BACK_GROUND_SPEED = 3;

constexpr int BACK_GROUND_SIZEW = 1280;
constexpr int BACK_GROUND_SIZEH = 720;
constexpr int BACK_GROUND_OVER = BACK_GROUND_SPEED - (BACK_GROUND_SIZEW % BACK_GROUND_SPEED);

class BackGround
{
private:
	int ResultBackCount;
	Rect_Data BG_Image[BACK_GROUND_NUM];

public:
	BackGround();
	~BackGround();

	void Init();
	void Step();
	void Draw();
	void Fin();


};