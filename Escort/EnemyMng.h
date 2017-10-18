#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Player.h"
#include"Princess.h"

class Enemy
{
public:
	/*Enemy();
	~Enemy();*/
	//int Updata(int count);	//�L�������Ƃɍ��
	int Draw();			//�`��
	//int End();

protected:
	Dot center;			//���S���W
	Square weekArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�
	int HP;				//HP
	int attack;			//���݂̍U����
	int Image;			//���݂̉摜
	int width;
	int height;
	int bodyClock;		//�A�j���[�V�����p�̓����v
	int starClock;		//�o��������
	int existFlag;		//����(����)�t���O
	int stateFlag;		//����ԃt���O
	/*
	0 stand
	1 run
	2 attack
	3 disappper
	*/
};
//
//Enemy::Enemy()
//{
//}
//
//Enemy::~Enemy()
//{
//}

class Box :public Enemy
{
public:
	int Initialize();
	int Set(int count); //�o��������
	int Updata(int count);
	int SetStand();
	int UpdataStand();
	/*Box();
	~Box();*/

private:

};

//Box::Box()
//{
//}
//
//Box::~Box()
//{
//}

class Fence : public Enemy
{
public:
	int Initialize();
	int Set(int count); //�o��������
	int Updata(int count);
	int SetStand();
	int UpdataStand();
private:

};

class Slime : public Enemy
{
public:

private:

};

int EnemyMngInitialize();			//�摜�n���h������
int EnemyMngSet(int stageFlag, int count);	//�X�e�[�W�A���Ԃ��Ƃɔz�u
int EnemyMngUpdata(int count);		//�ړ����A�j�����A�U���ɓ���̂�Judge�ōs��
int EnemyMngJudge(Player* player, Princess* girl,int count);	//����Astate�AHP���̍X�V
int EnemyMngDraw();

#endif // !ENEMYMNG_H
