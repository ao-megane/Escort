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
	Dot center;			//���S���W
	Square weekArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�
	//int jump;			
	int attack;			//���݂̍U����
	int Image;			//���݂̉摜
	int acceptFlag;		//���͎�t�t���O�i1�Ŏ�t�j
};

Player::Player()
{
}

Player::~Player()
{
}

#endif // !PLAYER_H
