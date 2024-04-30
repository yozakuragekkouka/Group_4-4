#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//タイトル初期化
void SceneTitle::Init()
{
	handle[0] = LoadGraph("Data/Image/titleName.png");
	handle[1] = LoadGraph("Data/Image/titleUI.png");
	handle[2] = LoadGraph("Data/Image/Caucasus_front.png");
	y = 720;
	alpha=255;
	alphaFlag=false;
	moveFlag = false;
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void SceneTitle::Step()
{

	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		moveFlag = true;
		
	}
	if (moveFlag) {
		y -= 8;
		if (y <= -60) {
			SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
		}
	}
	if (alphaFlag) {
		alpha += 5;
		if (alpha >= 255) {
			alpha = 255;
			alphaFlag = false;
		}
	}
	if (!alphaFlag) {
		alpha -= 5;
		if (alpha <= 0) {
			alpha = 0;
			alphaFlag = true;
		}
	}
}

//タイトル描画処理
void SceneTitle::Draw()
{
	DrawBox(0, 0, 1280, 720, GetColor(200, 200, 100), true);
	DrawGraph(-10, y-600, handle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawGraph(0, y-650, handle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	DrawBox(0, 720, 1280, y, GetColor(255, 0, 0), true);
	DrawRotaGraph(640, 100,1.0,90*3.1415/180, handle[2], true);
	
}

//タイトル後処理
void SceneTitle::Fin()
{
	for (int index = 0; index < 3; index++) {
		DeleteGraph(handle[index]);
	}
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}