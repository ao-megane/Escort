#include"Chore.h"
#include"DxLib.h"
#include"Value.h"
#include<fstream>
#include<string>
#include<iostream>
#include<sstream>
#include<list>

int Back::SetColor(int a) {
	ColorImage = a;
	Color[0].Set(0, 0, DISP_WIDTH*2, DISP_HEIGHT);
	//Color[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetKumo(int a) {
	KumoImage = a;
	Kumo[0].Set(0, 0, DISP_WIDTH*2, DISP_HEIGHT);
	Kumo[1].Set(DISP_WIDTH*2, 0, DISP_WIDTH * 4, DISP_HEIGHT);
	return 0;
}
int Back::SetFar(int a) {
	FarImage = a;
	Far[0].Set(0, 0, DISP_WIDTH*2, DISP_HEIGHT);
	Far[1].Set(DISP_WIDTH*2, 0, DISP_WIDTH * 4, DISP_HEIGHT);
	return 0;
}/*
int Back::SetMiddle(int a) {
	MiddleImage = a;
	Middle[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Middle[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}*/
int Back::SetClose(int a) {
	CloseImage = a;
	Close[0].Set(0, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	Close[1].Set(DISP_WIDTH * 2, 0, DISP_WIDTH * 4, DISP_HEIGHT);
	return 0;
}

int Back::Updata(int count) {
	if (count % 2 == 0) {
		for (int i = 0; i < 2; i++) {
			Kumo[i] - 1;
			Far[i] - 2;
			//Middle[i] - 3;
			Close[i] - 4;
		}
	}
	/*if (Color[0].Get_RD().Get_x() == 0) {
		Color[0] - (-DISP_WIDTH);
		Color[1] - (-DISP_WIDTH);
	}*/
	if (Kumo[0].Get_RD().Get_x() == DISP_WIDTH) {
		Kumo[0] - (-DISP_WIDTH * 1);
		Kumo[1] - (-DISP_WIDTH * 1);
	}
	if (Far[0].Get_RD().Get_x() == DISP_WIDTH) {
		Far[0] - (-DISP_WIDTH * 1);
		Far[1] - (-DISP_WIDTH * 1);
	}
	/*if (Middle[0].Get_RD().Get_x() == 0) {
		Middle[0] - (-DISP_WIDTH);
		Middle[1] - (-DISP_WIDTH);
	}*/
	if (Close[0].Get_RD().Get_x() == DISP_WIDTH) {
		Close[0] - (-DISP_WIDTH * 1);
		Close[1] - (-DISP_WIDTH * 1);
	}
	return 0;
}
int Back::Draw() {
	for (int i = 0; i < 2; i++) 
		DrawModiGraph(
			Color[i].Get_LU().Get_x(), Color[i].Get_LU().Get_y(),
			Color[i].Get_RD().Get_x(), Color[i].Get_LU().Get_y(),
			Color[i].Get_RD().Get_x(), Color[i].Get_RD().Get_y(),
			Color[i].Get_LU().Get_x(), Color[i].Get_RD().Get_y(),
			ColorImage, true
		);
	for (int i = 0; i < 2; i++) 
		DrawModiGraph(
			Kumo[i].Get_LU().Get_x(), Kumo[i].Get_LU().Get_y(),
			Kumo[i].Get_RD().Get_x(), Kumo[i].Get_LU().Get_y(),
			Kumo[i].Get_RD().Get_x(), Kumo[i].Get_RD().Get_y(),
			Kumo[i].Get_LU().Get_x(), Kumo[i].Get_RD().Get_y(),
			KumoImage, true
		);
	for (int i = 0; i < 2; i++)
		DrawModiGraph(
			Far[i].Get_LU().Get_x(), Far[i].Get_LU().Get_y(),
			Far[i].Get_RD().Get_x(), Far[i].Get_LU().Get_y(),
			Far[i].Get_RD().Get_x(), Far[i].Get_RD().Get_y(),
			Far[i].Get_LU().Get_x(), Far[i].Get_RD().Get_y(),
			FarImage, true
		);
	/*for (int i = 0; i < 2; i++)
		DrawModiGraph(
			Middle[i].Get_LU().Get_x(), Middle[i].Get_LU().Get_y(),
			Middle[i].Get_RD().Get_x(), Middle[i].Get_LU().Get_y(),
			Middle[i].Get_RD().Get_x(), Middle[i].Get_RD().Get_y(),
			Middle[i].Get_LU().Get_x(), Middle[i].Get_RD().Get_y(),
			MiddleImage, true
		);*/
	for (int i = 0; i < 2; i++)
		DrawModiGraph(
			Close[i].Get_LU().Get_x(), Close[i].Get_LU().Get_y() + 450,
			Close[i].Get_RD().Get_x(), Close[i].Get_LU().Get_y() + 450,
			Close[i].Get_RD().Get_x(), Close[i].Get_RD().Get_y() + 0,
			Close[i].Get_LU().Get_x(), Close[i].Get_RD().Get_y() + 0,
			CloseImage, true
		);
	return 0;
}

Back back;

int city_kumo;
int city_far;
int city_middle;
int city_close;

int ground_color;
int ground_kumo;
int ground_far;
int ground_middle;
int ground_close;

int Clear1;
int Flower;
int GameOver;
int Loading1;
int Credit;
int Result;
int Tytle;
int Allow;
int Logo;

int nishiki;
int SystemInitialize() {

	Clear1 = LoadGraph("images/System/Clear1.png");
	Flower = LoadGraph("images/System/Flower.png");
	GameOver = LoadGraph("images/System/GameOver.png");
	Loading1 = LoadGraph("images/System/Loading.png");
	Result = LoadGraph("images/System/Result.png");
	Credit = LoadGraph("images/System/Credit.png");
	Tytle = LoadGraph("images/System/Tytle.png");
	Logo = LoadGraph("images/System/Logo.png");
	Allow = LoadGraph("images/System/Allow.png");
	Flower = LoadGraph("images/System/Flower.png");
	Credit = LoadGraph("images/System/Credit.png");

	ground_color = LoadGraph("images/Back/Color.png");
	ground_kumo = LoadGraph("images/Back/kumo.png");
	ground_far = LoadGraph("images/Back/Far.png");
	ground_middle = LoadGraph("images/Back/Middle.png");
	ground_close = LoadGraph("images/Back/Close.png");

	if (AddFontResourceEx("Font/nishiki-teki.ttf", FR_PRIVATE, NULL) == 0) {
		printfDx("AddFontResourceEx失敗\n");
	}
	nishiki = CreateFontToHandle("Nishiki-teki", 60, -1, DX_FONTTYPE_ANTIALIASING_8X8);
	if (nishiki == -1) {
		printfDx("CreateFontToHandle失敗\n");
	}

	return 0;
}

int DrawOP(int levelFlag) {
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Tytle, true);
	DrawModiGraph(
		DISP_WIDTH / 2 + 185	  , DISP_HEIGHT / 2 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 200 + 185, DISP_HEIGHT / 2 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 200 + 185, DISP_HEIGHT / 2 + 200 + 170 + (levelFlag) * 110,
		DISP_WIDTH / 2 + 185	  , DISP_HEIGHT / 2 + 200 + 170 + (levelFlag) * 110,
		Allow, true);
	return 0;
}

int DrawManual() {
	DrawFormatStringFToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, RED, nishiki, "MANUAL!");
	return 0;
}
int DrawCredit() {
	DrawFormatStringFToHandle(DISP_WIDTH / 2, DISP_HEIGHT / 2, RED, nishiki, "CREDIT!");
	return 0;
}

int SetBack(int stage) {
	switch (stage)
	{
	case 0://City
		break;
	case 1://Ground
		back.SetColor(ground_color);
		back.SetKumo(ground_kumo);
		back.SetFar(ground_far);
		//back.SetMiddle(ground_middle);
		back.SetClose(ground_close);
		break;
	default:
		break;
	}
	return 0;
}

int UpdataBack(int count) {//count使わなくてもできる(?)
	back.Updata(count);
	return 0;
}

int DrawBack() {
	back.Draw();
	return 0;
}

/*---------------------------------------------------------------------------*/

int numOfPlayers;
int easyHighScore;
int easyAvgScore;
int hardHighScore;
int hardAvgScore;

int InputFile(std::string file) {
	std::ifstream File(file);
	std::string j;
	int i;

	getline(File, j, '\n');
	i = atoi(j.c_str());
	numOfPlayers = i;

	getline(File, j, '\n');
	i = atoi(j.c_str());
	easyHighScore = i;

	getline(File, j, '\n');
	i = atoi(j.c_str());
	easyAvgScore = i;

	//remove(file);
	//DeleteFile(file);
	rename(file.c_str(), "koryosai2018");

	return 0;
}

int DrawData(int levelFlag) {
	if (levelFlag == 0) {
		DrawFormatStringToHandle(DISP_WIDTH / 2 - 500, 50, BROWN, nishiki, "プレイ人数:%3d", numOfPlayers);
		DrawFormatStringToHandle(DISP_WIDTH / 2 + 0, 50, BROWN, nishiki, "クリア率:%5.2f", easyHighScore);
		DrawFormatStringToHandle(DISP_WIDTH / 2 + 500, 50, BROWN, nishiki, "ハイスコア:%5d", easyHighScore);
	}
	else if (levelFlag == 1) {

	}
	return 0;
}

int UpdataFile(std::string file, int stageFlag, int score) {
	std::ofstream fout(file, std::ios::app);
	fout << ++numOfPlayers << "\n" << stageFlag << "\n" << score << "\n";
	//DrawFormatString(0, 120, RED, "%d", numOfPlayers);

	return 0;
}

int Keeper;
int flag;
int DrawLoseBord(int count) {
	if ((count - Keeper) <= 30) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper) / 30 * 255);		//ブレンドモードを設定
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	else if (count >= 30) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, GameOver, true);
	}
	return 0;
}
int DrawWinBord(int count) {
	if ((count - Keeper) <= 60) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (count - Keeper) / 60.0 * 255.0);		//ブレンドモードを設定
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Clear1, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ
	}
	else if (count >= 60) {
		DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, Clear1, true);
	}
	return 0;
}

int SetWinner(int count) {
	Keeper = count;
	flag = 1;
	return 0;
}
int SetLoser(int count) {
	Keeper = count;
	flag = 1;
	return 0;
}
int WinnerUpdata(int count) {
	DrawModiGraph(
		DISP_WIDTH - (count - Keeper) * 4, 300,
		DISP_WIDTH + 700 - (count - Keeper) * 4, 300,
		DISP_WIDTH + 700 - (count - Keeper) * 4, 700 + 300,
		DISP_WIDTH - (count - Keeper) * 4, 700 + 300,
		Credit, true);
	DrawModiGraph(
		DISP_WIDTH * 3/2 - (count - Keeper) * 4, GROUND_HEIGHT - 125,
		DISP_WIDTH * 3/2 + 750 - (count - Keeper) * 4, GROUND_HEIGHT - 125,
		DISP_WIDTH * 3/2 + 750 - (count - Keeper) * 4, GROUND_HEIGHT + 125,
		DISP_WIDTH * 3/2 - (count - Keeper) * 4, GROUND_HEIGHT + 125,
		Flower, true);
	if ((DISP_WIDTH * 3/2 + 750 - (count - Keeper) * 4 + 300) < DISP_WIDTH / 2 && flag) {
		Keeper = count;
		flag = 0;
		return 1;
	}
	else if (!flag) {
		DrawWinBord(count);
		return 1;
	}
	else return 0;
}

/*----------------------------------------------------------------------------------------------*/

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.0;
char Key[256];
void FpsTimeFanction() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 49) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント
	if (Fps != 0)
		DrawFormatString(DISP_WIDTH-200, DISP_HEIGHT-40, WHITE, "FPS %.1f", Fps); //fpsを表示
	return;
}