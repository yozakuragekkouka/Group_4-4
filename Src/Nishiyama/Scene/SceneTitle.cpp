#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//タイトル初期化
void SceneTitle::Init()
{
	handle[0] = LoadGraph("Data/Image/titleName.png");
	handle[1] = LoadGraph("Data/Image/titleUI.png");
	alpha=255;
	alphaFlag=false;
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void SceneTitle::Step()
{

	if (Input::IsKeyPush(KEY_INPUT_RETURN)) {
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_TITLE;
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
	DrawGraph(-10, 0, handle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawGraph(0, 50, handle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

//タイトル後処理
void SceneTitle::Fin()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}