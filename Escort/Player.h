#ifndef PLAYER_H
#define PLAYER_H
#include"Chore.h"

class Player
{
public:
	Player();
	~Player();
	int Initialize();
	int Updata(int count);
	int End();

private:
	Dot center;			//中心座標
	Square weekArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	//int jump;			
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int acceptFlag;		//入力受付フラグ（1で受付）
};

Player::Player()
{
}

Player::~Player()
{
}

#endif // !PLAYER_H
