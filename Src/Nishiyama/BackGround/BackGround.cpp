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
	for (int i = 0; i < BACK_GROUND_NUM; i++)
	{
		//BG_Image[i].RectInit();
	}
}