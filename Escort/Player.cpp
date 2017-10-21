#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include<math.h>

//int P_run_1;
//int P_run_2;
//int P_run_3;
//int P_run_4;
//int P_run_5;
//int P_run_6;

int P_walk_1;
int P_walk_2;
int P_walk_3;

int backArm;
int backLeg;
int body;
int frontArm;
int frontLeg;
int head;


int Player::Initialize() {

	/*P_run_1 = LoadGraph("images/Player/run/1s.png");
	P_run_2 = LoadGraph("images/Player/run/2s.png");
	P_run_3 = LoadGraph("images/Player/run/3s.png");
	P_run_4 = LoadGraph("images/Player/run/4s.png");
	P_run_5 = LoadGraph("images/Player/run/5s.png");
	P_run_6 = LoadGraph("images/Player/run/6s.png");*/

	//P_walk_1 = LoadGraph("images/Player/walk/1.png");
	//P_walk_2 = LoadGraph("images/Player/walk/3.png");
	P_walk_1 = LoadGraph("images/Player/walk/a1.png");
	P_walk_2 = LoadGraph("images/Player/walk/a2.png");
	P_walk_3 = LoadGraph("images/Player/walk/a3.png");

	backArm = LoadGraph("images/Player/characterChip/backarm.png");
	backLeg = LoadGraph("images/Player/characterChip/backleg.png");
	body = LoadGraph("images/Player/characterChip/body.png");
	frontArm = LoadGraph("images/Player/characterChip/frontarm.png");
	frontLeg = LoadGraph("images/Player/characterChip/frontleg.png");
	head = LoadGraph("images/Player/characterChip/head.png");;

	center.Set(0);
	weekArea.Set(center, center);
	attack = 0;
	Image = P_walk_1;
	acceptFlag = 1;
	isRightFlag = 1;
	stateFlag = 0;

	return 0;
}

int Player::Set(int levelFlag) {
	//if(levelFlag = 1)
	center.Set(500, GROUND_HEIGHT - P_HEIGHT / 2);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	return 0;
}

int Player::SetStand() {
	stateFlag = 0;
	Image = P_walk_1;
	return 0;
}

int Player::UpdataStand(int count) {
	center.Set(center.Get_x() - 1);
	return 0;
}

int Player::SetWalk() {
	stateFlag = 1;
	Image = P_walk_1;
	return 0;
}
int Player::UpdataWalk(int count) {
	int speed = 1;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED);
	int sum = 40;	//一周のフレーム数
	int num = 4;	//一周の画像数
	if (count % sum <= sum / num * 1) {
		Image = P_walk_1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = P_walk_2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = P_walk_3;
	}
	else if (count % sum <= sum) {
		Image = P_walk_2;
	}
	return 0;
}

int Player::SetDash() {
	stateFlag = 2;
	Image = P_walk_1;
	return 0;
}
int Player::UpdataDash(int count) {
	int speed = 2;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED);
	////DrawFormatString(300, 200, WHITE, "count:%d", count);
	//int sum = 18;
	//int num = 6;
	//if (count % sum <= sum/num * 1) {
	//	Image = P_run_1;
	//}
	//else if (count % sum <= sum / num * 2) {
	//	Image = P_run_2;
	//}
	//else if (count % sum <= sum / num * 3) {
	//	Image = P_run_3;
	//}
	//else if (count % sum <= sum / num * 4) {
	//	Image = P_run_4;
	//}
	//else if (count % sum <= sum / num * 5) {
	//	Image = P_run_5;
	//}
	//else if (count % sum <= sum) {
	//	Image = P_run_6;
	//}
	int sum = 20;	//一周のフレーム数
	int num = 4;	//一周の画像数
	if (count % sum <= sum / num * 1) {
		Image = P_walk_1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = P_walk_2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = P_walk_3;
	}
	else if (count % sum <= sum) {
		Image = P_walk_2;
	}

	return 0;
}

int Player::SetJump() {
	stateFlag = 4;
	Image = P_walk_1;
	acceptFlag = 1;	//空中制動
	return 0;
}
int Player::UpdataJump(int count,int flag) {
	double height = DISP_HEIGHT * 0.5;//jumpの高さ
	double sum = 60.0;	//モーションにかかるフレーム数
	int num = 5;	//絵の枚数
	double a =  -sin((count / sum)*PI) * height;//ほしい山
	switch (flag)
	{
	case 0://右ダッシュ
		center.Set((center.Get_x()) - GROUND_SPEED + 2, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	case 1://右歩き
		center.Set((center.Get_x()) - GROUND_SPEED + 1, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break; 
	case 2://左ダッシュ
		center.Set((center.Get_x()) - GROUND_SPEED - 2, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	case 3://左歩き
		center.Set((center.Get_x()) - GROUND_SPEED - 1, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	case 4://立ち
		center.Set((center.Get_x()) - GROUND_SPEED + 0, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	default:
		break;
	}
	
	if (count >= sum) {
		stateFlag = 0;
		acceptFlag = 1;
		bodyClock = count;
	}
	return 0;
}

int Player::SetAttack_w() {
	stateFlag = 6;
	Image = P_walk_1;
	acceptFlag = 0;
	attack = 10;
	Dot LU,RD;
	if (isRightFlag) {
		LU.Set(center.Get_x(), center.Get_y() - P_HEIGHT / 2);
		RD.Set(center.Get_x() + P_WIDTH / 2, GROUND_HEIGHT);
	}
	else {
		LU.Set(center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2);
		RD.Set(center.Get_x(), GROUND_HEIGHT);
	}
	attackArea.Set(LU, RD);
	return 0;
}
int Player::UpdataAttack_w(int count) {
	if (count >= 10) {
		stateFlag = 0;
		acceptFlag = 1;
	}
	return 0;
}


int Player::Updata(int count,int Key[]) {
	//UpdataRun(count);
	int flag = 0;//空中制御用フラグ
	if (acceptFlag) {//入力受付時の処理
		//だぶりありみたいなのはupdataでやるのが無難か
		if (A) {//遠距離攻撃
			if (stateFlag != 7)bodyClock = count;
			//SetAttack_l();
		}
		else if (B) {//低威力広範囲攻撃
			if (stateFlag != 6)bodyClock = count;
			SetAttack_w();
		}
		else if (Y) {//高威力小範囲攻撃
			if (stateFlag != 5)bodyClock = count;
			//SetAttack_s();
		}
		else if (THUMB_Y <= -80) {//ジャンプ
			if (stateFlag != 4)bodyClock = count;
			SetJump();
		}
		else if (THUMB_Y >= 80) {//ガード
			if (stateFlag != 3)bodyClock = count;
			//SetGuard();
		}
		else if (THUMB_X > 80) {//右ダッシュ
			if (stateFlag != 2 && stateFlag != 4)bodyClock = count;
			flag = 0;
			isRightFlag = 1;
			if(stateFlag != 4)
				SetDash();
		}
		else if (THUMB_X > 0) {//右歩き
			if(stateFlag != 1 && stateFlag != 4)bodyClock = count;
			flag = 1;
			isRightFlag = 1;
			if(stateFlag != 4)
				SetWalk();
		}
		else if (THUMB_X < -80) {//左ダッシュ
			if (stateFlag != 2 && stateFlag != 4)bodyClock = count;
			flag = 2;
			isRightFlag = 0;
			if(stateFlag != 4)
				SetDash();
		}
		else if (THUMB_X < 0) {//左歩き
			if (stateFlag != 1 && stateFlag != 4)bodyClock = count;
			flag = 3;
			isRightFlag = 0;
			if(stateFlag != 4)
				SetWalk();
		}
		else if(abs(THUMB_Y) == 0 && abs(THUMB_X) == 0){//立ち
			if (stateFlag != 0 && stateFlag != 4)bodyClock = count;
			flag = 4;
			if(stateFlag != 4)
				SetStand();
		}
	}

	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock);
		break;
	case 1:
		UpdataWalk(count - bodyClock);
		break;
	case 2:
		UpdataDash(count - bodyClock);
		break;
	case 3:
		//UpdataGuard(count - bodyClock);
		break;
	case 4:
		UpdataJump(count - bodyClock, flag);
		break;
	case 5:
		//UpdataAttack_s(count - bodyClock);
		break;
	case 6:
		UpdataAttack_w(count - bodyClock);
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

int Player::GetStateFlag() {
	return stateFlag;
}
Square Player::GetAttackArea() {
	return attackArea;
}
int Player::GetAttack() {
	return attack;
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

	if(isRightFlag)
		DrawModiGraph(
			center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
			center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
			center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
			center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
			Image,true);
	else
		DrawModiGraph(
			center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
			center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
			center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
			center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
			Image, true);

	if(stateFlag == 6)
		DrawBox(
			attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
			attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
			RED, false);

	DrawFormatString(0, 0, RED, "P_state : %d ,accept : %d",stateFlag,acceptFlag);

	

	return 0;
}