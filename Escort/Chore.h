#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

//�S���N���X�Ǘ��ł��ǂ���

class Back
{
public:
	int SetColor(int a);
	int SetKumo(int a);
	int SetFar(int a);
	int SetMiddle(int a);
	int SetClose(int a);
	int Updata(int count);
	int Draw();
	int End();
	/*Back();
	~Back();*/

private:
	int ColorImage;
	Square Color[2];
	int KumoImage;		//�摜�n���h��
	Square Kumo[2];		//�`��ʒu(�񖇕�(���[�v�p))
	int FarImage;
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
