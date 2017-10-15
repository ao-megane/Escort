#ifndef PLAYER_H
#define PLAYER_H

#include"Chore.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//ゲーム開始時（画像ハンドル周辺）
	int Set();			//プレイ開始時（座標周辺）
	int SetRun();		//privateをいじる関数
	int UpdataRun(int count);//ダッシュ中の座標やらをいじる関数
	int SetDash();
	int UpdataDash(int count);
	int SetStand();
	int UpdataStand(int count);
	int Updata(int count,int key[]);
	int Draw();
	int End();

private:
	Dot center;			//中心座標
	Square weekArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	//int jump;			
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int acceptFlag;		//入力受付フラグ（1で受付）
	int stateFlag;		//現状態フラグ
	/*
	0 stand
	1 run
	2 dash
	*/
	int bodyClock;		//アニメーション用体内時計
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