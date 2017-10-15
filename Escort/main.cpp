#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Princess.h"
#include"Chore.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(2160, 1440, 32);
	//SetFontSize(40);
	{
	SetWindowSizeChangeEnableFlag(TRUE);
	SetWindowSizeExtendRate(0.8);
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
	InputInitialize(key);
	player.Initialize();
	//Princess.Initialize();
	//EnemyMngInitialize();
	ChoreInitialize();
	//InputFile("koryosai2017.txt");

	player.Set();
	SetBack(stageFlag);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		InputUpdata(input, key);
		//InputUpdata(key);
		player.Updata(count,key);
		UpdataBack(count);

		DrawBack();
		player.Draw();
		PrintInput(key);

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
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
	}


	//UpdataFile("koryosai2017.txt");
	DxLib_End();

	// ソフトの終了
	return 0;
}