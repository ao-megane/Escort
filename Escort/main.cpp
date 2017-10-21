#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Princess.h"
#include"EnemyMng.h"
#include"Chore.h"
#include"Value.h"
//#include<Windows.h>

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

	//printfDx("try\n");
	if (AddFontResourceEx("Font/nishiki-teki.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResourceExé∏îs\n");
	}
	int nishiki = CreateFontToHandle("Nishiki-teki", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (nishiki == -1) {
		printfDx("CreateFontToHandleé∏îs\n");
	}
	//printfDx("succes\n");

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

	//player.Set();
	//girl.Set();
	SetBack(stageFlag);

	flag = 1;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, "The brown quick fox", RED, nishiki);
		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2 + 40, "123456789", RED, nishiki);

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, key);
		InputUpdata(key);

		/*player.Updata(count,key);
		girl.Updata(count);
		UpdataBack(count);

		EnemyMngJudge(&player, &girl, count);
		
		DrawBack();
		girl.Draw();
		player.Draw();
		DrawData(levelFlag);*/
		//PrintInput(key);

		switch (flag){
		case 0://OP
			/*DrawOP();
			if () {
				if ();
				levelFlag = ;
			}
			if () {
				if ();
				levelFlag = ;
			}*/
			break;
		case 1://Loading
			player.Set(levelFlag);
			girl.Set(levelFlag);
			EnemyMngSet(levelFlag,stageFlag,count);
			//ChoreSet(levelFlag);
			SetBack(stageFlag);
			count = 0;
			flag = 2;
			break;
		case 2://playing
			player.Updata(count,key);
			girl.Updata(count);
			UpdataBack(count);
			//EnemyMngUpdata(count);

			EnemyMngJudge(&player, &girl, count);

			if (girl.GetHP() <= 0) {
				UpdataFile("output.txt", 0, 0);
				flag = 3;
			}
			if (count >= 5*60*30) {
				UpdataFile("output.txt", 0, 0);
				flag = 4;
			}

			DrawBack();
			//EnemyMngDraw();
			girl.Draw();
			player.Draw();
			break;
		case 3://gameover
			/*PrincessMotion_lose();
			DrawLoseBord();
			if () {
				flag = 0;
			}*/
			break;
		case 4://gameclear
			/*DrawWinBord(level_flag);
			if () {
				flag = 0;
			}*/
			break;
		default:
			break;
		}

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