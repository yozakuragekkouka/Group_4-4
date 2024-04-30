#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "ScenePlay.h"
#include "../Score/Score.h"

//プレイシーン初期化
void ScenePlay::Init()
{
	Score::Init();

	back.Init();
	player.Init();

	block.Init();

	ScoreNumber.Init();
	ScoreNumber.SetNumberFont(Number_16_32_blue);
	ScoreNumber.Set_posX(1000);
	ScoreNumber.Set_posY(600);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_PLAY;
}

//プレイシーン通常処理
void ScenePlay::Step()
{
	back.Step(player.GetRadian());
	player.Step();

	block.Step(player.GetRadian());
	block.isClear_box(player.Get_pos());

	if (block.isHit(player.Get_pos()))
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_PLAY;
	}
}

//プレイシーン描画処理
void ScenePlay::Draw()
{
	back.Draw();
	player.Draw();

	block.Draw();
	back.Wall_Draw();

	ScoreNumber.Draw_int(Score::GetScore());
}

//プレイシーン後処理
//リトライかどうかを返す
void ScenePlay::Fin()
{
	back.Fin();
	block.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
