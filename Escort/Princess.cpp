#include"Princess.h"
#include"Value.h"

/*
int run1
int run2
*/
int walk1;

int Damage;
int Jump;

int Princess::Initialize() {
	HP = 100;
	/*
	run1 = LoadGraph("");
	run1 = LoadGraph("");
	*/
	walk1 = LoadGraph("images/Princess/walk/1.png");
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
	HP = 100; 
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

	if (count % 60 <= 10) {
		//Image = P_run_1;
	}
	else if (count % 60 <= 20) {
		//Image = P_run_2;
	}
	else if (count % 60 <= 30) {
		//Image = P_run_3;
	}
	else if (count % 60 <= 40) {
		//Image = P_run_4;
	}
	else if (count % 60 <= 50) {
		//Image = P_run_5;
	}
	else if (count % 60 <= 60) {
		//Image = P_run_6;
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
	//if (count % 60 <= 10) {
	//	//Image = P_run_1;
	//}
	//else if (count % 60 <= 20) {
	//	//Image = P_run_2;
	//}
	//else if (count % 60 <= 30) {
	//	//Image = P_run_3;
	//}
	//else if (count % 60 <= 40) {
	//	//Image = P_run_4;
	//}
	//else if (count % 60 <= 50) {
	//	//Image = P_run_5;
	//}
	//else if (count % 60 <= 60) {
	//	//Image = P_run_6;
	//}
	return 0;
}

int Princess::Updata(int count,int Pstate) {
	//set
	if (Pstate == 8 && stateFlag == 0) {
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

	DrawBox(40, 40, 1040, 80, BLUE, false);
	DrawBox(40, 40, 40 + HP * 10, 80, BLUE, true);

	//DrawFormatString(0, 40, RED, "PRIHP:%d,PRIstate:%d", HP, stateFlag);

	return 0;
}