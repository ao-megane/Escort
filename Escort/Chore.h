#ifndef CHORE_H
#define CHORE_H

class Dot
{
public:
	Dot();
	~Dot();
	int Get_x();
	int Get_y();

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

private:
	Dot LU;
	Dot RU;
	Dot RD;
	Dot LD;
};

Square::Square()
{
}

Square::~Square()
{
}
#endif // !CHORE_H
