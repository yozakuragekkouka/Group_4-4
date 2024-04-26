#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "ScenePlay.h"

//プレイシーン初期化
void ScenePlay::Init()
{
	back.Init();
	player.Init();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::Step()
{
	back.Step(player.GetRadian());
	player.Step();


	/*if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}*/
}

//プレイシーン描画処理
void ScenePlay::Draw()
{
	back.Draw();
	player.Draw();

}

//プレイシーン後処理
//リトライかどうかを返す
void ScenePlay::Fin()
{
	back.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
