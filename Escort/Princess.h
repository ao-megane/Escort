#ifndef PRINCESS_H
#define PRINCESS_H

#include"Chore.h"

class Princess
{
public:/*
	Princess();
	~Princess();*/
	int Initialize();
	int Set();
	int SetRun();
	int UpdataRun(int count);
	int Updata(int count);
	int Draw();
	int End();

private:
	int HP;
	int Image;
	int stateFlag;	//��_�����Ƃ��ɖ��G�ɂ���t���O
	Dot center;
	Square week;
};
//
//Princess::Princess()
//{
//}
//
//Princess::~Princess()
//{
//}
//
//int PrincessInitialize();
//
//int SetPrincess();
//
//int UpdataPrincess(int count);
//
//int DrawPrincess();
//
//int EndPrincess();

#endif // !PRINCESS_H