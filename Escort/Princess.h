#ifndef PRINCESS_H
#define PRINCESS_H

#include"Chore.h"

class Princess
{
public:/*
	Princess();
	~Princess();*/
	int Initialize();
	int Set(int levelFlag);
	int SetWalk();
	int UpdataWalk(int count);
	int SetDamage(int damage,int count);	//�悻���牣����
	int UpdataDamage(int count);			//���[�V�����p
	int Updata(int count);
	int GetStateFlag();
	int GetHP();
	Square GetWeekArea();
	int Draw();
	int End();

private:
	int HP;
	int Image;
	int stateFlag;	//��_�����Ƃ��ɖ��G�ɂ���t���O
	int bodyClock;	//�A�j���[�V�����p�̓����v
	/*
	0 walk
	1 ��_��
	2 (Jump)
	*/
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