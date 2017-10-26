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
	/*SetWindowSizeChangeEnableFlag(TRUE);
	SetWindowSizeExtendRate(0.5);
	ChangeWindowMode(TRUE);*/
	}
	//SetBackgroundColor(34,145,253);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	//DrawFormatString(0,0,RED,"LOADING!!!\n");
	if (AddFontResourceEx("Font/nishiki-teki.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResourceExŽ¸”s\n");
	}
	int nishiki = CreateFontToHandle("Nishiki-teki", 40, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (nishiki == -1) {
		printfDx("CreateFontToHandleŽ¸”s\n");
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

	flag = 0;
	int right = 0;
	int left = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, "The brown quick fox", RED, nishiki);
		//DrawStringToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2 + 40, "123456789", RED, nishiki);

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		InputUpdata(input, Key);
		//InputUpdata(Key);

		/*player.Updata(count,key);
		girl.Updata(count);
		UpdataBack(count);

		EnemyMngJudge(&player, &girl, count);
		
		DrawBack();
		girl.Draw();
		player.Draw();
		DrawData(levelFlag);*/
		PrintInput(Key);

		switch (flag){
		case 0://OP
			UpdataBack(count);
			DrawOP(levelFlag);
			DrawData(levelFlag);
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
			EnemyMngInitialize();
			//ChoreSet(levelFlag);
			SetBack(stageFlag);
			flag = 2;
			break;
		case 2://playing
			EnemyMngSet(levelFlag, stageFlag, count,girl.GetCenter());
			player.Updata(count,Key);
			girl.Updata(count);
			UpdataBack(count);
			EnemyMngUpdata(count);

			EnemyMngJudge(&player, &girl, count);

			if (girl.GetHP() <= 0) {
				//UpdataFile("output.txt", 0, 0);
				flag = 3;
				SetLoser(count);
			}
			if (count >= 1*30*30) {
				//UpdataFile("output.txt", 0, 0);
				flag = 4;
				SetWinner(count);
			}

			DrawBack();
			EnemyMngDraw();
			girl.Draw();
			player.Draw();
			FpsTimeFanction();
			break;
		case 3://gameover
			DrawLoseBord();
			//PrincessMotion_lose();
			/*if (B == 1 && LoserUpdata(count)) {
				flag = 0;
			}*/
			if (B == 1) {
				flag = 0;
			}
			break;
		case 4://gameclear
			player.Updata(count, Key);
			girl.Updata(count);
			UpdataBack(count);

			DrawBack();
			girl.Draw();
			player.Draw();
			WinnerUpdata(count);
			if(B == 1)
				flag = 0;
			break;
		default:
			break;
		}

		count++;
		//DrawFormatString(DISP_WIDTH / 2, 40, RED, "%5d", count);
		DrawFormatStringToHandle(DISP_WIDTH / 2, 40, RED, nishiki, "%5d", count);
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
		
		ScreenFlip();
	}

	//UpdataFile("koryosai2017.txt", 0, 0);
	//UpdataFile("output.txt", 0, 0);
	DxLib_End();

	return 0;
}