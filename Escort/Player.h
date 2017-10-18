#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//ゲーム開始時（画像ハンドル周辺）
	int Set();			//プレイ開始時（座標周辺）
	int SetStand();		//privateをいじる関数
	int UpdataStand(int count);//ダッシュ中の座標やらをいじる関数
	int SetWalk();		
	int UpdataWalk(int count);
	int SetDash();
	int UpdataDash(int count);
	int SetGuard();
	int UpdataGuard(int count);
	int SetJump();
	int UpdataJump(int count);
	int SetAttack_w();
	int UpdataAttack_w(int count);
	int SetAttack_s();
	int UpdataAttack_s(int count);
	int SetAttack_l();
	int UpdataAttack_l(int count);
	int Updata(int count,int key[]);
	int GetStateFlag();
	Square GetAttackArea();
	int GetAttack();
	int Draw();
	int End();

private:
	Dot center;			//中心座標
	Square weekArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	//int jump;			
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int bodyClock;		//アニメーション用体内時計
	int isRightFlag;	//向いてる方向フラグ（0で左 1で右）
	int acceptFlag;		//入力受付フラグ（1で受付）
	int stateFlag;		//現状態フラグ
	/*
	0 stand
	1 run
	2 dash
	3 guard
	4 jump
	5 attack_strong
	6 attack_week
	7 attack_long
	*/
	
};
//
//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}

#endif // !PLAYER_H