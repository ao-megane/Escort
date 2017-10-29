#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);
const int BROWN = GetColor(46, 33, 13);

#define A (Key[0])
#define B (Key[1])
#define X (Key[2])
#define Y (Key[3])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trig������Z���n�߂�
#define L_TRIG (Key[7]) //Trig������Z���n�߂�
#define THUMB_Y (Key[8])//-100�`+100 100���ő�l
#define THUMB_X (Key[9]) //-100�`+100 100���ő�l
#define PAUSE (Key[10])

const int Trig = 200; //R2L2�̃J�E���g���n�߂邵�����l
const int ThumbTrig = 16383; //thumb�̖�������͈� �`32767

const int DISP_WIDTH = 2160;
const int DISP_HEIGHT = 1440;

const int GROUND_HEIGHT = 1440 - 50;
const int GROUND_SPEED = 1;

const int P_WIDTH = 200;	//�v���C���[���̂̕�
const int P_HEIGHT = 300;	//�v���C���[���̂̍����i2:3�j
const double P_W_WIDTH = P_WIDTH * 0.8;
const double P_W_HEIGHT = P_HEIGHT * 0.8;//��_������̑傫��
//������n ���`��n
const double P_D_WIDTH = 3000 / 1000 * P_WIDTH;//500
const double P_D_HEIGHT = 3000 / 1500 * P_HEIGHT;// 500
const double P_DIFF_H = (450 + 1500 / 2 - 3000 / 2) * P_D_WIDTH / 3000;//PH*�匳�̔䗦


const int PRI_WIDTH = 200;	//�v���C���[���̂̕�
const int PRI_HEIGHT = 300;	//�v���C���[���̂̍����i2:3�j
const double PRI_W_WIDTH = PRI_WIDTH * 0.8;
const double PRI_W_HEIGHT = PRI_HEIGHT * 0.8;//��_������̑傫��
//������n ���`��n
const double PRI_D_WIDTH = 3000 / 1000 * PRI_WIDTH;//500
const double PRI_D_HEIGHT = 3000 / 1500 * PRI_HEIGHT;// 500
const double PRI_DIFF = (450 + 1500 / 2 - 3000 / 2) * PRI_D_WIDTH / 3000;//PH*�匳�̔䗦

const int SLIME_WIDTH = 100;	//�v���C���[���̂̕�
const int SLIME_HEIGHT = 100;	//�v���C���[���̂̍����i2:3�j
const double SLIME_W_WIDTH = SLIME_WIDTH * 0.8;
const double SLIME_W_HEIGHT = SLIME_HEIGHT * 0.8;//��_������̑傫��
//������n ���`��n
const double SLIME_D_WIDTH = 1300 / 700 * SLIME_WIDTH;//500
const double SLIME_D_HEIGHT = 1000 / 700 * SLIME_HEIGHT;// 500
//const double SLIME_DIFF = (450 + 1500 / 2 - 3000 / 2) * SLIME_D_WIDTH / 3000;//PH*�匳�̔䗦
const double SLIME_DIFF_H = 0;
const double SLIME_DIFF_W = (100 + 700 / 2 - 1300 / 2) * SLIME_D_WIDTH / 1300;

const int SLIME_STAND_SPEED = 2;
const int SLIME_STAND_SUM = 40;	//����̃t���[����
const int SLIME_STAND_NUM = 4;	//����̉摜��
const int SLIME_JUMP_SPEED = 1;
const double SLIME_JUMP_SUM = 40.0;	//����̃t���[����
const int SLIME_JUMP_NUM = 3;	//����̉摜��
const double SLIME_JUMP_HIGH = DISP_HEIGHT * 0.3;//�W�����v�̍���
const int SLIME_DISAP_SUM = 5;
const int SLIME_DISAP_NUM = 1;

const int BIRD_WIDTH = 200;	//�v���C���[���̂̕�
const int BIRD_HEIGHT = 300;	//�v���C���[���̂̍����i2:3�j
const double BIRD_W_WIDTH = BIRD_WIDTH * 0.8;
const double BIRD_W_HEIGHT = BIRD_HEIGHT * 0.8;//��_������̑傫��
												 //������n ���`��n
const double BIRD_D_WIDTH = 3000 / 1000 * BIRD_WIDTH;//500
const double BIRD_D_HEIGHT = 3000 / 1500 * BIRD_HEIGHT;// 500
const double BIRD_DIFF = (450 + 1500 / 2 - 3000 / 2) * BIRD_D_WIDTH / 3000;//PH*�匳�̔䗦

const int BIRD_STAND_SUM = 90;
const int BIRD_STAND_NUM = 4;
const int BIRD_STAND_SPEED = 2;
const double BIRD_STAND_HIGH = 10.0;
const double BIRD_ATTACK_PRE = 15.0;
const double BIRD_ATTACK_SUM = 60.0;
const int BIRD_ATTACK_NUM = 4;
const int BIRD_DAMAGE_SPEED = -GROUND_SPEED;
const int BIRD_DISAP_SUM = 5;
const int BIRD_DISAP_NUM = 1;
//const int BIRD_BACK_SUM = ;
const int BIRD_BACK_NUM = 5;
const int BIRD_BACK_SPEED = 8;

#endif // !VALUE_H
