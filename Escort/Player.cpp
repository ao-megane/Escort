#include"Player.h"
#include"DxLib.h"
#include"Value.h"

int P_run_1;
int P_run_2;
int P_run_3;
int P_run_4;
int P_run_5;
int P_run_6;

int P_walk_1;
int P_walk_2;


int Player::Initialize() {

	P_run_1 = LoadGraph("images/Player/run/1s.png");
	P_run_2 = LoadGraph("images/Player/run/2s.png");
	P_run_3 = LoadGraph("images/Player/run/3s.png");
	P_run_4 = LoadGraph("images/Player/run/4s.png");
	P_run_5 = LoadGraph("images/Player/run/5s.png");
	P_run_6 = LoadGraph("images/Player/run/6s.png");

	P_walk_1 = LoadGraph("images/Player/walk/1.png");
	P_walk_2 = LoadGraph("images/Player/walk/3.png");

	center.Set(0);
	weekArea.Set(center, center);
	attack = 0;
	Image = P_run_1;
	acceptFlag = 1;
	stateFlag = 0;

	return 0;
}

int Player::Set() {
	center.Set(500, 1000);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
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
	if (count % 20 <= 10) {
		Image = P_walk_1;
	}
	else if (count % 20 <= 20) {
		Image = P_walk_2;
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
	if (count % 18 <= 3) {
		Image = P_run_1;
	}
	else if (count % 18 <= 6) {
		Image = P_run_2;
	}
	else if (count % 18 <= 9) {
		Image = P_run_3;
	}
	else if (count % 18 <= 12) {
		Image = P_run_4;
	}
	else if (count % 18 <= 15) {
		Image = P_run_5;
	}
	else if (count % 18 <= 18) {
		Image = P_run_6;
	}
	return 0;
}


int Player::Updata(int count,int Key[]) {
	//UpdataRun(count);
	if (acceptFlag) {//“ü—ÍŽó•tŽž‚Ìˆ—
		if (A) {//‰“‹——£UŒ‚
			if (stateFlag != 7)bodyClock = count;
			//SetAttack_l();
		}
		else if (B) {//’áˆÐ—ÍL”ÍˆÍUŒ‚
			if (stateFlag != 6)bodyClock = count;
			//SetAttack_w();
		}
		else if (Y) {//‚ˆÐ—Í¬”ÍˆÍUŒ‚
			if (stateFlag != 5)bodyClock = count;
			//SetAttack_s();
		}
		else if (THUMB_Y > 80) {//ƒWƒƒƒ“ƒv
			if (stateFlag != 4)bodyClock = count;
			//SetJump();
		}
		else if (THUMB_Y < -80) {//ƒK[ƒh
			if (stateFlag != 3)bodyClock = count;
			//SetGuard();
		}
		else if (THUMB_X > 80) {//ƒ_ƒbƒVƒ…
			if (stateFlag != 2)bodyClock = count;
			SetDash();
		}
		else if (THUMB_X > 0) {//•à‚«
			if(stateFlag != 1)bodyClock = count;
			SetRun();
		}
		else {//—§‚¿
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
		break;
	case 3:
		//UpdataGuard(count - bodyClock);
		break;
	case 4:
		//UpdataJump(count - bodyClock);
		break;
	case 5:
		//UpdataAttack_s(count - bodyClock);
		break;
	case 6:
		//UpdataAttack_w(count - bodyClock);
		break;
	case 7:
		//UpdataAttack_l(count - bodyClock);
		break;
	default:
		break;
	}

	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	return 0;
}

int Player::Draw() {

	DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GREEN, false);
	DrawBox(
		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
		BLUE, false);

	DrawModiGraph(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		Image,true);
	DrawFormatString(0, 0, RED, "P_state : %d",stateFlag);

	

	return 0;
}