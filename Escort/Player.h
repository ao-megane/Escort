#ifndef PLAYER_H
#define PLAYER_H

#include"Chore.h"

class Player{

public:/*
	Player();
	~Player();*/
	int Initialize();	//�Q�[���J�n���i�摜�n���h�����Ӂj
	int Set();			//�v���C�J�n���i���W���Ӂj
	int SetRun();	//private��������֐�
	int UpdataRun(int count);//�_�b�V�����̍��W����������֐�
	int Updata(int count,int key[]);
	int Draw();
	int End();

private:
	Dot center;			//���S���W
	Square weekArea;	//��_���͈�
	Square attackArea;	//�^�_���͈�
	int jump;			
	int attack;			//���݂̍U����
	int Image;			//���݂̉摜
	int acceptFlag;		//���͎�t�t���O�i1�Ŏ�t�j
	int stateFlag;		//����ԃt���O(1�Ń_�b�V��)
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