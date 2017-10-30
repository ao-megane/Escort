#include "EnemyMng.h"
#include "Value.h"
#include "DxLib.h"

int EDamage;
//int Enemy::Draw() {
//
//	DrawBox(
//		center.Get_x() - width / 2, center.Get_y() - height / 2,
//		center.Get_x() + width / 2, center.Get_y() + height / 2,
//		GREEN, false);
//	DrawBox(
//		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
//		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
//		BLUE, false);
//	DrawBox(
//		attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
//		attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
//		RED, false);
//
//	if(dirFlag)
//		DrawModiGraph(
//			center.Get_x() - width / 2, center.Get_y() - height / 2,
//			center.Get_x() + width / 2, center.Get_y() - height / 2,
//			center.Get_x() + width / 2, center.Get_y() + height / 2,
//			center.Get_x() - width / 2, center.Get_y() + height / 2,
//			Image, true);
//	else
//		DrawModiGraph(
//			center.Get_x() + width / 2, center.Get_y() - height / 2,
//			center.Get_x() - width / 2, center.Get_y() - height / 2,
//			center.Get_x() - width / 2, center.Get_y() + height / 2,
//			center.Get_x() + width / 2, center.Get_y() + height / 2,
//			Image, true);
//	return 0;
//}
int Enemy::GetExistFlag() {
	return existFlag;
}
int Enemy::SetHP(int a) {
	HP = a;
	return 0;
}
int Enemy::SetAttackval(int a) {
	attack = a;
	return 0;
}
int Enemy::GetHP() {
	return HP;
}
int Enemy::GetAttack() {
	return attack;
}
int Enemy::GetStartClock() {
	return startClock;
}
int Enemy::GetStateFlag() {
	return stateFlag;
}
int Enemy::GetBodyClock() {
	return bodyClock;
}
int Enemy::GetHeight() {
	return height;
}
int Enemy::GetWidth() {
	return width;
}
int Enemy::GetStrength() {
	return strength;
}
Dot Enemy::GetCenter() {
	return center;
}
Square Enemy::GetWeekArea() {
	return weekArea;
}
Square Enemy::GetAttackArea() {
	return attackArea;
}
int Enemy::PlayDamage() {
	PlaySoundMem(EDamage, DX_PLAYTYPE_BACK);
	return 0;
}

int Decoi;

int WeakSlimeStand1;
int WeakSlimeStand2;
int WeakSlimeStand3;
int WeakSlimeJump1;
int WeakSlimeJump2;
int WeakSlimeJump3;

int MiddleSlimeStand1;
int MiddleSlimeStand2;
int MiddleSlimeStand3;
int MiddleSlimeJump1;
int MiddleSlimeJump2;
int MiddleSlimeJump3;

int ToughSlimeStand1;
int ToughSlimeStand2;
int ToughSlimeStand3;
int ToughSlimeJump1;
int ToughSlimeJump2;
int ToughSlimeJump3;

Slime slime[10];
void SlimeMngInitialize() {
	WeakSlimeStand1 = LoadGraph("images/Slime/weak/stand/1.png");
	WeakSlimeStand2 = LoadGraph("images/Slime/weak/stand/2.png");
	WeakSlimeStand3 = LoadGraph("images/Slime/weak/stand/3.png");
	WeakSlimeJump1 = LoadGraph("images/Slime/weak/jump/1.png");
	WeakSlimeJump2 = LoadGraph("images/Slime/weak/jump/2.png");
	WeakSlimeJump3 = LoadGraph("images/Slime/weak/jump/3.png");

	MiddleSlimeStand1 = LoadGraph("images/Slime/middle/stand/1.png");
	MiddleSlimeStand2 = LoadGraph("images/Slime/middle/stand/2.png");
	MiddleSlimeStand3 = LoadGraph("images/Slime/middle/stand/3.png");
	MiddleSlimeJump1 = LoadGraph("images/Slime/middle/jump/1.png");
	MiddleSlimeJump2 = LoadGraph("images/Slime/middle/jump/2.png");
	MiddleSlimeJump3 = LoadGraph("images/Slime/middle/jump/3.png");

	ToughSlimeStand1 = LoadGraph("images/Slime/tough/stand/1.png");
	ToughSlimeStand2 = LoadGraph("images/Slime/tough/stand/2.png");
	ToughSlimeStand3 = LoadGraph("images/Slime/tough/stand/3.png");
	ToughSlimeJump1 = LoadGraph("images/Slime/tough/jump/1.png");
	ToughSlimeJump2 = LoadGraph("images/Slime/tough/jump/2.png");
	ToughSlimeJump3 = LoadGraph("images/Slime/tough/jump/3.png");

	EDamage = LoadSoundMem("music/damage.wav");

	for (int i = 0; i < 10; i++) {
		slime[i].Initialize();
	}
}
void Slime::Initialize() {
	existFlag = 0;
	bodyClock = 0;
	strength = 0;
}
int Slime::Set(int count,int isright,int level) {
	strength = level;
	width = SLIME_WIDTH * (strength * 2 + 1);
	height = SLIME_HEIGHT * (strength * 2 + 1);
	weekArea.Set(center, width, height);
	attackArea.Set(center, width, height);
	/*SetHP(20 * (strength + 1));
	SetAttackval(20 * (strength + 1));*/
	SetHP(20);
	SetAttackval(20);
	if (strength == 0)
		Image = WeakSlimeStand1;
	else if (strength == 1)
		Image = MiddleSlimeStand1;
	else if (strength == 2)
		Image = ToughSlimeStand1;
	bodyClock = count;
	startClock = count;
	existFlag = 1;
	if (isright) {
		center.Set(DISP_WIDTH + width, GROUND_HEIGHT - height / 2);
		dirFlag = 0;
	}
	else {
		center.Set(0 - width/2, GROUND_HEIGHT - height / 2);
		dirFlag = 1;
	}
	SetStand(count);
	return 0;
}
int Slime::SetStand(int count) {
	stateFlag = 0;
	bodyClock = count;
	return 0;
}
int Slime::UpdataStand(int count) {
	//int speed = 2 * ((dirFlag == 1 ? 1 : -1));
	center.Set(center.Get_x() - GROUND_SPEED + SLIME_STAND_SPEED * ((dirFlag == 1 ? 1 : -1)), center.Get_y());
	//int sum = 40;	//一周のフレーム数
	//int num = 4;	//一周の画像数
	if (strength == 0) {
		if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 1) {
			Image = WeakSlimeStand1;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 2) {
			Image = WeakSlimeStand2;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 3) {
			Image = WeakSlimeStand3;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_NUM) {
			Image = WeakSlimeStand2;
		}
	}
	else if (strength == 1) {
		if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 1) {
			Image = MiddleSlimeStand1;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 2) {
			Image = MiddleSlimeStand2;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 3) {
			Image = MiddleSlimeStand3;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_NUM) {
			Image = MiddleSlimeStand2;
		}
	}
	else if (strength == 2) {
		if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 1) {
			Image = ToughSlimeStand1;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 2) {
			Image = ToughSlimeStand2;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_SUM / SLIME_STAND_NUM * 3) {
			Image = ToughSlimeStand3;
		}
		else if (count % SLIME_STAND_SUM <= SLIME_STAND_NUM) {
			Image = ToughSlimeStand2;
		}
	}
	return 0;
}
int Slime::SetJump(int count) {
	stateFlag = 3;
	bodyClock = count;
	//startClock = count;
	return 0;
}
int Slime::UpdataJump(int count) {
	//double high = DISP_HEIGHT * 0.3;//jumpの高さ
	//double sum = 40.0;	//モーションにかかるフレーム数
	//int speed = 1 * ((dirFlag == 1 ? 1 : -1));
	//int num = 5;	//絵の枚数
	double a = -sin((count / SLIME_JUMP_SUM)*PI) * SLIME_JUMP_HIGH;//ほしい山
	center.Set((center.Get_x()) - GROUND_SPEED + SLIME_JUMP_SPEED * ((dirFlag == 1 ? 1 : -1)), a + GROUND_HEIGHT - height / 2);

	if (strength == 0) {
		if (count < 40 / 4 * 1) Image = WeakSlimeJump1;
		else if (count < 40 / 4 * 2) Image = WeakSlimeJump2;
		else if (count < 40 / 4 * 4) Image = WeakSlimeJump3;
	}
	else if (strength == 1) {
		if (count < 40 / 4 * 1) Image = MiddleSlimeJump1;
		else if (count < 40 / 4 * 2) Image = MiddleSlimeJump2;
		else if (count < 40 / 4 * 4) Image = MiddleSlimeJump3;
	}
	else if (strength == 2) {
		if (count < 40 / 4 * 1) Image = ToughSlimeJump1;
		else if (count < 40 / 4 * 2) Image = ToughSlimeJump2;
		else if (count < 40 / 4 * 4) Image = ToughSlimeJump3;
	}

	if (count >= SLIME_JUMP_SUM) {
		stateFlag = 0;
		bodyClock = count;
		SetStand(count);
	}
	return 0;
}
int Slime::SetDamage(int count, int damage) {
	stateKeeper = stateFlag;
	stateFlag = 5;
	clockKeeper = bodyClock + 60;
	bodyClock = count;
	SetHP(GetHP() - damage);
	PlayDamage();
	return 0;
}
int Slime::UpdataDamage(int count) {
	center.Set(center.Get_x() - GROUND_SPEED);
	if (count >= 60) {
		bodyClock = clockKeeper;
		clockKeeper = 0;
		stateFlag = stateKeeper;
	}
	return 0;
}
int Slime::SetDisapper(int count) {
	stateFlag = 6;
	bodyClock = count;
	return 0;
}
int Slime::UpdataDisapper(int count) {
	//int sum = 5;	//モーションにかかるフレーム数
	//int num = 1;	//絵の枚数
	//center.Set((center.Get_x()) - GROUND_SPEED + 0, GROUND_HEIGHT - SLIME_HEIGHT / 2);
	/*if (count % sum <= sum / num * 1) {
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
	}*/

	if (count % 3 == 0) Image = Decoi;
	else {
		if (strength == 0) {
			Image = WeakSlimeStand1;
		}
		else if (strength == 1) {
			Image = MiddleSlimeStand1;
		}
		else if (strength == 2) {
			Image = ToughSlimeStand1;
		}
	}

	if (count >= SLIME_DISAP_SUM) {
		existFlag = 0;
	}
	return 0;
}
int Slime::Updata(int count) {
	if (HP <= 0 && stateFlag != 6) {
		bodyClock = count;
		SetDisapper(count);
	}
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock);
		break;
	case 1:
		//UpdataDash(count - bodyClock);
		break;
	//case 2:
	//	UpdataAttack(count - bodyClock);
	//	break;
	case 3:
		UpdataJump(count - bodyClock);
		break;
	//case 4:
	//	UpdataHappen(count - bodyClock);
	//	break;
	case 5:
		UpdataDamage(count - bodyClock);
		break;
	case 6:
		UpdataDisapper(count - bodyClock);
		break;
	//case 7:
	//	//UpdataAttack_l(count - bodyClock);
	//	break;
	default:
		break;
	}

	weekArea.Set(center, width*0.8, height*0.8);
	attackArea.Set(center, width*0.7, height*0.7);
	return 0;
}
int Slime::Draw() {

	DrawBox(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		GREEN, false);
	DrawBox(
		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
		BLUE, false);
	DrawBox(
		attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
		attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
		RED, false);

	if (dirFlag)
		DrawModiGraph(
			center.Get_x() - width / 2 + SLIME_DIFF_H, center.Get_y() - height / 2 + SLIME_DIFF_W,
			center.Get_x() + width / 2 + SLIME_DIFF_H, center.Get_y() - height / 2 + SLIME_DIFF_W,
			center.Get_x() + width / 2 + SLIME_DIFF_H, center.Get_y() + height / 2 + SLIME_DIFF_W,
			center.Get_x() - width / 2 + SLIME_DIFF_H, center.Get_y() + height / 2 + SLIME_DIFF_W,
			Image, true);
	else
		DrawModiGraph(
			center.Get_x() + width / 2 + SLIME_DIFF_H, center.Get_y() - height / 2 + SLIME_DIFF_W,
			center.Get_x() - width / 2 + SLIME_DIFF_H, center.Get_y() - height / 2 + SLIME_DIFF_W,
			center.Get_x() - width / 2 + SLIME_DIFF_H, center.Get_y() + height / 2 + SLIME_DIFF_W,
			center.Get_x() + width / 2 + SLIME_DIFF_H, center.Get_y() + height / 2 + SLIME_DIFF_W,
			Image, true);
	return 0;
}

/*------------------------------------------------------------------------------------------------------------------------*/

int WeakBirdStand1;
int WeakBirdStand2;
int WeakBirdStand3;
int WeakBirdAttack1;
int WeakBirdRunaway1;

int MiddleBirdStand1;
int MiddleBirdStand2;
int MiddleBirdStand3;
int MiddleBirdAttack1;
int MiddleBirdRunaway1;

int ToughBirdStand1;
int ToughBirdStand2;
int ToughBirdStand3;
int ToughBirdAttack1;
int ToughBirdRunaway1;


Bird bird[10];
void BirdMngInitialize() {

	WeakBirdStand1 = LoadGraph("images/Bird/weak/stand/1.png");
	WeakBirdStand2 = LoadGraph("images/Bird/weak/stand/2.png");
	WeakBirdStand3 = LoadGraph("images/Bird/weak/stand/3.png");
	WeakBirdAttack1 = LoadGraph("images/Bird/weak/attack/1.png");
	WeakBirdRunaway1 = LoadGraph("images/Bird/weak/runaway/1.png");

	MiddleBirdStand1 = LoadGraph("images/Bird/middle/stand/1.png");
	MiddleBirdStand2 = LoadGraph("images/Bird/middle/stand/2.png");
	MiddleBirdStand3 = LoadGraph("images/Bird/middle/stand/3.png");
	MiddleBirdAttack1 = LoadGraph("images/Bird/middle/attack/1.png");
	MiddleBirdRunaway1 = LoadGraph("images/Bird/middle/runaway/1.png");

	ToughBirdStand1 = LoadGraph("images/Bird/tough/stand/1.png");
	ToughBirdStand2 = LoadGraph("images/Bird/tough/stand/2.png");
	ToughBirdStand3 = LoadGraph("images/Bird/tough/stand/3.png");
	ToughBirdAttack1 = LoadGraph("images/Bird/tough/attack/1.png");
	ToughBirdRunaway1 = LoadGraph("images/Bird/tough/runaway/1.png");

	EDamage = LoadSoundMem("music/damage.wav");
	for (int i = 0; i < 10; i++) {
		bird[i].Initialize();
	}
}
int Bird::Initialize() {
	existFlag = 0;
	bodyClock = 0;
	width = BIRD_WIDTH;
	height = BIRD_HEIGHT;
	return 0;
}
int Bird::Set(int count,int isright,int level) {
	strength = level;
	width = BIRD_WIDTH*(strength + 1);
	height = BIRD_HEIGHT*(strength + 1);
	if (!isright) {
		center.Set(0 - width / 2, 300 + height / 2);
		dirFlag = 0;
	}
	else {
		center.Set(DISP_WIDTH + width / 2, 300 + height / 2);
		dirFlag = 1;
	}
	weekArea.Set(center, width * 0.8, height * 0.8);
	attackArea.Set(center, width * 0.7, height * 0.7);
	if(strength == 0)
		Image = WeakBirdStand1;
	else if (strength == 1)
		Image = MiddleBirdStand1;
	if (strength == 2)
		Image = ToughBirdStand1;
	bodyClock = count;
	startClock = count;
	existFlag = 1;
	SetHP(20 * (strength + 1));
	SetAttackval(10 * (strength + 1));
	/*SetHP(20);
	SetAttackval(10);*/
	SetStand(count);
	return 0;
}
int Bird::SetStand(int count) {
	stateFlag = 0;
	bodyClock = count;
	return 0;
}
int Bird::UpdataStand(int count) {
	//int sum = 90;	//一周のフレーム数
	//int num = 4;	//一周の画像数
	//int speed = 2 * ((dirFlag == 0 ? -1 : 1));
	//double high = 10.0;
	//double a = -sin(2 * PI * count / 30 * 1) * high;
	center.Set(center.Get_x() - GROUND_SPEED + BIRD_STAND_SPEED*(dirFlag == 0 ? -1 : 1), BIRD_HIGH + -sin(2 * PI * count / 30 * 1) * BIRD_STAND_HIGH);
	if (strength == 0) {
		if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 1) {
			Image = WeakBirdStand1;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 2) {
			Image = WeakBirdStand2;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 3) {
			Image = WeakBirdStand3;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM) {
			Image = WeakBirdStand2;
		}
	}
	else if (strength == 1) {
		if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 1) {
			Image = MiddleBirdStand1;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 2) {
			Image = MiddleBirdStand2;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 3) {
			Image = MiddleBirdStand3;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM) {
			Image = MiddleBirdStand2;
		}
	}
	else if (strength == 2) {
		if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 1) {
			Image = ToughBirdStand1;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 2) {
			Image = ToughBirdStand2;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM / BIRD_STAND_NUM * 3) {
			Image = ToughBirdStand3;
		}
		else if (count % BIRD_STAND_SUM <= BIRD_STAND_SUM) {
			Image = ToughBirdStand2;
		}
	}

	return 0;
}
Dot girl;
int Bird::SetAttack(int count,Dot princess) {
	stateFlag = 2;
	girl = princess;
	bodyClock = count;
	if (center.Get_x() > princess.Get_x()) dirFlag = 0;
	else dirFlag = 1;
	return 0;
}
int Bird::UpdataAttack(int count) {
	//double prepare = 15.0;	//予備動作のフレーム数
	//double sum = 60.0;	//攻撃のフレーム数
	//int num = 4;	//一周の画像数
	//int speed = 2 * ((dirFlag == 0 ? 1 : -1));
	if (count < BIRD_ATTACK_PRE) {//予備動作
		if(center.Get_x() < girl.Get_x())
			center.Set(center.Get_x() - 1, center.Get_y() - 1);
		else
			center.Set(center.Get_x() + 1, center.Get_y() + 1);
	}
	else if (count == BIRD_ATTACK_PRE) {//攻撃先の決定
		birdAttackHigh = (double)((girl.Get_y() - (300.0)));
		birdAttackWidth = (center.Get_x() - girl.Get_x()) * 2.0;
		SetAttackval(20);
		//printfDx("TARGET!!\n");
	}
	else {//攻撃
		//double a = -sin(2 * PI * (1) * (count / 30)) * birdAttackHigh;
		double a = sin(2 * PI*(15.0/BIRD_ATTACK_SUM)*((count-BIRD_ATTACK_PRE) / 30.0)) * birdAttackHigh;
		center.Set(center.Get_x() - birdAttackWidth / BIRD_ATTACK_SUM, 300 + a);
		//center.Set(center.Get_x(), 300 + width / 2 + a);

		//if ((count - prepare) % sum <= sum / num * 1) {
		//	//printfDx("1!!");
		//	//Image = P_walk_1;
		//}
		//else if ((count - prepare) % sum <= sum / num * 2) {
		//	//printfDx("2!!");
		//	//Image = P_walk_2;
		//}
		//else if ((count - prepare) % sum <= sum / num * 3) {
		//	//printfDx("3!!");
		//	//Image = P_walk_3;
		//}
		//else if ((count - prepare) % sum < sum / num * 4) {
		//	//printfDx("4!!");
		//	//Image = P_walk_2;
		//}
		//else 
		if (count == BIRD_ATTACK_PRE + BIRD_ATTACK_SUM) {
			//printfDx("SET!!\n");
			//dirFlag == 0 ? dirFlag = 1 : dirFlag = 0;
			SetStand(count);
		}
	}
	if (count <= BIRD_ATTACK_PRE + BIRD_ATTACK_SUM) {
		if (strength == 0)Image = WeakBirdAttack1;
		else if (strength == 1)Image = MiddleBirdAttack1;
		else if (strength == 2)Image = ToughBirdAttack1;
	}
		
	return 0;
}
int Bird::SetDamage(int count, int damage) {
	stateKeeper = stateFlag;
	stateFlag = 5;
	bodyClock = count;
	clockKeeper = count + 60;
	SetHP(GetHP() - damage);
	PlayDamage();
	return 0;
}
int Bird::UpdataDamage(int count) {
	//int speed = -GROUND_SPEED;
	center.Set(center.Get_x() + BIRD_DAMAGE_SPEED);
	if (count >= 60) {
		bodyClock = count;
		clockKeeper = 0;
		SetBack(count);
	}
	return 0;
}
int Bird::SetDisapper(int count) {
	stateFlag = 6;
	bodyClock = count;
	//printfDx("DISAPPERSET\n");
	return 0;
}
int Bird::UpdataDisapper(int count) {
	//int sum = 5;	//モーションにかかるフレーム数
	//int num = 1;	//絵の枚数
	//center.Set((center.Get_x()) - GROUND_SPEED + 0, GROUND_HEIGHT - SLIME_HEIGHT / 2);
	/*if (count % sum <= sum / num * 1) {
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
	}*/
	//printfDx("DISAPPERUPDATA\n");
	if (count >= BIRD_DISAP_SUM) {
		existFlag = 0;
	}
	return 0;
}
int Bird::SetBack(int count) {
	stateFlag = 7;
	bodyClock = count;
	(dirFlag == 0 ? dirFlag = 1 : dirFlag = 0);
	//printfDx("DISAPPERSET\n");
	return 0;
}
int Bird::UpdataBack(int count) {
	//int sum = 5;	//モーションにかかるフレーム数
	//int num = 1;	//絵の枚数
	center.Set(center.Get_x() + (dirFlag == 0 ? -11 : 1) * BIRD_BACK_SPEED / 8, center.Get_y() - BIRD_BACK_SPEED);
	/*if (count % sum <= sum / num * 1) {
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
	}*/
	//printfDx("DISAPPERUPDATA\n");
	if (center.Get_y() <300 ) {
		SetStand(count);
	}
	if (strength == 0)
		Image = WeakBirdRunaway1;
	else if (strength == 1)
		Image = MiddleBirdRunaway1;
	else if (strength == 2)
		Image = ToughBirdRunaway1;
	return 0;
}
int Bird::Updata(int count) {
	if (HP <= 0 && stateFlag != 6) {
		bodyClock = count;
		SetDisapper(count);
	}
	if (center.Get_x() <= 0) dirFlag = 1;
	if (center.Get_x() >= DISP_WIDTH + width / 2) dirFlag = 0;
	switch (stateFlag)
	{
	case 0:
		UpdataStand(count - bodyClock);
		break;
	case 1:
		//UpdataDash(count - bodyClock);
		break;
	case 2:
		UpdataAttack(count - bodyClock);
		break;
	case 3:
		//UpdataJump(count - bodyClock);
		break;
	//case 4:
	//	UpdataHappen(count - bodyClock);
	//	break;
	case 5:
		UpdataDamage(count - bodyClock);
		break;
	case 6:
		UpdataDisapper(count - bodyClock);
		break;
	case 7:
		UpdataBack(count - bodyClock);
		break;
	default:
		break;
	}

	//weekArea.Set(center, BIRD_WIDTH*0.8, BIRD_HEIGHT*0.8);
	weekArea.Set(center, width * 0.8, height * 0.8);
	attackArea.Set(center, width * 0.7, height * 0.7);
	return 0;
}
int Bird::Draw() {
	DrawBox(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		GREEN, false);
	DrawBox(
		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
		BLUE, false);
	DrawBox(
		attackArea.Get_LU().Get_x(), attackArea.Get_LU().Get_y(),
		attackArea.Get_RD().Get_x(), attackArea.Get_RD().Get_y(),
		RED, false);

	if(dirFlag)
		DrawModiGraph(
			center.Get_x() - width / 2, center.Get_y() - height / 2,
			center.Get_x() + width / 2, center.Get_y() - height / 2,
			center.Get_x() + width / 2, center.Get_y() + height / 2,
			center.Get_x() - width / 2, center.Get_y() + height / 2,
			Image, true);
	else
		DrawModiGraph(
			center.Get_x() + width / 2, center.Get_y() - height / 2,
			center.Get_x() - width / 2, center.Get_y() - height / 2,
			center.Get_x() - width / 2, center.Get_y() + height / 2,
			center.Get_x() + width / 2, center.Get_y() + height / 2,
			Image, true);
	return 0;
}

/*---------------------------------------------------------------------------------------------------*/

int SlimeMngSet(int count,int dirFlag,int level) {
	for (int i = 0; i < 10; i++) {
		if (!slime[i].GetExistFlag()) {
			slime[i].Set(count, dirFlag, level);
			return 0;
		}
	}
	return 1;
}

int BirdMngSet(int count, int dirFlag, int level) {
	for (int i = 0; i < 10; i++) {
		if (!bird[i].GetExistFlag()) {
			bird[i].Set(count, dirFlag, level);
			return 0;
		}
	}
	return 1;
}

int EnemyMngInitialize() {
	Decoi = LoadGraph("images/docoi.png");
	SlimeMngInitialize();
	BirdMngInitialize();
	return 0;
}
int EnemyMngSet(int levelFlag, int count, Dot girl) {

	switch (count)
	{
	case 10:
		SlimeMngSet(count, 1, 0);
		SlimeMngSet(count, 1, 1);
		break;
	case 100:
		SlimeMngSet(count, 1, 1);
		break;
	case 200:
		BirdMngSet(count, 1, 0);
		break;
	case 450:
		BirdMngSet(count, 1, 1);
		break;
	default:
		break;
	}

	for (int i = 0; i < 10; i++) {
		if ((count - slime[i].GetStartClock()) % 150 == 0 &&
			count != 0 && slime[i].GetStateFlag() == 0) {
			if (slime[i].GetExistFlag()) {
				//printfDx("JUMP!!!");
				slime[i].SetJump(count);
			}
		}
		if ((count - bird[i].GetStartClock()) % 200 == 90 &&
			count != 0 && bird[i].GetStateFlag() == 0 &&
			bird[i].GetCenter().Get_x() < DISP_WIDTH &&
			bird[i].GetCenter().Get_x() > bird[i].GetWidth()) {
			if (bird[i].GetExistFlag())bird[i].SetAttack(count, girl);
		}
	}
	return 0;
}
int EnemyMngUpdata(int count) {
	for (int i = 0; i < 10; i++) {
		//if (box[i].GetExistFlag()) box[i].Draw();
		//if (fence[i].GetExistFlag()) fence[i].Draw();
		if (slime[i].GetExistFlag()) slime[i].Updata(count);
		if (bird[i].GetExistFlag()) bird[i].Updata(count);
	}
	return 0;
}
int EnemyMngJudge(Player* player, Princess* girl,int count) {
	//if (player->GetAttack() > 0 && 
	//	(*girl).GetStateFlag() != 1 && 
	//	(*player).GetAttackArea() & (*girl).GetWeekArea()) {
	//	//frendly fire!
	//	//プレイヤーは殴るモード、姫は殴られるモードで実際に当たったら
	//	(*girl).SetDamage((*player).GetAttack(), count);
	//}
	for (int i = 0; i < 10; i++) {
		//enemy is damaged!
		if (slime[i].GetExistFlag() &&
			slime[i].GetStateFlag() != 5 &&
			slime[i].GetStateFlag() != 6 &&
			player->GetAttack() &&
			slime[i].GetWeekArea() & (*player).GetAttackArea()) {//slime
			slime[i].SetDamage(count, player->GetAttack());
		}	
		if (bird[i].GetExistFlag() &&
			bird[i].GetStateFlag() != 5 &&
			bird[i].GetStateFlag() != 6 &&
			player->GetAttack() &&
			bird[i].GetWeekArea() & (*player).GetAttackArea()) {//birds
			bird[i].SetDamage(count, player->GetAttack());
		}
		//Princess is damaged!
		if (slime[i].GetExistFlag() &&
			slime[i].GetStateFlag() != 5 &&
			(*girl).GetStateFlag() != 1 &&
			slime[i].GetAttackArea() & (*girl).GetWeekArea()) {//slime
			//printfDx("HIT!!!!!\n");
			girl->SetDamage(slime[i].GetAttack(),count);
		}
		if (bird[i].GetExistFlag() &&
			bird[i].GetStateFlag() != 5 &&
			girl->GetStateFlag() != 1 &&
			bird[i].GetAttackArea() & girl->GetWeekArea()) {//birds
			girl->SetDamage(bird[i].GetAttack(),count);
		}
	}
	return 0;
}
int EnemyMngDraw() {
	for (int i = 0; i < 10; i++) {
		if (slime[i].GetExistFlag() && slime[i].GetStrength() == 2) slime[i].Draw();
		if (bird[i].GetExistFlag() && bird[i].GetStrength() == 2) bird[i].Draw();
	}
	for (int i = 0; i < 10; i++) {
		if (slime[i].GetExistFlag() && slime[i].GetStrength() == 1) slime[i].Draw();
		if (bird[i].GetExistFlag() && bird[i].GetStrength() == 1) bird[i].Draw();
	}
	for (int i = 0; i < 10; i++) {
		if (slime[i].GetExistFlag() && slime[i].GetStrength() == 0) {
			slime[i].Draw();
			//printfDx("DRAWING");
		}
		if (bird[i].GetExistFlag() && bird[i].GetStrength() == 0) bird[i].Draw();
	}
	//DrawFormatString(0, 280, RED, "SLIMEHP : %d,state : %d;position : %d,exist:%d,strength:%d", slime[0].GetHP(),slime[0].GetStateFlag(),slime[0].GetCenter().Get_x(),slime[0].GetExistFlag(),slime[0].GetStrength());
	//DrawFormatString(0, 280, RED, "BIRDHP : %d,state : %d,attack : %d", bird[0].GetHP(), bird[0].GetStateFlag(),bird[0].GetAttack());
	return 0;
}
