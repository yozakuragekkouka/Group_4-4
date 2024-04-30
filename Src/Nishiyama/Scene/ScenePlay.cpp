#include <math.h>

#include "DxLib.h"
#include "../../Common.h"
#include "../Input/Input.h"
#include "ScenePlay.h"
#include "../Score/Score.h"

//�v���C�V�[��������
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

//�v���C�V�[���ʏ폈��
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

//�v���C�V�[���`�揈��
void ScenePlay::Draw()
{
	back.Draw();
	player.Draw();

	block.Draw();
	back.Wall_Draw();

	ScoreNumber.Draw_int(Score::GetScore());
}

//�v���C�V�[���㏈��
//���g���C���ǂ�����Ԃ�
void ScenePlay::Fin()
{
	back.Fin();
	block.Fin();

	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_RESULT;
}
