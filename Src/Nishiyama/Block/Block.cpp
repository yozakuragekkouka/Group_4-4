#include "Block.h"
#include "../../Common.h"

Block::Block()
{
	memset(&pos, 0, sizeof(VECTOR));
	memset(&size, 0, sizeof(VECTOR));
	isClear = false;
}

void Block::Init()
{
	pos.x = (float)(GetRand(SCREEN_SIZE_X - 16 - BLOCK_SIZE_MIN_X / 2) + 16 + BLOCK_SIZE_MIN_X / 2);
	pos.y = (float)(SCREEN_SIZE_Y + 200);

	size.x = (float)(GetRand(BLOCK_SIZE_MAX_X - BLOCK_SIZE_MIN_X) + BLOCK_SIZE_MIN_X);
	size.y = (float)BLOCK_SIZE_Y;
}

void Block::Step(float CurrentSpeed)
{
	pos.y -= CurrentSpeed;
}

void Block::Fin()
{
	return;
}
