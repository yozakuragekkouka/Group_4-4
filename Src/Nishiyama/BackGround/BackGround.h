#pragma once
#include "../Shapes/Shapes.h"

constexpr int BACK_GROUND_NUM = 3;
constexpr int BACK_GROUND_DEFAULT_SPEED = 10;

constexpr int BACK_GROUND_SIZEW = 1280;
constexpr int BACK_GROUND_SIZEH = 720;
constexpr int BACK_GROUND_OVER = 30 + BACK_GROUND_SIZEH;

constexpr char BACK_GROUND_PATH[128] = "";

class BackGround
{
private:
	float speed;
	int ResultBackCount;
	Rect_Data BG_Image[BACK_GROUND_NUM];

public:
	BackGround();
	~BackGround();

	void Init();
	void Step(float pl_radian);
	void Draw();
	void Fin();

	void SetSpeed(float New_Speed) { speed = New_Speed; }
};