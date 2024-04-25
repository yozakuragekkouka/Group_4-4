#include <math.h>

#include "DxLib.h"
#include "BackGround.h"

BackGround::BackGround()
{
	
}

BackGround::~BackGround()
{

}

void BackGround::Init()
{
	ResultBackCount = 0;

	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		//BG_Image[i].RectInit();
	}
}

void BackGround::Step()
{
	/*for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		BG_Image[i].Move_Y((float)-BACK_GROUND_SPEED);
		if (ResultBack[i].Get_pos().y <= -(RESULT_BACK_SIZEH + ((RESULT_BACK_OVER * ResultBackCount) % RESULT_BACK_SPEED)))
		{
			ResultBack[i].Set_posY((float)(RESULT_BACK_SIZEH * (RESULT_BACK_NUM - 1) + ((RESULT_BACK_OVER * ResultBackCount) % RESULT_BACK_SPEED)));

			ResultBackCount++;
			if (RESULT_BACK_OVER == (RESULT_BACK_OVER * ResultBackCount) % RESULT_BACK_SPEED)
			{
				ResultBackCount = 0;
			}
		}
	}*/
}