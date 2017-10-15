#include"Player.h"
#include"DxLib.h"
#include"Value.h"

int P_run_1;
int P_run_2;
int P_run_3;
int P_run_4;
int P_run_5;
int P_run_6;


int Player::Initialize() {

	P_run_1 = LoadGraph("images/Player/run/1.png");
	P_run_2 = LoadGraph("images/Player/run/2.png");
	P_run_3 = LoadGraph("images/Player/run/3.png");
	P_run_4 = LoadGraph("images/Player/run/4.png");
	P_run_5 = LoadGraph("images/Player/run/5.png");
	P_run_6 = LoadGraph("images/Player/run/6.png");

	center.Set(0);
	weekArea.Set(center, center);
	attack = 0;
	Image = P_run_1;
	acceptFlag = 1;

	return 0;
}

int Player::Set() {
	center.Set(500, 500);
	
	return 0;
}

int Player::SetRun() {
	stateFlag = 1;
	Image = P_run_1;

	return 0;
}
int Player::UpdataRun(int count) {
	center.Set(center.Get_x() + 0);
	DrawFormatString(300, 200, WHITE, "count:%d", count);
	if (count % 60 <= 10) {
		Image = P_run_1;
	}else if (count % 60 <= 20) {
		Image = P_run_2;
	}
	else if (count % 60 <= 30) {
		Image = P_run_3;
	}
	else if (count % 60 <= 40) {
		Image = P_run_4;
	}
	else if (count % 60 <= 50) {
		Image = P_run_5;
	}
	else if (count % 60 <= 60) {
		Image = P_run_6;
	}
	return 0;
}

int Player::SetStand() {
	stateFlag = 0;
	Image = P_run_2;

	return 0;
}

int Player::UpdataStand(int count) {
	center.Set(center.Get_x() - 2);
	return 0;
}

int Player::Updata(int count,int Key[]) {
	//UpdataRun(count);
	if (acceptFlag) {//入力受付時の処理
		if (A) {

		}
		else if (B) {

		}
		else if (RIGHT == 1) {
			bodyClock = count;
			SetRun();
			//UpdataRun(count - bodyClock);
		}
		else if (RIGHT > 1) {
			UpdataRun(count - bodyClock);
		}
		else  if(bodyClock != 0){
			UpdataStand(count);
		}
		else {
			bodyClock = count;
		}

	}
	else {//入力非受付時の処理
		switch (stateFlag)
		{
		case 0:
			break;
		case 1://ダッシュ
			//UpdataRun(count);
			break;
		default:
			break;
		}

	}


	
	return 0;
}

int Player::Draw() {

	DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GRAY, true);

	DrawModiGraph(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		Image,false);
	//DrawFormatString(0, 0, WHITE, "Drawing : %d",center.Get_x());

	

	return 0;
}