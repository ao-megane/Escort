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
	int GetExistFlag();
	int SetHP(int a);
	int SetAttack(int a);
	int GetHP();
	int GetAttack();
	int GetStartClock();
	int GetStateFlag();
	int GetBodyClock();
	Square GetWeekArea();
	Square GetAttackArea();
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
	int clockKeeper;	//��_�����̃J�E���g�L�[�p�[
	int startClock;		//�o��������
	int existFlag;		//����(����)�t���O
	int stateFlag;		//����ԃt���O
	int stateKeeper;
	int dirFlag;		//�����Ă�����t���O�i0�ō� 1�ŉE�j
	/*
	0 stand
	1 run
	2 attack
	3 jump
	4 happen
	5 damage
	6 disappper
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

//class Box :public Enemy
//{
//public:
//	int Initialize();
//	int Set(int count); //�o��������
//	int Updata(int count);
//	int SetStand();
//	int UpdataStand();
//	/*Box();
//	~Box();*/
//
//private:
//
//};
//
////Box::Box()
////{
////}
////
////Box::~Box()
////{
////}
//
//class Fence : public Enemy
//{
//public:
//	int Initialize();
//	int Set(int count); //�o��������
//	int Updata(int count);
//	int SetStand();
//	int UpdataStand();
//private:
//
//};

class Slime : public Enemy
{
public:
	int Initialize();
	int Set(int count,int position); //�o��������
	int SetStand(int count);
	int UpdataStand(int count);
	int SetJump(int count);
	int UpdataJump(int count);
	int SetDamage(int count, int damage);
	int UpdataDamage(int count);
	int SetDisapper(int count);
	int UpdataDisapper(int count);
	int Updata(int count);
private:
};

class Bird : public Enemy {
public:
	int Initialize();
	int Set(int count,int position); //�o��������
	int SetStand(int count);
	int UpdataStand(int count);
	int SetAttack(int count);
	int UpdataAttack(int count);
	int SetDisapper(int count);
	int UpdataDisapper(int count);
	int SetDamage(int count, int damage);
	int UpdataDamage(int count);
	int Updata(int count);
	int UpdataStand();
};

int EnemyMngInitialize();			//�摜�n���h������
int EnemyMngSet(int levelFlag,int stageFlag, int count);	//�X�e�[�W�A���Ԃ��Ƃɔz�u
int EnemyMngUpdata(int count);		//�ړ����A�j�����A�U���ɓ���̂�Judge�ōs��
int EnemyMngJudge(Player* player, Princess* girl,int count);	//����Astate�AHP���̍X�V
int EnemyMngDraw();

#endif // !ENEMYMNG_H
