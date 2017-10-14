#ifndef PLAYER_H
#define PLAYER_H
//#include"Chore.h"

class Player
{
public:
	Player();
	~Player();
	int Initialize();
	int Updata(int count);
	int End();

private:
	/*Dot center;
	Square weekArea;
	Square attackArea;*/
	int jump;
	int attack;
	int Image;
};

Player::Player()
{
}

Player::~Player()
{
}

#endif // !PLAYER_H
