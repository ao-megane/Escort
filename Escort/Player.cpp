#include"Player.h"
#include"DxLib.h"
#include"Value.h"
#include<math.h>

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

	P_walk_1 = LoadGraph("images/Player/walk/a1.png");
	P_walk_2 = LoadGraph("images/Player/walk/a2.png");
	P_walk_3 = LoadGraph("images/Player/walk/a3.png");

	/*backArm = LoadGraph("images/Player/characterChip/backarm.png");
	backLeg = LoadGraph("images/Player/characterChip/backleg.png");
	body = LoadGraph("images/Player/characterChip/body.png");
	frontArm = LoadGraph("images/Player/characterChip/frontarm.png");
	frontLeg = LoadGraph("images/Player/characterChip/frontleg.png");
	head = LoadGraph("images/Player/characterChip/head.png");*/

	center.Set(500, GROUND_HEIGHT - P_HEIGHT / 2);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	attack = 0;
	Image = P_walk_1;
	acceptFlag = 1;
	isRightFlag = 1;
	stateFlag = 0;
	bodyClock = 0;

	return 0;
}

int Player::Set(int levelFlag) {
	//if(levelFlag = 1)
	center.Set(500, GROUND_HEIGHT - P_HEIGHT / 2);
	weekArea.Set(center, P_WIDTH*0.8, P_HEIGHT*0.8);
	attack = 0;
	Image = P_walk_1;
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
	Image = P_walk_1;
	return 0;
}

int Player::UpdataStand(int count) {
	center.Set(center.Get_x() - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	return 0;
}

int Player::SetWalk() {
	stateFlag = 1;
	acceptFlag = 1;
	Image = P_walk_1;
	return 0;
}
int Player::UpdataWalk(int count) {
	int speed = GROUND_SPEED;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
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
	acceptFlag = 1;
	return 0;
}
int Player::UpdataDash(int count) {
	int speed = 8;
	if(isRightFlag)
		center.Set(center.Get_x() + speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
	else
		center.Set(center.Get_x() - speed - GROUND_SPEED, GROUND_HEIGHT - P_HEIGHT / 2);
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
	double height = DISP_HEIGHT * 0.3;//jumpの高さ
	double sum = 50.0;	//モーションにかかるフレーム数
	int num = 5;		//絵の枚数
	double a =  -sin((count / sum)*PI) * height;//ほしい山
	if (a > 0) a *= -1;
	switch (flag)
	{
	case 0://右ダッシュ
		center.Set((center.Get_x()) - GROUND_SPEED + 2*2, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	case 1://右歩き
		center.Set((center.Get_x()) - GROUND_SPEED + 1*2, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break; 
	case 2://左ダッシュ
		center.Set((center.Get_x()) - GROUND_SPEED - 2*2, a + GROUND_HEIGHT - P_HEIGHT / 2);
		break;
	case 3://左歩き
		center.Set((center.Get_x()) - GROUND_SPEED - 1*2, a + GROUND_HEIGHT - P_HEIGHT / 2);
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
	//DrawFormatString(0, 200, RED, "JUMPINGCOUNT : %d", count);
	return 0;
}
int Player::SetPriJump() {
	stateFlag = 8;
	Image = P_walk_1;
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
			stateFlag = 4;//戻す
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
	Image = P_walk_1;
	acceptFlag = 0;
	attack = 0;
	return 0;
}
int Player::UpdataAttack_w(int count) {
	Dot LU, RD;
	if (isRightFlag) {
		LU.Set(center.Get_x() - P_WIDTH, center.Get_y() - P_HEIGHT);
		RD.Set(center.Get_x() + P_WIDTH * 2, center.Get_y() + P_HEIGHT / 2);
	}
	else {
		LU.Set(center.Get_x() + P_WIDTH, center.Get_y() - P_HEIGHT);
		RD.Set(center.Get_x() - P_WIDTH * 2, center.Get_y() + P_HEIGHT / 2);
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
	else if (count >= 17) {//モーション終わり
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//戻す
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	return 0;
}

int Player::SetAttack_s() {
	stateFlag = 5;
	Image = P_walk_1;
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

	if (count < 17) {//待機
		acceptFlag = 0;
	}
	else if (count < 20) {//攻撃
		attack = 50;
		attackArea.Set(LU, RD);
	}
	else if (count < 40) {//余韻
		attack = 0;
	}
	else if (count >= 40) {//モーション終わり
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//戻す
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	return 0;
}

int Player::SetAttack_l() {
	stateFlag = 7;
	Image = P_walk_1;
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

	if (count < 10) {//待機
		acceptFlag = 0;
	}
	else if (count < 40) {//攻撃
		attack = 30;
		attackArea.Set(LU, RD);
	}
	else if (count < 60) {//余韻
		attack = 0;
	}
	else if (count >= 60) {//モーション終わり
		acceptFlag = 1;
		if (IsJumping != 0) {
			bodyClock = IsJumping;
			IsJumping = 0;
			stateFlag = 4;//戻す
		}
		else {
			SetStand();
			//printfDx("SETSTAND!\n");
		}
	}
	return 0;
}

int Player::Updata(int count,int Key[]) {
	int flag = 4;//空中制御用フラグ
	if (acceptFlag) {//入力受付時の処理
		//だぶりありみたいなのはupdataでやるのが無難か
		if (A) {//遠距離攻撃
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
		else if (B) {//低威力広範囲攻撃
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
		else if (Y) {//高威力小範囲攻撃
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
		else if (X) {//姫ジャンプ
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
		else if (abs(THUMB_Y) == 0 && abs(THUMB_X) == 0) {//立ち
			if (stateFlag != 0 && stateFlag != 4)bodyClock = count;
			flag = 4;
			if (stateFlag != 4)//ジャンプ中でなければ
				SetStand();
		} else {//攻撃はなくて移動なら
			if (THUMB_Y <= -80) {//ジャンプ
				if (stateFlag != 4) {
					bodyClock = count;
					IsJumping = count;
					SetJump();
					//printfDx("SETJUMP!!");
				}
			}
			//else if (THUMB_Y >= 80) {//ガード
			//	if (stateFlag != 3 && stateFlag != 4)bodyClock = count;
			//	//SetGuard();
			//}
			if (THUMB_X >= 80) {//右ダッシュ
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count; 
					SetDash();
				}
				flag = 0;
				isRightFlag = 1;
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X > 0) {//右歩き
				if (stateFlag != 1 && stateFlag != 4) {
					bodyClock = count;
					SetWalk();
				}
				flag = 1;
				isRightFlag = 1;
				/*if (stateFlag != 4)
					SetWalk();*/
			}
			if (THUMB_X <= -80) {//左ダッシュ
				if (stateFlag != 2 && stateFlag != 4) {
					bodyClock = count;
					SetDash();
				}
				flag = 2;
				isRightFlag = 0;
				/*if (stateFlag != 4)
					SetDash();*/
			}
			else if (THUMB_X < 0) {//左歩き
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

	DrawFormatString(0, 0, RED, "P_state : %2d ,accept : %2d,bodyClock : %5d,center.y : %5d",stateFlag,acceptFlag,bodyClock,center.Get_y());

	

	return 0;
}