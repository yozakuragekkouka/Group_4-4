#include <math.h>

#include "DxLib.h"
#include "BackGround.h"

BackGround::BackGround()
{
	speed = 0.0f;
	ResultBackCount = 0;
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		memset(&BG_Image[i], 0, sizeof(Rect_Data));
		memset(&wall_Image[i], 0, sizeof(Rect_Data));
	}
}

BackGround::~BackGround()
{

}

void BackGround::Init()
{
	speed = BACK_GROUND_DEFAULT_SPEED;
	ResultBackCount = 0;

	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		BG_Image[i].RectInit(LoadGraph(BACK_GROUND_PATH), VGet(0.0f, (float)BACK_GROUND_SIZEH * i, 0.0f), BACK_GROUND_SIZEW, BACK_GROUND_SIZEH);
		wall_Image[i].RectInit(LoadGraph(WALL_GROUND_PATH), BG_Image[i].Get_pos(), BACK_GROUND_SIZEW, BACK_GROUND_SIZEH);
	}
}

void BackGround::Step(float pl_radian)
{
	float pl_Speed = sinf(pl_radian);
	speed = (float)BACK_GROUND_DEFAULT_SPEED * pl_Speed;

	BG_Image[ResultBackCount].Move_Y(-speed);

	for (int i = ResultBackCount + 1; i != ResultBackCount; i++)
	{
		if (i == BACK_GROUND_NUM)
		{
			i = 0;
			if (ResultBackCount == 0)
				break;
		}
		if (i == 0)
		{
			BG_Image[i].Set_posY(BG_Image[BACK_GROUND_NUM - 1].Get_posY() + (float)BACK_GROUND_SIZEH);
		}
		else
		{
			BG_Image[i].Set_posY(BG_Image[i - 1].Get_posY() + (float)BACK_GROUND_SIZEH);
		}
	}
	if (-BACK_GROUND_OVER > BG_Image[ResultBackCount].Get_pos().y)
	{
		if (ResultBackCount == 0)
		{
			BG_Image[ResultBackCount].Set_posY(BG_Image[BACK_GROUND_NUM - 1].Get_posY() + (float)BACK_GROUND_SIZEH);
		}
		else
		{
			BG_Image[ResultBackCount].Set_posY(BG_Image[ResultBackCount - 1].Get_posY() + (float)BACK_GROUND_SIZEH);
		}
		ResultBackCount++;
		if (ResultBackCount >= BACK_GROUND_NUM)
		{
			ResultBackCount = 0;
		}
	}

	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		wall_Image[i].Set_pos(BG_Image[i].Get_pos());
	}
}

void BackGround::Draw()
{
	
	unsigned int color[BACK_GROUND_NUM] =
	{
		GetColor(255, 0, 0),
		GetColor(0, 255, 0),
		GetColor(0, 0, 255)
	};
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		//BG_Image[i].DrawRect();
		DrawBox((int)BG_Image[i].Get_pos().x, (int)BG_Image[i].Get_pos().y, (int)BG_Image[i].Get_pos().x + BACK_GROUND_SIZEW, (int)BG_Image[i].Get_pos().y + BACK_GROUND_SIZEH, color[i], true);
	}
}

void BackGround::Wall_Draw()
{
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		wall_Image[i].DrawRect();
	}
}

void BackGround::Fin()
{
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		BG_Image[i].RectFin();
		wall_Image[i].RectFin();
	}
}