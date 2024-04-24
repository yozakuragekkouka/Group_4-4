#include "player.h"
#include "math.h"
#include "../Nishiyama/Input/Input.h"

void Player::Init() {
	//いったん仮置きをロード
	handle[0] = LoadGraph("Data/Image/kabuto.png");
	pos={ 640,100,0 };
	radian = 0;
}

void Player::Step() {

	//まだ途中、動きません。マジックナンバーあり
	if (Input::IsKeyKeep(KEY_INPUT_A)|| Input::IsKeyKeep(KEY_INPUT_LEFT)) {
		radian += 0.1;
	}
	else if (Input::IsKeyKeep(KEY_INPUT_D) || Input::IsKeyKeep(KEY_INPUT_RIGHT)) {
		radian -= 0.1;

	}
	else {
		if (radian < 0) {
			radian += 0.1;
		}
		else if(radian > 0){
			radian -= 0.1;
		}
	}
}

void Player::Draw() {

	DrawRotaGraph(pos.x, pos.y, 1.0, radian, handle[0], true);

}