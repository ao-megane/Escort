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
	int SetAttackval(int a);
	int GetHP();
	int GetAttack();
	int GetStartClock();
	int GetStateFlag();
	int GetBodyClock();
	int GetHeight();
	int GetWidth();
	int GetStrength();
	int PlayDamage();
	Dot GetCenter();
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
	int strength;		//����
	int dirFlag;		//�����Ă�����t���O�i1�ŉE 0�ō��j
	/*
	0 stand
	1 run
	2 attack
	3 jump
	4 happen
	5 damage
	6 disappper
	7 �U�����~(��)
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

class Slime : public Enemy
{
public:
	int Initialize();
	int Set(int count,int position,int strength); //�o��������
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
	int Set(int count,int position,int strength); //�o��������
	int SetStand(int count);
	int UpdataStand(int count);
	int SetAttack(int count,Dot princess);
	int UpdataAttack(int count);
	int SetDisapper(int count);
	int UpdataDisapper(int count);
	int SetDamage(int count, int damage);
	int UpdataDamage(int count);
	int SetBack(int count);
	int UpdataBack(int count);
	int Updata(int count);
	double birdAttackHigh;
	double birdAttackWidth;
};

int SlimeMngSet(int count,int dirFlag,int level);

int BirdMngSet(int count,int dirFlag,int level);

int EnemyMngInitialize();			//�摜�n���h������
int EnemyMngSet(int levelFlag, int count,Dot girl);	//�X�e�[�W�A���Ԃ��Ƃɔz�u
int EnemyMngUpdata(int count);		//�ړ����A�j�����A�U���ɓ���̂�Judge�ōs��
int EnemyMngJudge(Player* player, Princess* girl,int count);	//����Astate�AHP���̍X�V
int EnemyMngDraw();

#endif // !ENEMYMNG_H
