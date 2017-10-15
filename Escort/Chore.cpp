#include"Chore.h"
#include"DxLib.h"
#include"Value.h"

int Back::SetKumo(int a) {
	KumoImage = a;
	Kumo[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Kumo[1].Set(DISP_WIDTH, DISP_HEIGHT, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetFar(int a) {
	FarImge = a;
	Far[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Far[1].Set(DISP_WIDTH, DISP_HEIGHT, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetMiddle(int a) {
	MiddleImage = a;
	Middle[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Middle[1].Set(DISP_WIDTH, DISP_HEIGHT, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}
int Back::SetClose(int a) {
	CloseImage = a;
	Close[0].Set(0, 0, DISP_WIDTH, DISP_HEIGHT);
	Close[1].Set(DISP_WIDTH, DISP_HEIGHT, DISP_WIDTH * 2, DISP_HEIGHT);
	return 0;
}

int Back::Updata() {
	for (int i = 0; i < 2; i++) {
		Kumo[i].
	}
	return 0;
}

Back back;

int city_kumo;
int city_far;
int city_middle;
int city_close;

int ground_kumo;
int ground_far;
int ground_middle;
int ground_close;

int ChoreInitialize() {
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
		back.SetKumo(ground_kumo);
		back.SetFar(ground_far);
		back.SetMiddle(ground_middle);
		back.SetClose(ground_close);
		break;
	default:
		break;
	}
}

int UpdataBack(int count) {//countŽg‚í‚È‚­‚Ä‚à‚Å‚«‚é(?)
	back.Updata();
	return 0;
}