#include "../Nishiyama/Shapes/Shapes.h"


class Player : public Circle {
private:
	int handle[3];//�摜�n���h��
	float radian;//���̌���
	float speed;//���̉��ړ����x

public:

	void Init();

	void Step();

	void Draw();

	float GetRadian(){ return radian; }
};