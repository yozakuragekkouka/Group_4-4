#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "SceneResult.h"
#include "../Score/Score.h"

//クリア初期化
void SceneResult::Init()
{
	ScoreNumber.Init();
	ScoreNumber.SetNumberFont(Number_16_32_blue);
	ScoreNumber.Set_posX(SCREEN_SIZE_X / 2 - 30);
	ScoreNumber.Set_posY(SCREEN_SIZE_Y / 2 - 10);

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_RESULT;
}

//クリア通常処理
void SceneResult::Step()
{
	if (Input::PressAnyKey())
	{
		SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_FIN_RESULT;
	}
}

//クリア描画処理
void SceneResult::Draw()
{
	ScoreNumber.Draw_int(Score::GetScore());
}

//クリア後処理
void SceneResult::Fin()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_TITLE;
}
