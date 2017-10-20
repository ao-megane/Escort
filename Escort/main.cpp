#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Princess.h"
#include"EnemyMng.h"
#include"Chore.h"
#include"Value.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(2160, 1440, 32);
	SetFontSize(40);
	{
	SetWindowSizeChangeEnableFlag(TRUE);
	SetWindowSizeExtendRate(0.5);
	ChangeWindowMode(TRUE);
	}
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	XINPUT_STATE input;

	int key[10] = { 0 };

	int flag = 0;
	int levelFlag = 0;
	int stageFlag = 1; //0 1 2
	int count = 0;
	int keep_count = 0;
	Player player;
	Princess girl;
	InputInitialize(key);
	player.Initialize();
	girl.Initialize();
	//EnemyMngInitialize();
	ChoreInitialize();
	InputFile("koryosai2017.txt");

	player.Set();
	girl.Set();
	SetBack(stageFlag);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, key);
		InputUpdata(key);

		player.Updata(count,key);
		girl.Updata(count);
		UpdataBack(count);

		EnemyMngJudge(&player, &girl, count);
		
		DrawBack();
		girl.Draw();
		player.Draw();
		//PrintInput(key);

		//switch (flag){
		//case 0://OP
		//	DrawOP();
		//	if () {
		//		if ();
		//		level_flag = ;
		//	}
		//	if () {
		//		if ();
		//		level_flag = ;
		//	}
		//	break;
		//case 1://Loading
		//	PlayerInitialize(level_flag);
		//	PrincessInitialize(level_flag);
		//	EnemyMngInitialize(level_flag);
		//	ChoreInitialize(level_flag);
		//	count = 0;
		//	break;
		//case 2://playing
		//	PlayerUpdata(count);
		//	EnemyMngUpdata(count);
		//	PrincessUpdata(count);
		//	ChoreUpdata(count);

		//	if (S_S_IsHit(Get_PriWeek(), Get_EnemyMng_Attack())) {

		//	}
		//	if (make) {
		//		Set_ChoreLoser(level_flag,Get_ChoreLoser(level_flag)++);
		//		flag = 3;
		//	}
		//	if (kati) {
		//		Set_ChoreWiner(level_flag,Get_ChoreWiner(level_flag)++);
		//		flag = 4;
		//	}

		//	DrawBackGround(count);
		//	EnemyMngDraw();
		//	PrincessDraw();
		//	PyaerDraw();
		//	break;
		//case 3://gameover
		//	PrincessMotion_lose();
		//	DrawLoseBord();
		//	if () {
		//		flag = 0;
		//	}
		//	break;
		//case 4://gameclear
		//	DrawWinBord(level_flag);
		//	if () {
		//		flag = 0;
		//	}
		//	break;
		//default:
		//	break;
		//}

		count++;
		DrawFormatString(DISP_WIDTH / 2, 0, RED, "%d", count / 30);
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
		
		ScreenFlip();
	}

	//UpdataFile("koryosai2017.txt", 0, 0);
	UpdataFile("output.txt", 0, 0);
	DxLib_End();

	return 0;
}