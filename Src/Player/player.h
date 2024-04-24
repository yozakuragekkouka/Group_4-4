#include "../Nishiyama/Shapes/Shapes.h"


class Player : public Circle {
private:
	int handle[3];
	float radian;
public:

	void Init();

	void Step();

	void Draw();

	float GetRadian(){ return radian; }
};