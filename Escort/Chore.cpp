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
	Color[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Color[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetKumo(int a) {
	KumoImage = a;
	Kumo[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Kumo[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetFar(int a) {
	FarImage = a;
	Far[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Far[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetMiddle(int a) {
	MiddleImage = a;
	Middle[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Middle[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetClose(int a) {
	CloseImage = a;
	Close[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Close[1].Set(DISP_WIDTH, 0, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}

int Back::Updata(int count) {
	if (count % 2 == 0) {
		for (int i = 0; i < 2; i++) {
			Kumo[i] - 1;
			Far[i] - 2;
			Middle[i] - 3;
			Close[i] - 4;
		}
	}
	if (Color[0].Get_RD().Get_x() == 0) {
		Color[0] - (-DISP_WIDTH);
		Color[1] - (-DISP_WIDTH);
	}
	if (Kumo[0].Get_RD().Get_x() == 0) {
		Kumo[0] - (-DISP_WIDTH);
		Kumo[1] - (-DISP_WIDTH);
	}
	if (Far[0].Get_RD().Get_x() == 0) {
		Far[0] - (-DISP_WIDTH);
		Far[1] - (-DISP_WIDTH);
	}
	if (Middle[0].Get_RD().Get_x() == 0) {
		Middle[0] - (-DISP_WIDTH);
		Middle[1] - (-DISP_WIDTH);
	}
	if (Close[0].Get_RD().Get_x() == 0) {
		Close[0] - (-DISP_WIDTH);
		Close[1] - (-DISP_WIDTH);
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
	for (int i = 0; i < 2; i++)
		DrawModiGraph(
			Middle[i].Get_LU().Get_x(), Middle[i].Get_LU().Get_y(),
			Middle[i].Get_RD().Get_x(), Middle[i].Get_LU().Get_y(),
			Middle[i].Get_RD().Get_x(), Middle[i].Get_RD().Get_y(),
			Middle[i].Get_LU().Get_x(), Middle[i].Get_RD().Get_y(),
			MiddleImage, true
		);
	for (int i = 0; i < 2; i++)
		DrawModiGraph(
			Close[i].Get_LU().Get_x(), Close[i].Get_LU().Get_y(),
			Close[i].Get_RD().Get_x(), Close[i].Get_LU().Get_y(),
			Close[i].Get_RD().Get_x(), Close[i].Get_RD().Get_y(),
			Close[i].Get_LU().Get_x(), Close[i].Get_RD().Get_y(),
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

int ChoreInitialize() {
	ground_color = LoadGraph("images/Back/Color.png");
	ground_kumo = LoadGraph("images/Back/kumo.png");
	ground_far = LoadGraph("images/Back/Far.png");
	ground_middle = LoadGraph("images/Back/Middle.png");
	ground_close = LoadGraph("images/Back/Close.png");

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
		back.SetMiddle(ground_middle);
		back.SetClose(ground_close);
		break;
	default:
		break;
	}
	return 0;
}

int UpdataBack(int count) {//countŽg‚í‚È‚­‚Ä‚à‚Å‚«‚é(?)
	back.Updata(count);
	return 0;
}

int DrawBack() {
	back.Draw();
	return 0;
}

/*---------------------------------------------------------------------------*/

int numOfPlayers;

int InputFile(std::string file) {
	std::ifstream File(file);
	std::string j;
	int i;
	getline(File, j, '\n');
	i = atoi(j.c_str());
	numOfPlayers = i;
	//remove(file);
	//DeleteFile(file);
	rename(file.c_str(), "koryosai2018");

	return 0;
}

int UpdataFile(std::string file, int stageFlag, int score) {
	std::ofstream fout(file, std::ios::app);
	fout << ++numOfPlayers << "\n" << stageFlag << "\n" << score << "\n";
	//DrawFormatString(0, 120, RED, "%d", numOfPlayers);

	return 0;
}