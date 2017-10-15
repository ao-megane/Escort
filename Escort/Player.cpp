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
	center.Set(500, 1000);
	
	return 0;
}

int Player::SetStand() {
	stateFlag = 0;
	Image = P_run_2;
	return 0;
}

int Player::UpdataStand(int count) {
	center.Set(center.Get_x() - 1);
	return 0;
}


int Player::SetRun() {
	stateFlag = 1;
	Image = P_run_1;

	return 0;
}
int Player::UpdataRun(int count) {
	center.Set(center.Get_x() + 0);
	//DrawFormatString(300, 200, WHITE, "count:%d", count);
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

int Player::SetDash() {
	stateFlag = 2;
	Image = P_run_1;

	return 0;
}
int Player::UpdataDash(int count) {
	center.Set(center.Get_x() + 1);
	//DrawFormatString(300, 200, WHITE, "count:%d", count);
	if (count % 30 <= 5) {
		Image = P_run_1;
	}
	else if (count % 30 <= 10) {
		Image = P_run_2;
	}
	else if (count % 30 <= 15) {
		Image = P_run_3;
	}
	else if (count % 30 <= 20) {
		Image = P_run_4;
	}
	else if (count % 30 <= 25) {
		Image = P_run_5;
	}
	else if (count % 30 <= 30) {
		Image = P_run_6;
	}
	return 0;
}


int Player::Updata(int count,int Key[]) {
	//UpdataRun(count);
	if (acceptFlag) {//“ü—ÍŽó•tŽž‚Ìˆ—
		if (A) {

		}
		else if (B) {

		}
		else if (THUMB_X > 80) {
			if (stateFlag != 2)bodyClock = count;
			SetDash();
		}
		else if (THUMB_X > 0) {
			if(stateFlag != 1)bodyClock = count;
			SetRun();
		}
		else {
			if (stateFlag != 0)bodyClock = count;
			SetStand();
		}
	}
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock);
		break;
	case 1:
		UpdataRun(count - bodyClock);
		break;
	case 2:
		UpdataDash(count - bodyClock);
	default:
		break;
	}

	return 0;
}

int Player::Draw() {

	DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GREEN, false);

	DrawModiGraph(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		Image,true);
	//DrawFormatString(0, 0, WHITE, "Drawing : %d",center.Get_x());

	

	return 0;
}