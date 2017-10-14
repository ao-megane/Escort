#ifndef CHORE_H
#define CHORE_H

class Dot
{
public:
	Dot();
	~Dot();
	int Set(int x,int y);			//左上、右下
	//Dot Get(); //渡せてるやんけ
	int Get_x();
	int Get_y();
	
	void operator = (Dot d) {};		//Dotの代入
	Dot operator - (Dot d) {};		//Dotの平行移動

private:
	int x;
	int y;
};

Dot::Dot()
{
}

Dot::~Dot()
{
}

class Square
{
public:
	Square();
	~Square();
	int Set(Dot a, Dot b);
	int Get_up();
	int Get_left();
	Dot Get_LU();
	Dot Get_RD();
	void operator - (Dot a) {};		//Squareの平行移動
	bool operator & (Square a) {};	//あたり判定演算子　true で重なってる

private:
	Dot LU;
	Dot RD;
};

Square::Square()
{
}

Square::~Square()
{
}
#endif // !CHORE_H
