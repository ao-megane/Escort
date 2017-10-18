#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include<math.h>

int P_run_1;
int P_run_2;
int P_run_3;
int P_run_4;
int P_run_5;
int P_run_6;

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

	P_run_1 = LoadGraph("images/Player/run/1s.png");
	P_run_2 = LoadGraph("images/Player/run/2s.png");
	P_run_3 = LoadGraph("images/Player/run/3s.png");
	P_run_4 = LoadGraph("images/Player/run/4s.png");
	P_run_5 = LoadGraph("images/Player/run/5s.png");
	P_run_6 = LoadGraph("images/Player/run/6s.png");

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
	Image = P_run_1;
	acceptFlag = 1;
	isRightFlag = 1;
	stateFlag = 0;

	return 0;
}

int Player::Set() {
	center.Set(500, GROUND_HEIGHT - P_HEIGHT / 2);
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

int Player::SetWalk() {
	stateFlag = 1;
	Image = P_run_1;
	return 0;
}
int Player::UpdataWalk(int count) {
	int speed = 1;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED);
	int sum = 40;	//����̃t���[����
	int num = 4;	//����̉摜��
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
	Image = P_run_1;
	return 0;
}
int Player::UpdataDash(int count) {
	int speed = 2;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED);
	//DrawFormatString(300, 200, WHITE, "count:%d", count);
	int sum = 18;
	int num = 6;
	if (count % sum <= sum/num * 1) {
		Image = P_run_1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = P_run_2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = P_run_3;
	}
	else if (count % sum <= sum / num * 4) {
		Image = P_run_4;
	}
	else if (count % sum <= sum / num * 5) {
		Image = P_run_5;
	}
	else if (count % sum <= sum) {
		Image = P_run_6;
	}
	return 0;
}

int Player::SetJump() {
	stateFlag = 4;
	//Image = 
	acceptFlag = 0;
	return 0;
}
int Player::UpdataJump(int count) {
	double height = DISP_HEIGHT * 0.5;//jump�̍���
	double sum = 60.0;	//���[�V�����ɂ�����t���[����
	int num = 5;	//�G�̖���
	double a =  -sin((count / sum)*PI) * height;//�ق����R
	center.Set((center.Get_x()) + 1, a + GROUND_HEIGHT - P_HEIGHT / 2);
	if (count >= sum) {
		stateFlag = 0;
		acceptFlag = 1;
	}
	return 0;
}

int Player::SetAttack_w() {
	stateFlag = 6;
	Image = P_run_3;
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
	if (acceptFlag) {//���͎�t���̏���
		if (A) {//�������U��
			if (stateFlag != 7)bodyClock = count;
			//SetAttack_l();
		}
		else if (B) {//��З͍L�͈͍U��
			if (stateFlag != 6)bodyClock = count;
			SetAttack_w();
		}
		else if (Y) {//���З͏��͈͍U��
			if (stateFlag != 5)bodyClock = count;
			//SetAttack_s();
		}
		else if (THUMB_Y <= -80) {//�W�����v
			if (stateFlag != 4)bodyClock = count;
			SetJump();
		}
		else if (THUMB_Y >= 80) {//�K�[�h
			if (stateFlag != 3)bodyClock = count;
			//SetGuard();
		}
		else if (THUMB_X > 80) {//�E�_�b�V��
			if (stateFlag != 2)bodyClock = count;
			isRightFlag = 1;
			SetDash();
		}
		else if (THUMB_X > 0) {//�E����
			if(stateFlag != 1)bodyClock = count;
			isRightFlag = 1;
			SetWalk();
		}
		else if (THUMB_X < -80) {//���_�b�V��
			if (stateFlag != 2)bodyClock = count;
			isRightFlag = 0;
			SetDash();
		}
		else if (THUMB_X < 0) {//������
			if (stateFlag != 1)bodyClock = count;
			isRightFlag = 0;
			SetWalk();
		}
		else {//����
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
		UpdataWalk(count - bodyClock);
		break;
	case 2:
		UpdataDash(count - bodyClock);
		break;
	case 3:
		//UpdataGuard(count - bodyClock);
		break;
	case 4:
		UpdataJump(count - bodyClock);
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

	DrawFormatString(0, 0, RED, "P_state : %d",stateFlag);

	

	return 0;
}