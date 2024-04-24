#include "player.h"
#include "math.h"
#include "../Nishiyama/Input/Input.h"

void Player::Init() {
	//�������񉼒u�������[�h
	handle[0] = LoadGraph("Data/Image/Caucasus_front.png");
	pos={ 640,100,0 };
	radian = 90 * 3.1415926535 / 180;
	speed = 5.0f;
}

void Player::Step() {

	//�J�u�g���V�̍��ړ�
	if (Input::IsKeyKeep(KEY_INPUT_A)|| Input::IsKeyKeep(KEY_INPUT_LEFT)) {
		radian += 0.1;
		if (radian >= 170 * 3.1415926535 / 180) {
			radian = 170 * 3.1415926535 / 180;
		}
	}//�J�u�g���V�̉E�ړ�
	else if (Input::IsKeyKeep(KEY_INPUT_D) || Input::IsKeyKeep(KEY_INPUT_RIGHT)) {
		radian -= 0.1;
		if (radian <= 10 * 3.1415926535 / 180) {
			radian = 10 * 3.1415926535 / 180;
		}

	}
	else {//�{�^����������Ă��Ȃ��Ƃ��p�x��^���ɖ߂�
		if (radian > 90 * 3.1415926535 / 180) {
			radian -= 0.1;
			if (radian < 90 * 3.1415926535 / 180) {
				radian = 90 * 3.1415926535 / 180;
			}
		}
		if(radian <  90 * 3.1415926535 / 180){
			radian += 0.1;
			if (radian > 90 * 3.1415926535 / 180) {
				radian = 90 * 3.1415926535 / 180;
			}
		}
	}

	//x�ړ�
	pos.x=pos.x + speed * cos(radian);
}

void Player::Draw() {

	DrawRotaGraph(pos.x, pos.y, 1.0, radian, handle[0], true);

}