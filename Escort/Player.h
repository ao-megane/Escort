#ifndef PLAYER_H
#define PLAYER_H

#include"Obj.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//�Q�[���J�n���i�摜�n���h�����Ӂj
	int Set();			//�v���C�J�n���i���W���Ӂj
	int SetRun();		//private��������֐�
	int UpdataRun(int count);//�_�b�V�����̍��W����������֐�
	int SetDash();
	int UpdataDash(int count);
	int SetStand();
	int UpdataStand(int count);
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
	int Draw();
	int End();

private:
	Dot center;			//���S���W
	Square weekArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�
	//int jump;			
	int attack;			//���݂̍U����
	int Image;			//���݂̉摜
	int acceptFlag;		//���͎�t�t���O�i1�Ŏ�t�j
	int stateFlag;		//����ԃt���O
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
	int bodyClock;		//�A�j���[�V�����p�̓����v
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