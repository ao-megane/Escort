#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

class Back
{
public:
	int SetKumo(int a);
	int SetFar(int a);
	int SetMiddle(int a);
	int SetClose(int a);
	int Updata();
	/*Back();
	~Back();*/

private:
	int KumoImage;			//�摜�n���h��
	Square Kumo[2];		//�`��ʒu(�񖇕�(���[�v�p))
	int FarImge;
	Square Far[2];
	int MiddleImage;
	Square Middle[2];
	int CloseImage;
	Square Close[2];

};
//
//Back::Back()
//{
//}
//
//Back::~Back()
//{
//}

int ChoreInitialize();

int SetBack(int stageFlag);

int UpdataBack(int count);

int DrawBack();

int EndBack();

#endif // !CHORE_H
