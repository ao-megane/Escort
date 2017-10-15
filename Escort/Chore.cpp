#include"Chore.h"

int Dot::Set(int a, int b) {
	x = a;
	y = b;
	return 0;
}
int Dot::Set(int a) {
	x = a;
	//y = a;
	return 0;
}

int Dot::Get_x() {
	return x;
}

int Dot::Get_y() {
	return y;
}

/***************************************************************/

int Square::Set(Dot a, Dot b) {
	LU = a;
	RD = b;
	return 0;
}
int Square::Set(Dot a, int w, int h) {
	LU.Set(a.Get_x() - w / 2, a.Get_y() - h / 2);
	RD.Set(a.Get_x() + w / 2, a.Get_y() + h / 2);
	return 0;
}

int Square::Get_up() {
	return LU.Get_y();
}
int Square::Get_left() {
	return LU.Get_x();
}
Dot Square::Get_LU() {
	return LU;
}
Dot Square::Get_RD() {
	return RD;
}

/*******************************************/

int 