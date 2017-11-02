#include"Princess.h"
#include"Value.h"

/*
int run1
int run2
*/
int walk1;
int walk2;
int walk3;
int walk4;
int walk5;

int Dwalk1;
int Dwalk2;
int Dwalk3; 
int Dwalk4;
int Dwalk5;

int PriDecoi;

int HPImage;
int HPBackImage;
int HealImage;
int DamageImage;

int Damage;
int Jump;

int DamageCount;

int Princess::Initialize() {
	HP = 100;
	/*
	run1 = LoadGraph("");
	run1 = LoadGraph("");
	*/
	walk1 = LoadGraph("images/Princess/walk/Resize/1.png");
	walk2 = LoadGraph("images/Princess/walk/Resize/2.png");
	walk3 = LoadGraph("images/Princess/walk/Resize/3.png");
	walk4 = LoadGraph("images/Princess/walk/Resize/4.png");
	walk5 = LoadGraph("images/Princess/walk/Resize/5.png");

	Dwalk1 = LoadGraph("images/Princess/damagewalk/Resize/1.png");
	Dwalk2 = LoadGraph("images/Princess/damagewalk/Resize/2.png");
	Dwalk3 = LoadGraph("images/Princess/damagewalk/Resize/3.png");
	Dwalk4 = LoadGraph("images/Princess/damagewalk/Resize/4.png");
	Dwalk5 = LoadGraph("images/Princess/damagewalk/Resize/5.png");

	HPImage = LoadGraph("images/Princess/HP.png");
	HPBackImage = LoadGraph("images/Princess/HPBack.png");
	HealImage = LoadGraph("images/Princess/Heal.png");
	DamageImage = LoadGraph("images/Princess/Damage.png");

	PriDecoi = LoadGraph("images/decoi.png");

	Damage = LoadSoundMem("music/damage2.wav");
	Jump = LoadSoundMem("music/jump1.wav");

	return 0;
}

int Princess::PlayDamage() {
	PlaySoundMem(Damage, DX_PLAYTYPE_BACK);
	return 0;
}
int Princess::PlayJump() {
	PlaySoundMem(Jump, DX_PLAYTYPE_BACK);
	return 0;
}

int Princess::SetHP(int a) {
	HP = a;
	return 0;
}

int Princess::Set(int levelFlag) {
	//if(levelFlag == 0)
	center.Set(DISP_WIDTH * 0.3, GROUND_HEIGHT - PRI_HEIGHT / 2);
	weak.Set(center, PRI_W_WIDTH, PRI_W_HEIGHT);
	Image = walk1;
	stateFlag = 0;
	HP = PRI_MAXHP; 
	Keeper = 0;
	DamageCount = 0;
	HPstate = 0;
	return 0;
}

int Princess::SetWalk() {
	stateFlag = 0;
	//Image = walk1;
	Keeper = 0;
	return 0;
}
int Princess::UpdataWalk(int count) {
	//int speed = GROUND_SPEED;
	center.Set(center.Get_x() + GROUND_SPEED - GROUND_SPEED,GROUND_HEIGHT - PRI_HEIGHT/2);
	int sum = 40;	//一周のフレーム数
	int num = 8;	//一周の画像数
	if (count % sum <= sum / num * 1) {
		Image =walk1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = walk2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = walk3;
	}
	else if (count % sum <= sum / num * 4) {
		Image = walk4;
	}
	else if (count % sum <= sum / num * 5) {
		Image = walk5;
	}
	else if (count % sum <= sum / num * 6) {
		Image = walk4;
	}
	else if (count % sum <= sum / num * 7) {
		Image = walk3;
	}
	else if (count % sum <= sum / num * 8) {
		Image = walk2;
	}
	return 0;
}

int Princess::SetJump(int count) {
	stateFlag = 2;
	Image = walk1;
	bodyClock = count;
	PlayJump();
	return 0;
}
int Princess::UpdataJump(int count) {
	double height = DISP_HEIGHT * 0.3;//jumpの高さ
	double sum = 60.0;	//モーションにかかるフレーム数
	int num = 5;	//絵の枚数
	double a = -sin((count / sum)*PI) * height;//ほしい山
	
	center.Set((center.Get_x()) - GROUND_SPEED + GROUND_SPEED, a + GROUND_HEIGHT - PRI_HEIGHT / 2);
	Image = walk1;
	if (count >= sum) {
		stateFlag = 0;
		//acceptFlag = 1;
		bodyClock = count;
		//SetWalk();
	}
	return 0;
}

int Princess::SetDamage(int damage,int count) {
	DamageCount = 0;
	if (stateFlag == 2) {
		Keeper = bodyClock + 30;//ダメージにかかる時間
		bodyClock = count;
	}
	else {
		Keeper = 0;
		bodyClock = count;
	}
	PlayDamage();
	stateFlag = 1;
	HP -= damage;
	//Image = P_run_1;
	return 0;
}
int Princess::UpdataDamage(int count) {
	center.Set(center.Get_x() + GROUND_SPEED - GROUND_SPEED);
	if (count >= 30) {
		if (Keeper != 0) {//jump
			bodyClock = Keeper;
			Keeper = 0;
			stateFlag = 2;//戻す
		}
		else {
			SetWalk();
		}
	}
	int sum = 30;	//一周のフレーム数
	int num = 8;	//一周の画像数
	if (count % sum <= sum / num * 1) {
		Image = Dwalk1;
	}
	else if (count % sum <= sum / num * 2) {
		Image = Dwalk2;
	}
	else if (count % sum <= sum / num * 3) {
		Image = Dwalk3;
	}
	else if (count % sum <= sum / num * 4) {
		Image = Dwalk4;
	}
	else if (count % sum <= sum / num * 5) {
		Image = Dwalk5;
	}
	else if (count % sum <= sum / num * 6) {
		Image = Dwalk4;
	}
	else if (count % sum <= sum / num * 7) {
		Image = Dwalk3;
	}
	else if (count % sum <= sum / num * 8) {
		Image = Dwalk2;
	}
	if (count % 3 == 0) Image = PriDecoi;
	return 0;
}

int Princess::Updata(int count,int PriJump) {
	//set
	DamageCount++;
	if (PriJump == 1 && stateFlag == 0 /*&& (center.Get_y() == GROUND_HEIGHT - PRI_HEIGHT / 2)*/) {
		SetJump(count);
	}
	if (DamageCount >= 120) {//回復
		if (HP < PRI_MAXHP && count % 2 == 0)HP++;
		if (HPstate == 2 || HPstate == 3) HPstate = 3;
		else HPstate = 1;
	}
	else if (HPstate == 2 || HPstate == 3) HPstate = 2;//回復してない
	else HPstate = 0;

	//updata
	switch (stateFlag)
	{
	case 0:
		UpdataWalk(count);
		break;
	case 1:
		UpdataDamage(count - bodyClock);
		break;
	case 2:
		UpdataJump(count - bodyClock);
		break;
	default:
		break;
	}

	weak.Set(center, PRI_W_WIDTH, PRI_W_HEIGHT);
	return 0;
}

int Princess::GetStateFlag() {
	return stateFlag;
}
int Princess::GetHP() {
	return HP;
}
Square Princess::GetWeekArea() {
	return weak;
}

Dot Princess::GetCenter() {
	return center;
}

int Princess::Draw() {

	/*DrawBox(
		center.Get_x() - PRI_WIDTH / 2, center.Get_y() - PRI_HEIGHT / 2,
		center.Get_x() + PRI_WIDTH / 2, center.Get_y() + PRI_HEIGHT / 2,
		GREEN, false);
	DrawBox(
		weak.Get_LU().Get_x(), weak.Get_LU().Get_y(),
		weak.Get_RD().Get_x(), weak.Get_RD().Get_y(),
		BLUE, false);*/

	DrawModiGraph(
		center.Get_x() - PRI_D_WIDTH / 2, center.Get_y() - PRI_D_HEIGHT / 2 + PRI_DIFF_H,
		center.Get_x() + PRI_D_WIDTH / 2, center.Get_y() - PRI_D_HEIGHT / 2 + PRI_DIFF_H,
		center.Get_x() + PRI_D_WIDTH / 2, center.Get_y() + PRI_D_HEIGHT / 2 + PRI_DIFF_H,
		center.Get_x() - PRI_D_WIDTH / 2, center.Get_y() + PRI_D_HEIGHT / 2 + PRI_DIFF_H,
		Image, true);

	DrawModiGraph(
		HPBAR_MARGIN_WIDTH, HPBAR_MARGIN_HEIGHT, HPBAR_MARGIN_WIDTH + HPBAR_WIDTH, HPBAR_MARGIN_HEIGHT,
		HPBAR_MARGIN_WIDTH + HPBAR_WIDTH, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT, HPBAR_MARGIN_WIDTH, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT, HPBackImage, true);
	if(HP > 0)
		DrawBox(
		HPSQU_MARGIN_WIDTH+HPBAR_MARGIN_WIDTH							, HPSQU_MARGIN_HEIGHT + HPBAR_MARGIN_HEIGHT, 
		HPSQU_MARGIN_WIDTH+HPBAR_MARGIN_WIDTH + HP / (double)(PRI_MAXHP) * HPSQU_WIDTH, HPSQU_MARGIN_HEIGHT + HPBAR_MARGIN_HEIGHT + HPSQU_HEIGHT, BLUE, true);
	DrawModiGraph(
		HPBAR_MARGIN_WIDTH, HPBAR_MARGIN_HEIGHT, HPBAR_MARGIN_WIDTH + HPBAR_WIDTH, HPBAR_MARGIN_HEIGHT,
		HPBAR_MARGIN_WIDTH + HPBAR_WIDTH, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT, HPBAR_MARGIN_WIDTH, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT, HPImage, true);

	if (HPstate == 1 || HPstate == 3) {
		DrawModiGraph(
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 60 * -1				, HPBAR_MARGIN_HEIGHT,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 60 * -1 + HPBAR_HEIGHT , HPBAR_MARGIN_HEIGHT,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 60 * -1 + HPBAR_HEIGHT , HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT ,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 60 * -1, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT , HealImage, true);
	}
	if (HPstate == 2 || HPstate == 3) {
		DrawModiGraph(
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 80 * -1 + HPBAR_HEIGHT, HPBAR_MARGIN_HEIGHT,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 80 * -1 + HPBAR_HEIGHT *2, HPBAR_MARGIN_HEIGHT,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 80 * -1 + HPBAR_HEIGHT *2, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT,
			HPBAR_MARGIN_WIDTH + HPBAR_WIDTH + 80 * -1 + HPBAR_HEIGHT, HPBAR_MARGIN_HEIGHT + HPBAR_HEIGHT, DamageImage, true);
	}

	//DrawFormatString(0, 300, RED, "PRIHPstate:%d,PRIstate:%d", HPstate, stateFlag);

	return 0;
}