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

int Damage;
int Jump;

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

int Princess::Set(int levelFlag) {
	//if(levelFlag == 0)
	center.Set(DISP_WIDTH * 0.3, GROUND_HEIGHT - PRI_HEIGHT / 2);
	week.Set(center, PRI_WIDTH * 0.5, PRI_HEIGHT * 0.5);
	Image = walk1;
	stateFlag = 0;
	HP = 1000; 
	Keeper = 0;
	return 0;
}

int Princess::SetWalk() {
	stateFlag = 0;
	Image = walk1;
	Keeper = 0;
	return 0;
}
int Princess::UpdataWalk(int count) {
	//int speed = GROUND_SPEED;
	center.Set(center.Get_x() + GROUND_SPEED - GROUND_SPEED);

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
	//acceptFlag = 1;	//空中制動
	return 0;
}
int Princess::UpdataJump(int count) {
	double height = DISP_HEIGHT * 0.3;//jumpの高さ
	double sum = 60.0;	//モーションにかかるフレーム数
	int num = 5;	//絵の枚数
	double a = -sin((count / sum)*PI) * height;//ほしい山
	
	center.Set((center.Get_x()) - GROUND_SPEED + GROUND_SPEED, a + GROUND_HEIGHT - PRI_HEIGHT / 2);

	if (count >= sum) {
		stateFlag = 0;
		//acceptFlag = 1;
		bodyClock = 0;
		SetWalk();
	}
	return 0;
}

int Princess::SetDamage(int damage,int count) {
	if (stateFlag == 2) {
		Keeper = count + 60;
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
	if (count >= 60) {
		if (Keeper != 0) {//jump
			bodyClock = Keeper;
			Keeper = 0;
			stateFlag = 2;//戻す
		}
		else {
			SetWalk();
		}
	}
	int sum = 40;	//一周のフレーム数
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
		//Image = PriDecoi;
	}
	else if (count % sum <= sum / num * 5) {
		Image = Dwalk5;
		//Image = PriDecoi;
	}
	else if (count % sum <= sum / num * 6) {
		Image = Dwalk4;
		//Image = PriDecoi;
	}
	else if (count % sum <= sum / num * 7) {
		//Image = Dwalk3;
		Image = PriDecoi;
	}
	else if (count % sum <= sum / num * 8) {
		Image = Dwalk2;
	}
	if (count % 3 == 0) Image = PriDecoi;
	return 0;
}

int Princess::Updata(int count,int PriJump) {
	//set
	if (PriJump == 1 && stateFlag == 0) {
		SetJump(count);
	}

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

	week.Set(center, PRI_WIDTH*0.5, PRI_HEIGHT*0.5);
	return 0;
}

int Princess::GetStateFlag() {
	return stateFlag;
}
int Princess::GetHP() {
	return HP;
}
Square Princess::GetWeekArea() {
	return week;
}

Dot Princess::GetCenter() {
	return center;
}

int Princess::Draw() {

	DrawBox(
		center.Get_x() - PRI_WIDTH / 2, center.Get_y() - PRI_HEIGHT / 2,
		center.Get_x() + PRI_WIDTH / 2, center.Get_y() + PRI_HEIGHT / 2,
		GREEN, false);
	DrawBox(
		week.Get_LU().Get_x(), week.Get_LU().Get_y(),
		week.Get_RD().Get_x(), week.Get_RD().Get_y(),
		BLUE, false);

	DrawModiGraph(
		center.Get_x() - PRI_WIDTH / 2, center.Get_y() - PRI_HEIGHT / 2,
		center.Get_x() + PRI_WIDTH / 2, center.Get_y() - PRI_HEIGHT / 2,
		center.Get_x() + PRI_WIDTH / 2, center.Get_y() + PRI_HEIGHT / 2,
		center.Get_x() - PRI_WIDTH / 2, center.Get_y() + PRI_HEIGHT / 2,
		Image, true);

	//DrawFormatString(0, 40, RED, "PRIHP:%d,PRIstate:%d", HP, stateFlag);

	return 0;
}