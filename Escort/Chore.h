#ifndef CHORE_H
#define CHORE_H

class Dot
{
public:
	Dot();
	~Dot();
	int Set(int x,int y);			//����A�E��
	//Dot Get(); //�n���Ă���
	int Get_x();
	int Get_y();
	
	void operator = (Dot d) {};		//Dot�̑��
	Dot operator - (Dot d) {};		//Dot�̕��s�ړ�

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
	void operator - (Dot a) {};		//Square�̕��s�ړ�
	bool operator & (Square a) {};	//�����蔻�艉�Z�q�@true �ŏd�Ȃ��Ă�

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
