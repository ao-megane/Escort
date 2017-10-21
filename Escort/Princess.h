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
	int SetDamage(int damage,int count);	//よそから殴られる
	int UpdataDamage(int count);			//モーション用
	int Updata(int count);
	int GetStateFlag();
	int GetHP();
	Square GetWeekArea();
	int Draw();
	int End();

private:
	int HP;
	int Image;
	int stateFlag;	//被ダメ中とかに無敵にするフラグ
	int bodyClock;	//アニメーション用体内時計
	/*
	0 walk
	1 被ダメ
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