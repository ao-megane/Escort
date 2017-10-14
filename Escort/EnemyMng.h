#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"

class Enemy
{
public:
	Enemy();
	~Enemy();
	int Initialze();
	int Set();
	int Updata(int count);
	int Draw();
	int End();

private:
	Square weedArea;
	Square attackArea;
	int HP;
	int attack;
	int image;
};

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

#endif // !ENEMYMNG_H
