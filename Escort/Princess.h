#ifndef PRINCESS_H
#define PRINCESS_H

#include"Chore.h"

class Princess
{
public:/*
	Princess();
	~Princess();*/
	int Initialize();
	int PlayDamage();
	int PlayJump();
	int Set(int levelFlag);
	int SetWalk();
	int UpdataWalk(int count);
	int SetJump(int count);
	int UpdataJump(int count);
	int SetDamage(int damage,int count);	//よそから殴られる
	int UpdataDamage(int count);			//モーション用
	int Updata(int count,int Pstate);
	int GetStateFlag();
	int GetHP();
	int SetHP(int a);
	Square GetWeekArea();
	Dot GetCenter();
	int Draw();
	int End();
	int Keeper;

private:
	int HP;
	int Image;
	int stateFlag;	//被ダメ中とかに無敵にするフラグ
	int bodyClock;	//アニメーション用体内時計
	/*
	0 walk
	1 被ダメ
	2 Jump
	*/
	Dot center;
	Square weak;
};
//
//Princess::Princess()
//{
//}
//
//Princess::~Princess()
//{
//}

#endif // !PRINCESS_H