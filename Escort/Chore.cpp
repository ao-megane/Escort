#include"Chore.h"

int Dot::Set(int a, int b) {
	x = a;
	y = b;
	return 0;
}

int Dot::Get_x() {
	return x;
}

int Dot::Get_y() {
	return y;
}

void Dot::operator = (Dot d) {
	x = d.Get_x();
	y = d.Get_y();
}

Dot Dot::operator - (Dot d) {
	Dot a;
	a.x -= d.Get_x();
	a.y -= d.Get_y();
	return a;
};

/***************************************************************/

int Square::Set(Dot a, Dot b) {
	LU = a;
	RD = b;
}
int Square::Set(Dot a, int w, int h) {
	LU.Set(a.Get_x() - w / 2, a.Get_y() - h / 2);
	RD.Set(a.Get_x() + w / 2, a.Get_y() + h / 2);
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

void Square::operator - (Dot a) {
	Set(LU - a, RD - a);
};
bool Square::operator & (Square a) {
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return “–‚½‚Á‚Ä‚È‚¢
	if (RD.Get_x() < a.Get_LU().Get_x() || LU.Get_x() > a.RD.Get_x() ||
		LU.Get_y() < a.Get_RD().Get_y() || RD.Get_y() < a.LU.Get_y())
		return false;
	else
		return true;
};