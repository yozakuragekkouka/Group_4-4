#pragma once
#include "DxLib.h"

constexpr int BLOCK_SIZE_MIN_X = 100;
constexpr int BLOCK_SIZE_MAX_X = 500;
constexpr int BLOCK_SIZE_Y = 100;

class Block
{
private:
	VECTOR pos;
	VECTOR size;
	bool isClear;

public:
	Block();

	VECTOR Get_pos() { return pos; }
	void Set_pos(VECTOR Newpos) { pos = Newpos; }
	VECTOR Get_size() { return size; }
	void Set_size(VECTOR Newsize) { size = Newsize; }
	bool Get_isClear() { return isClear; }
	void Set_isClear(bool NewisClear) { isClear = NewisClear; }

	void Init();
	void Step(float CurrentSpeed);
	void Fin();
};