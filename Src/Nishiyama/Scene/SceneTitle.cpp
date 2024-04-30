#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../Input/Input.h"

//�^�C�g��������
void SceneTitle::Init()
{
	handle[0] = LoadGraph("Data/Image/titleName.png");
	handle[1] = LoadGraph("Data/Image/titleUI.png");
	alpha=255;
	alphaFlag=false;
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_LOOP_TITLE;
}

//�^�C�g���ʏ폈��
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

//�^�C�g���`�揈��
void SceneTitle::Draw()
{
	DrawGraph(-10, 0, handle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawGraph(0, 50, handle[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
}

//�^�C�g���㏈��
void SceneTitle::Fin()
{
	SceneManager::g_CurrenySceneID = SCENEID::SCENE_ID_INIT_PLAY;
}