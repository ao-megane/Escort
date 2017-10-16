#include "EnemyMng.h"
#include "Value.h"
#include "DxLib.h"


Box box[2];
Fence fence[2];

int Enemy::Draw() {

	DrawBox(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		GREEN, false);
	DrawBox(
		weekArea.Get_LU().Get_x(), weekArea.Get_LU().Get_y(),
		weekArea.Get_RD().Get_x(), weekArea.Get_RD().Get_y(),
		BLUE, false);

	DrawModiGraph(
		center.Get_x() - width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() - height / 2,
		center.Get_x() + width / 2, center.Get_y() + height / 2,
		center.Get_x() - width / 2, center.Get_y() + height / 2,
		Image, true);
	//DrawFormatString(0, 0, RED, "E_state : %d", stateFlag);

	return 0;
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
	center.Set(1000, 1000);
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

