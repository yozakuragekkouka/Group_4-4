#pragma once
#include "Block.h"

constexpr float BLOCK_DEFAULT_SPEED = 10.0f;

constexpr char BLOCK_PATH[128] = "";

class BlockManager
{
private:
	float speed;
	int Block_Image;
	Block block[5];

	unsigned int Debug_BoxColor;

public:
	BlockManager();
	~BlockManager();

	void Init();
	void Step(float pl_radian);
	void Draw();
	void Fin();

	bool isHit(VECTOR pl_pos);
	void isClear_box(VECTOR pl_pos);

	void SetSpeed(float New_Speed) { speed = New_Speed; }
};