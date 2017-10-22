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
	SetWindowSizeExtendRate(0.8);
	ChangeWindowMode(TRUE);
	}
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	//printfDx("try\n");
	if (AddFontResourceEx("Font/nishiki-teki.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResourceEx���s\n");
	}
	int nishiki = CreateFontToHandle("Nishiki-teki", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (nishiki == -1) {
		printfDx("CreateFontToHandle���s\n");
	}
	//printfDx("succes\n");

	XINPUT_STATE input;

	int Key[10] = { 0 };

	int flag = 0;
	int levelFlag = 0;
	int stageFlag = 1; //0 1 2
	int count = 0;
	int keep_count = 0;
	Player player;
	Princess girl;
	InputInitialize(Key);
	player.Initialize();
	girl.Initialize();
	EnemyMngInitialize();
	ChoreInitialize();
	InputFile("koryosai2017.txt");

	//player.Set();
	//girl.Set();
	SetBack(stageFlag);

	flag = 1;
	int right = 0;
	int left = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, "The brown quick fox", RED, nishiki);
		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2 + 40, "123456789", RED, nishiki);

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, Key);
		InputUpdata(Key);

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
			DrawOP(levelFlag);
			if (THUMB_X >= 80) right++; else right = 0;
			if(right == 1){
				if (levelFlag == 1) levelFlag = 0;
				else levelFlag = 1;
			}
			if (THUMB_X <= -80) left++; else left = 0;
			if(left == 1){
				if (levelFlag == 0) levelFlag = 1;
				else levelFlag = 0;
			}
			if (B == 1)
				flag = 1;
			break;
		case 1://Loading
			count = 0;
			player.Set(levelFlag);
			girl.Set(levelFlag);
			//ChoreSet(levelFlag);
			SetBack(stageFlag);
			flag = 2;
			break;
		case 2://playing
			EnemyMngSet(levelFlag, stageFlag, count);
			player.Updata(count,Key);
			girl.Updata(count);
			UpdataBack(count);
			EnemyMngUpdata(count);

			EnemyMngJudge(&player, &girl, count);

			/*if (girl.GetHP() <= 80) {
				UpdataFile("output.txt", 0, 0);
				flag = 3;
			}
			if (count >= 0.1*60*30) {
				UpdataFile("output.txt", 0, 0);
				flag = 4;
			}*/

			DrawBack();
			EnemyMngDraw();
			girl.Draw();
			player.Draw();
			break;
		case 3://gameover
			//PrincessMotion_lose();
			DrawLoseBord();
			if (B == 1) {
				flag = 0;
			}
			break;
		case 4://gameclear
			DrawWinBord(levelFlag);
			if (B == 1) {
				flag = 0;
			}
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