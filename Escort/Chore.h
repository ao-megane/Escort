#ifndef CHORE_H
#define CHORE_H

class Dot{
public:/*
	Dot();
	~Dot();*/
	int Set(int x);
	int Set(int x,int y);			//左上、右下
	//Dot Get(); //渡せてるやんけ
	int Get_x();
	int Get_y();
	
	void operator = (Dot d) {		//Dotの代入
		x = d.Get_x();
		y = d.Get_y();
	};		
	Dot operator - (Dot d) {		//Dotの平行移動
		Dot a;
		a.x -= d.Get_x();
		a.y -= d.Get_y();
		return a;
	};		
private:
	int x;
	int y;
};
//
//Dot::Dot()
//{
//}
//
//Dot::~Dot()
//{
//}

class Square{
public:/*
	Square();
	~Square();*/
	int Set(Dot a, Dot b);
	int Set(Dot a, int w, int h);
	int Get_up();
	int Get_left();
	Dot Get_LU();
	Dot Get_RD();
	void operator - (Dot a) {		//Squareの平行移動
		Set(LU - a, RD - a);
	};		
	bool operator & (Square a) {	//あたり判定演算子　true で重なってる
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Get_x() < a.Get_LU().Get_x() || LU.Get_x() > a.RD.Get_x() ||
			LU.Get_y() < a.Get_RD().Get_y() || RD.Get_y() < a.LU.Get_y())
			return false;
		else
			return true;
	};	

private:
	Dot LU;
	Dot RD;
};
//
//Square::Square()
//{
//}
//
//Square::~Square()
//{
//}

#endif // !CHORE_H
