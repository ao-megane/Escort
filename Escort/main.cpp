#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"Princess.h"
#include"EnemyMng.h"
#include"Chore.h"
#include"Value.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(2160, 1440, 32);
	
	
	{
	/*SetWindowSizeChangeEnableFlag(TRUE);
	SetWindowSizeExtendRate(0.6);
	ChangeWindowMode(TRUE);*/
	}
	//SetBackgroundColor(34,145,253);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	//DrawFormatString(0,0,RED,"LOADING!!!\n");
	
	//printfDx("succes\n");

	XINPUT_STATE input;

	int Key[10] = { 0 };

	int flag = 0;
	int levelFlag = 0;
	//int stageFlag = 1; //0 1 2
	int count = 0;
	int keep_count = 0;
	Player player;
	Princess girl;
	InputInitialize(Key);
	player.Initialize();
	girl.Initialize();
	EnemyMngInitialize();
	SystemInitialize();
	InputFile("koryosai2017.txt");

	//player.Set();
	//girl.Set();
	SetBack(1);

	flag = 0;
	int down = 0;
	int up = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, Key);
		InputUpdata(Key);
		//PrintInput(Key);

		UpdataBack(count);
		DrawBack();
		
		switch (flag){
		case 0://OP
			/*UpdataBack(count);
			DrawBack();*/
			DrawOP(levelFlag);
			DrawData(levelFlag);
			if (THUMB_Y >= 80) down++; else down = 0;
			if (THUMB_Y <= -80) up++; else up = 0;

			if(down == 1){
				if (levelFlag == 3) levelFlag = 0;
				else levelFlag++;
			}
			if(up == 1){
				if (levelFlag == 0) levelFlag = 3;
				else levelFlag--;
			}
			if (B == 1) {
				switch (levelFlag)
				{
				case 0: 
				case 1:flag = 1;
					break;
				case 2:flag = 5;
					break;
				case 3:flag = 6;
					break;
				default:
					break;
				}
			}
			break;
		case 1://Loading
			count = 0;
			player.Set(levelFlag);
			girl.Set(levelFlag);
			EnemyMngInitialize();
			//ChoreSet(levelFlag);
			//SetBack(stageFlag);
			flag = 2;
			break;
		case 2://playing
			EnemyMngSet(levelFlag, count, girl.GetCenter());
			player.Updata(count,Key);
			girl.Updata(count);
			//UpdataBack(count);
			EnemyMngUpdata(count);

			EnemyMngJudge(&player, &girl, count);

			if (girl.GetHP() <= 0) {
				//UpdataFile("output.txt", 0, 0);
				flag = 3;
				SetLoser(levelFlag,count);
			}
			if (count >= 1*5*30) {
				//UpdataFile("output.txt", 0, 0);
				flag = 4;
				SetWinner(levelFlag,count);
			}

			//DrawBack();
			EnemyMngDraw();
			girl.Draw();
			player.Draw();
			FpsTimeFanction();
			break;
		case 3://gameover
			DrawLoseBord(count);
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
			//UpdataBack(count);

			//DrawBack();
			girl.Draw();
			player.Draw();
			WinnerUpdata(count);
			if(B == 1)
				flag = 0;
			break;
		case 5://マニュアル
			DrawManual();
			if(B==1) flag = 0;
			break;
		case 6://クレジット
			DrawCredit();
			if(B==1) flag = 0;
		default:
			break;
		}

		count++;
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
		
		ScreenFlip();
	}

	UpdataFile("koryosai2017.txt", 0, 0);
	//UpdataFile("output.txt", 0, 0);
	DxLib_End();

	return 0;
}