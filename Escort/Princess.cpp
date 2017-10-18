#include"Princess.h"
#include"Value.h"

/*
int run1
int run2
*/

int Princess::Initialize() {
	HP = 100;
	/*
	run1 = LoadGraph("");
	run1 = LoadGraph("");
	*/

	return 0;
}

int Princess::Set() {
	center.Set(200, GROUND_HEIGHT - PRI_HEIGHT / 2);
	week.Set(center, PRI_WIDTH, PRI_HEIGHT);
	return 0;
}

int Princess::SetRun() {
	stateFlag = 1;
	//Image = P_run_1;

	return 0;
}
int Princess::UpdataRun(int count) {
	center.Set(center.Get_x() + 0);
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


int Princess::Updata(int count) {
	//UpdataRun(count);
	switch (stateFlag)
	{
	case 0:
		//UpdataStand(count - bodyClock);
		break;
	case 1:
		UpdataRun(count);
		break;
	case 2:
		//UpdataDash(count - bodyClock);
	default:
		break;
	}

	week.Set(center, PRI_WIDTH*0.8, PRI_HEIGHT*0.8);
	return 0;
}

int Princess::Draw() {

	DrawBox(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		GREEN, false);
	DrawBox(
		week.Get_LU().Get_x(), week.Get_LU().Get_y(),
		week.Get_RD().Get_x(), week.Get_RD().Get_y(),
		BLUE, false);

	DrawModiGraph(
		center.Get_x() - P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() - P_HEIGHT / 2,
		center.Get_x() + P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		center.Get_x() - P_WIDTH / 2, center.Get_y() + P_HEIGHT / 2,
		Image, true);

	return 0;
}
//
//Princess girl;
//int PrincessInitialize() {
//	girl.Initialize();
//	return 0;
//}
//int SetPrincess() {
//	girl.Set();
//	return 0;
//}
//int UpdataPrincess(int count) {
//	girl.Updata(count);
//	return 0;
//}
//int DrawPrincess() {
//	girl.Draw();
//	return 0;
//}
//int EndPrincess() {
//	return 0;
//}