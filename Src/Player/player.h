#include "../Nishiyama/Shapes/Shapes.h"


class Player : public Circle {
private:
	int handle[3];//‰æ‘œƒnƒ“ƒhƒ‹
	float radian;//’Ž‚ÌŒü‚«
	float speed;//’Ž‚Ì‰¡ˆÚ“®‘¬“x

public:

	void Init();

	void Step();

	void Draw();

	float GetRadian(){ return radian; }
};