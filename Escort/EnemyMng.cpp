#include "EnemyMng.h"
#include "Value.h"
#include "DxLib.h"

int Enemy::Draw() {

	DrawBox(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		GREEN, false);
	DrawBox(
		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
		BLUE, false);

	/*DrawModiGraph(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		center.Get_x() - width / 2, center.Get_y() + height / 2,
		Image, true);*/
	DrawModiGraph(
		center.Get_x() + width / 2, center.Get_y() - height / 2,
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() - width / 2, center.Get_y() + height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		Image, true);
	return 0;
}
int Enemy::GetExistFlag() {
	return existFlag;
}

int Box_1;
int Box_breaked_1;
int Box::Initialize() {
	//Box_1 = LoadGraph("images/Enemy/Box/1.png");
	width = BOX_WIDTH;
	height = BOX_HEIGHT;

	center.Set(0);
	weekArea.Set(center, center);
	attack = 0;
	Image = Box_1;
	existFlag = 0;
	stateFlag = 0;

	return 0;
}
int Box::Set(int count) {
	center.Set(1000, GROUND_HEIGHT - height / 2);
	weekArea.Set(center, width, height);
	starClock = count;
	return 0;
}
int Box::SetStand() {
	Image = Box_1;
	return 0;
}
int Box::UpdataStand() {
	center.Set(center.Get_x() - 1);
	return 0;
}

int Box::Updata(int count) {
	switch (stateFlag)
	{
	default:
		break;
	}
	weekArea.Set(center, width, height);
	return 0;
}


int Fence_1;
int Fence_breaked_1;
int Fence::Initialize() {
	//Box_1 = LoadGraph("images/Enemy/Box/1.png");
	width = FENCE_WIDTH;
	height = FENCE_HEIGHT;

	center.Set(0);
	weekArea.Set(center, center);
	attack = 0;
	Image = Fence_1;
	existFlag = 0;
	stateFlag = 0;

	return 0;
}
int Fence::Set(int count) {
	center.Set(1000, GROUND_HEIGHT - height / 2);
	weekArea.Set(center, width, height);
	starClock = count;
	return 0;
}
int Fence::SetStand() {
	Image = Fence_1;
	return 0;
}
int Fence::UpdataStand() {
	center.Set(center.Get_x() - 1);
	return 0;
}

int Fence::Updata(int count) {
	switch (stateFlag)
	{
	default:
		break;
	}
	weekArea.Set(center, width, height);
	return 0;
}

int SlimeStand1;
int SlimeJump1;
int Slime::Initialize() {
	SlimeStand1 = LoadGraph("images/Slime/stand/1.png");
	SlimeJump1 = LoadGraph("images/Slime/stand/1.png");
	existFlag = 0;
	width = SLIME_WIDTH;
	height = SLIME_HEIGHT;
	return 0;
}
int Slime::Set(int count) {
	center.Set(DISP_WIDTH - SLIME_WIDTH, GROUND_HEIGHT - SLIME_HEIGHT / 2);
	weekArea.Set(center, width, height);
	Image = SlimeStand1;
	bodyClock = count;
	existFlag = 1;
	return 0;
}
int Slime::SetStand(int count) {
	stateFlag = 0;
	bodyClock = count;
	return 0;
}
int Slime::UpdataStand(int count) {
	center.Set(center.Get_x() - GROUND_SPEED, center.Get_y());
	int sum = 40;	//一周のフレーム数
	int num = 4;	//一周の画像数
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
	return 0;
}
int Slime::SetJump(int count) {
	stateFlag = 3;
	bodyClock = count;
	return 0;
}
int Slime::UpdataJump(int count) {
	double height = DISP_HEIGHT * 0.5;//jumpの高さ
	double sum = 30.0;	//モーションにかかるフレーム数
	int num = 5;	//絵の枚数
	double a = -sin((count / sum)*PI) * height;//ほしい山
	center.Set((center.Get_x()) - GROUND_SPEED + 0, a + GROUND_HEIGHT - SLIME_HEIGHT / 2);
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
	if (count >= sum) {
		stateFlag = 0;
		//acceptFlag = 1;
		bodyClock = count;
	}
	return 0;
}
int Slime::Updata(int count) {
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
	//case 5:
	//	//UpdataAttack_s(count - bodyClock);
	//	break;
	//case 6:
	//	UpdataAttack_w(count - bodyClock);
	//	break;
	//case 7:
	//	//UpdataAttack_l(count - bodyClock);
	//	break;
	default:
		break;
	}

	weekArea.Set(center, SLIME_WIDTH*0.8, SLIME_HEIGHT*0.8);
	return 0;
}

int BirdStand1;
int Bird::Initialize() {
	BirdStand1 = LoadGraph("images/Bird/stand/1.png");
	existFlag = 0;
	width = BIRD_WIDTH;
	height = BIRD_HEIGHT;
	return 0;
}
int Bird::Set(int count) {
	center.Set(DISP_WIDTH - BIRD_WIDTH, GROUND_HEIGHT - BIRD_HEIGHT / 2 - 1000);
	weekArea.Set(center, width, height);
	Image = BirdStand1;
	bodyClock = count;
	existFlag = 1;
	return 0;
}
int Bird::SetStand(int count) {
	stateFlag = 0;
	bodyClock = count;
	return 0;
}
int Bird::UpdataStand(int count) {
	center.Set(center.Get_x() - GROUND_SPEED, center.Get_y());
	int sum = 40;	//一周のフレーム数
	int num = 4;	//一周の画像数
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
	return 0;
}
int Bird::Updata(int count) {
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
		//UpdataJump(count - bodyClock);
		break;
		//case 4:
		//	UpdataHappen(count - bodyClock);
		//	break;
		//case 5:
		//	//UpdataAttack_s(count - bodyClock);
		//	break;
		//case 6:
		//	UpdataAttack_w(count - bodyClock);
		//	break;
		//case 7:
		//	//UpdataAttack_l(count - bodyClock);
		//	break;
	default:
		break;
	}

	//weekArea.Set(center, BIRD_WIDTH*0.8, BIRD_HEIGHT*0.8);
	weekArea.Set(center, 300, 300);
	return 0;
}

Box box[2];
Fence fence[2];
Slime slime[2];
Bird bird[2];
int EnemyMngInitialize() {
	for (int i = 0; i < 2; i++) {
		//box[i].Initialize();
		//fence[i].Initialize();
		slime[i].Initialize();
		bird[i].Initialize();
	}
	return 0;
}
int EnemyMngSet(int levelFlag,int stageFlag, int count) {
	if (count == 30) {
		slime[0].Set(count);
		bird[0].Set(count);
	}
	if (count % 60 == 0 && count != 0) {
		slime[0].SetJump(count);
		//printfDx("JUMP!!");
	}
	return 0;
}
int EnemyMngUpdata(int count) {
	for (int i = 0; i < 2; i++) {
		//if (box[i].GetExistFlag()) box[i].Draw();
		//if (fence[i].GetExistFlag()) fence[i].Draw();
		if (slime[i].GetExistFlag()) slime[i].Updata(count);
		if (bird[i].GetExistFlag()) bird[i].Updata(count);
	}
	return 0;
}
int EnemyMngJudge(Player* player, Princess* girl,int count) {
	//DrawFormatString(0, 80, RED, "NONHIT");
	if ((*player).GetStateFlag() == 6 && (*girl).GetStateFlag() != 1 && (*player).GetAttackArea() & (*girl).GetWeekArea()) {
		//プレイヤーは殴るモード、姫は殴られるモードで実際に当たったら
		//DrawFormatString(0, 80, RED, "HIT!!");
		(*girl).SetDamage((*player).GetAttack(), count);
		//姫にダメージ処理
	}
	return 0;
}
int EnemyMngDraw() {
	//slime[0].Draw();
	for (int i = 0; i < 2; i++) {
		//if (box[i].GetExistFlag()) box[i].Draw();
		//if (fence[i].GetExistFlag()) fence[i].Draw();
		if (slime[i].GetExistFlag()) slime[i].Draw();
		if (bird[i].GetExistFlag()) bird[i].Draw();
	}
	return 0;
}

