#include "player.h"
#include "math.h"
#include "../Nishiyama/Input/Input.h"

void Player::Init() {
	//いったん仮置きをロード
	handle[0] = LoadGraph("Data/Image/Caucasus_front.png");
	pos={ 640,100,0 };
	radian = 90 * 3.1415926535 / 180;
	speed = 5.0f;
}

void Player::Step() {

	//カブトムシの左移動
	if (Input::IsKeyKeep(KEY_INPUT_A)|| Input::IsKeyKeep(KEY_INPUT_LEFT)) {
		radian += 0.1;
		if (radian >= 170 * 3.1415926535 / 180) {
			radian = 170 * 3.1415926535 / 180;
		}
	}//カブトムシの右移動
	else if (Input::IsKeyKeep(KEY_INPUT_D) || Input::IsKeyKeep(KEY_INPUT_RIGHT)) {
		radian -= 0.1;
		if (radian <= 10 * 3.1415926535 / 180) {
			radian = 10 * 3.1415926535 / 180;
		}

	}
	else {//ボタンが押されていないとき角度を真下に戻す
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

	//x移動
	pos.x=pos.x + speed * cos(radian);
}

void Player::Draw() {

	DrawRotaGraph(pos.x, pos.y, 1.0, radian, handle[0], true);

}