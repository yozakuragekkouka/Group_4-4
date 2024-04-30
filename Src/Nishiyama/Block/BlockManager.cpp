#include <math.h>

#include "BlockManager.h"
#include "../../Common.h"
#include "../Score/Score.h"

BlockManager::BlockManager()
{
	for (int i = 0; i < 5; i++)
	{
		memset(&block[i], 0, sizeof(Block));
	}

	speed = 0.0f;
	Block_Image = -1;

	Debug_BoxColor = 0;
}

BlockManager::~BlockManager()
{
	if (Block_Image != -1)
		DeleteGraph(Block_Image);
}

void BlockManager::Init()
{
	for (int i = 0; i < 5; i++)
	{
		block[i].Init();
		block[i].Step(-200.0f * i);
	}

	speed = BLOCK_DEFAULT_SPEED;
	Block_Image = LoadGraph(BLOCK_PATH);

	Debug_BoxColor = GetColor(148, 0, 211);
}

void BlockManager::Step(float pl_radian)
{
	float pl_Speed = sinf(pl_radian);
	speed = (float)BLOCK_DEFAULT_SPEED * pl_Speed;

	for (int i = 0; i < 5; i++)
	{
		block[i].Step(speed);
		if (block[i].Get_pos().y < -100)
		{
			block[i].Init();
		}
	}
}

void BlockManager::Draw()
{
	for (int i = 0; i < 5; i++)
	{
		if (Block_Image != -1)
		{
			DrawExtendGraph((int)(block[i].Get_pos().x - block[i].Get_size().x / 2.0f),
				(int)(block[i].Get_pos().y - block[i].Get_size().y / 2.0f),
				(int)(block[i].Get_pos().x + block[i].Get_size().x / 2.0f),
				(int)(block[i].Get_pos().y + block[i].Get_size().y / 2.0f),
				Block_Image, true);
		}
		else
		{
			DrawBox((int)(block[i].Get_pos().x - block[i].Get_size().x / 2.0f),
				(int)(block[i].Get_pos().y - block[i].Get_size().y / 2.0f),
				(int)(block[i].Get_pos().x + block[i].Get_size().x / 2.0f),
				(int)(block[i].Get_pos().y + block[i].Get_size().y / 2.0f),
				Debug_BoxColor, true);
		}
		
	}
}

void BlockManager::Fin()
{
	if (Block_Image != -1)
		DeleteGraph(Block_Image);
	return;
}

bool BlockManager::isHit(VECTOR pl_pos)
{
	for (int i = 0; i < 5; i++)
	{
		if (pl_pos.x > block[i].Get_pos().x - block[i].Get_size().x / 2.0f &&
			pl_pos.x < block[i].Get_pos().x + block[i].Get_size().x / 2.0f &&
			pl_pos.y > block[i].Get_pos().y - block[i].Get_size().y / 2.0f &&
			pl_pos.y < block[i].Get_pos().y + block[i].Get_size().y / 2.0f)
		{
			return true;
		}
	}
	return false;
}

void BlockManager::isClear_box(VECTOR pl_pos)
{
	for (int i = 0; i < 5; i++)
	{
		if (block[i].Get_isClear())
			continue;

		if (block[i].Get_pos().y + block[i].Get_size().y / 2.0f < pl_pos.y)
		{
			Score::AddScore(1);
			block[i].Set_isClear(true);
		}
	}
}
