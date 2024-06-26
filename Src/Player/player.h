#include "../Nishiyama/Shapes/Shapes.h"


class Player : public Circle {
private:
	int handle[3];//画像ハンドル
	float radian;//虫の向き
	float speed;//虫の横移動速度

public:
	~Player();

	void Init();

	void Step();

	void Draw();

	float GetRadian(){ return radian; }
};