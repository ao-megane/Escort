#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include<math.h>

int PWalk1;
int PWalk2;
int PWalk3;
int PWalk4;
int PWalk5;

int PRun1;
int PRun2;
int PRun3;
int PRun4;
int PRun5;

int PAttacks1;
int PAttacks2;
int PAttacks3;

int PAttackw1;
int PAttackw2;
int PAttackw3;

int backArm;
int backLeg;
int body;
int frontArm;
int frontLeg;
int head;

int Attack_w;
int Attack_s;
int Attack_l;
int PJump;

int Player::Initialize() {

	PWalk1 = LoadGraph("images/Player/walk/Resize/1.png");
	PWalk2 = LoadGraph("images/Player/walk/Resize/2.png");
	PWalk3 = LoadGraph("images/Player/walk/Resize/3.png");
	PWalk4 = LoadGraph("images/Player/walk/Resize/4.png");
	PWalk5 = LoadGraph("images/Player/walk/Resize/5.png");

	PRun1 = LoadGraph("images/Player/run/Resize/1.png");
	PRun2 = LoadGraph("images/Player/run/Resize/2.png");
	PRun3 = LoadGraph("images/Player/run/Resize/3.png");
	PRun4 = LoadGraph("images/Player/run/Resize/4.png");
	PRun5 = LoadGraph("images/Player/run/Resize/5.png");

	PAttacks1 = LoadGraph("images/Player/Attack_s/Resize/1.png");
	PAttacks2 = LoadGraph("images/Player/Attack_s/Resize/2.png");
	PAttacks3 = LoadGraph("images/Player/Attack_s/Resize/3.png");

	PAttackw1 = LoadGraph("images/Player/Attack_w/Resize/1.png");
	PAttackw2 = LoadGraph("images/Player/Attack_w/Resize/2.png");
	PAttackw3 = LoadGraph("images/Player/Attack_w/Resize/3.png");

	Attack_s = LoadSoundMem("music/knife2.wav");
	Attack_l = LoadSoundMem("music/knife.wav");
	PJump = LoadSoundMem("music/jump1.wav");

	center.Set(500, GROUND_HEIGHT - (P_HEIGHT + P_BOTTOM_MARGIN) / 2);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	attack = 0;
	Image = PWalk1;
	acceptFlag = 1;
	isRightFlag = 1;
	stateFlag = 0;
	bodyClock = 0;

	return 0;
}

int Player::PlayAttack_l() {
	PlaySoundMem(Attack_l, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayAttack_s() {
	PlaySoundMem(Attack_s, DX_PLAYTYPE_BACK);
	return 0;
}
int Player::PlayJump() {
	PlaySoundMem(PJump, DX_PLAYTYPE_BACK);
	return 0;
}

int Player::Set(int levelFlag) {
	//if(levelFlag = 1)
	center.Set(500, GROUND_HEIGHT - (P_HEIGHT + P_BOTTOM_MARGIN) / 2);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	attack = 0;
	Image = PWalk1;
	acceptFlag = 1;
	IsJumping = 0;
	bodyClock = 0;
	isRightFlag = 1;
	SetStand();
	return 0;
}

int Player::SetStand() {
	stateFlag = 0;
	acceptFlag = 1;
	Image = PWalk1;
	return 0;
}

int Player::UpdataStand(int count) {
	center.Set(center.Get_x() - GROUND_SPEED, GROUND_HEIGHT -(P_HEIGHT + P_BOTTOM_MARGIN) / 2);
	return 0;
}

int Player::SetWalk() {
	stateFlag = 1;
	acceptFlag = 1;
	Image = PWalk1;
	return 0;
}
int Player::UpdataWalk(int count) {
	int speed = GROUND_SPEED;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
	int sum = 40;	//����̃t���[����
	int num = 8;	//����̉摜��
	if (count % sum <= sum / num * 1) {
		Image = PWalk1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = PWalk2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = PWalk3;
	}
	else if (count % sum <= sum / num * 4) {
		Image = PWalk4;
	}
	else if (count % sum <= sum / num * 5) {
		Image = PWalk5;
	}
	else if (count % sum <= sum / num * 6) {
		Image = PWalk4;
	}
	else if (count % sum <= sum / num * 7) {
		Image = PWalk3;
	}
	else if (count % sum <= sum / num * 8) {
		Image = PWalk2;
	}
	return 0;
}

int Player::SetDash() {
	stateFlag = 2;
	Image = PWalk1;
	acceptFlag = 1;
	return 0;
}
int Player::UpdataDash(int count) {
	int speed = 8;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
	int sum = 40;	//����̃t���[����
	int num = 8;	//����̉摜��
	if (count % sum <= sum / num * 1) {
		Image = PRun1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = PRun2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = PRun3;
	}
	else if (count % sum <= sum / num * 4) {
		Image = PRun4;
	}
	else if (count % sum <= sum / num * 5) {
		Image = PRun5;
	}
	else if (count % sum <= sum / num * 6) {
		Image = PRun4;
	}
	else if (count % sum <= sum / num * 7) {
		Image = PRun3;
	}
	else if (count % sum <= sum / num * 8) {
		Image = PRun2;
	}
	return 0;
}

int Player::SetJump() {
	stateFlag = 4;
	Image = PWalk1;
	acceptFlag = 1;	//�󒆐���
	PlayJump();
	return 0;
}
int Player::UpdataJump(int count,int flag) {
	double height = DISP_HEIGHT * 0.3;//jump�̍���
	double sum = 50.0;	//���[�V�����ɂ�����t���[����
	int num = 5;		//�G�̖���
	double a =  -sin((count / sum)*PI) * height;//�ق����R
	if (a > 0) a *= -1;
	switch (flag)
	{
	case 0://�E�_�b�V��
		center.Set((center.Get_x()) - GROUND_SPEED + 2*2, a + GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
		break;
	case 1://�E����
		center.Set((center.Get_x()) - GROUND_SPEED + 1*2, a + GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
		break; 
	case 2://���_�b�V��
		center.Set((center.Get_x()) - GROUND_SPEED - 2*2, a + GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
		break;
	case 3://������
		center.Set((center.Get_x()) - GROUND_SPEED - 1*2, a + GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
		break;
	case 4://����
		center.Set((center.Get_x()) - GROUND_SPEED + 0, a + GROUND_HEIGHT - P_HEIGHT / 2 + P_BOTTOM_MARGIN);
		break;
	default:
		break;
	}
	
	if (count >= sum) {
		stateFlag = 0;
		acceptFlag = 1;
		bodyClock = count;
	}
	//DrawFormatString(0, 200, RED, "JUMPINGCOUNT : %d", count);
	return 0;
}
int Player::SetPriJump() {
	stateFlag = 8;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdataPriJump(int count) {
	if (count >= 15) {
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//�߂�
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	return 0;
}

int Player::SetAttack_w() {
	stateFlag = 6;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdataAttack_w(int count) {
	Dot LU, RD;
	if (isRightFlag) {
		LU.Set(center.Get_x() - P_WIDTH*0.3, center.Get_y() - P_HEIGHT*0.3);
		RD.Set(center.Get_x() + P_WIDTH*0.3 * 2, center.Get_y() + P_HEIGHT*0.3 / 2);
	}
	else {
		LU.Set(center.Get_x() + P_WIDTH*0.3, center.Get_y() - P_HEIGHT*0.3);
		RD.Set(center.Get_x() - P_WIDTH*0.3 * 2, center.Get_y() + P_HEIGHT*0.3 / 2);
	}

	if (count < 2) {
		acceptFlag = 0;
	}
	else if (count < 15) {
		attack = 10;
		attackArea.Set(LU, RD);
	}
	else if (count < 17) {
		attack = 0;
	}
	else if (count >= 17) {//���[�V�����I���
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//�߂�
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}

	if (count == 0) Image = PAttackw1;
	if (count == 2) Image = PAttackw2;
	if (count == 5) Image = PAttackw3;

	return 0;
}

int Player::SetAttack_s() {
	stateFlag = 5;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdataAttack_s(int count) {
	Dot LU, RD;
	if (isRightFlag) {
		LU.Set(center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 4);
		RD.Set(center.Get_x() + P_WIDTH *3/2, center.Get_y() + P_HEIGHT / 4);
	}
	else {
		LU.Set(center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT/4);
		RD.Set(center.Get_x() - P_WIDTH *3/2, center.Get_y() + P_HEIGHT / 4);
	}

	if (count < 17) {//�ҋ@
		acceptFlag = 0;
	}
	else if (count < 20) {//�U��
		attack = 50;
		attackArea.Set(LU, RD);
	}
	else if (count < 40) {//�]�C
		attack = 0;
	}
	else if (count >= 40) {//���[�V�����I���
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//�߂�
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	if (count == 0) Image = PAttacks1;
	if (count == 17) Image = PAttacks2;
	if (count == 19) Image = PAttacks3;
	if (count == 17)
		PlayAttack_s();
	return 0;
}

int Player::SetAttack_l() {
	stateFlag = 7;
	Image = PWalk1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdataAttack_l(int count) {
	Dot LU, RD;
	if (isRightFlag) {
		LU.Set(center.Get_x() - P_HEIGHT / 2 + (count - 10) * 40, center.Get_y() - P_HEIGHT / 2 );
		RD.Set(center.Get_x() + P_HEIGHT / 2 + (count - 10) * 40, center.Get_y() + P_HEIGHT / 2 );
	}
	else {
		LU.Set(center.Get_x() - P_HEIGHT / 2 - (count - 10) * 40, center.Get_y() - P_HEIGHT / 2 );
		RD.Set(center.Get_x() + P_HEIGHT / 2 - (count - 10) * 40, center.Get_y() + P_HEIGHT / 2);
	}

	if (count < 10) {//�ҋ@
		acceptFlag = 0;
	}
	else if (count < 40) {//�U��
		attack = 30;
		attackArea.Set(LU, RD);
	}
	else if (count < 60) {//�]�C
		attack = 0;
	}
	else if (count >= 60) {//���[�V�����I���
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//�߂�
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}

	if(count == 10)
		PlayAttack_l();
	return 0;
}

int Player::Updata(int count,int Key[]) {
	int flag = 4;//�󒆐���p�t���O
	if (acceptFlag) {//���͎�t���̏���
		//���Ԃ肠��݂����Ȃ̂�updata�ł��̂����
		if (A) {//�������U��
			if (stateFlag == 4) {
				IsJumping = bodyClock + 60;
			}
			else {
				IsJumping = 0;
			}
			if (stateFlag != 7)
				bodyClock = count;
			SetAttack_l();
		}
		else if (B) {//��З͍L�͈͍U��
			if (stateFlag == 4) {
				IsJumping = bodyClock + 17;
			}
			else {
				IsJumping = 0;
			}
			if (stateFlag != 6)
				bodyClock = count;
			SetAttack_w();
		}
		else if (Y) {//���З͏��͈͍U��
			if (stateFlag == 4) {
				IsJumping = bodyClock + 40;
			}
			else {
				IsJumping = 0;
			}
			if (stateFlag != 5)
				bodyClock = count;
			SetAttack_s();
		}
		else if (X) {//�P�W�����v
			if (stateFlag == 4) {
				IsJumping = bodyClock + 15;
			}
			else {
				IsJumping = 0;
			}
			if (stateFlag != 8)
				bodyClock = count;
			SetPriJump();
		}
		else if (abs(THUMB_Y) == 0 && abs(THUMB_X) == 0) {//����
			if (stateFlag != 0 && stateFlag != 4)bodyClock = count;
			flag = 4;
			if (stateFlag != 4)//�W�����v���łȂ����
				SetStand();
		} else {//�U���͂Ȃ��Ĉړ��Ȃ�
			if (THUMB_Y <= -80) {//�W�����v
				if (stateFlag != 4) {
					bodyClock = count;
					IsJumping = count;
					SetJump();
					//printfDx("SETJUMP!!");
				}
			}
			//else if (THUMB_Y >= 80) {//�K�[�h
			//	if (stateFlag != 3 && stateFlag != 4)bodyClock = count;
			//	//SetGuard();
			//}
			if (THUMB_X >= 80) {//�E�_�b�V��
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count; 
					SetDash();
				}
				flag = 0;
				isRightFlag = 1;
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X > 0) {//�E����
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 1;
				isRightFlag = 1;
				/*if (stateFlag != 4)
					SetWalk();*/
			}
			if (THUMB_X <= -80) {//���_�b�V��
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count;
					SetDash();
				}
				flag = 2;
				isRightFlag = 0;
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X < 0) {//������
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 3;
				isRightFlag = 0;
				/*if (stateFlag != 4)
					SetWalk();*/
			}
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
		UpdataAttack_s(count - bodyClock);
		break;
	case 6:
		UpdataAttack_w(count - bodyClock);
		break;
	case 7:
		UpdataAttack_l(count - bodyClock);
		break;
	case 8:
		UpdataPriJump(count - bodyClock);
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

	if(attack > 0)
		DrawBox(
			attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
			attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
			RED, false);

	//DrawFormatString(0, 0, RED, "P_state : %2d ,accept : %2d,bodyClock : %5d,center.y : %5d",stateFlag,acceptFlag,bodyClock,center.Get_y());

	

	return 0;
}