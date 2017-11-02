#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"
#include<string>

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

int SystemInitialize();

int PlayMove();

int PlayChoice();

int ChoreSet(int levelFlag);

int* ScorePass();

int PlayBGM();

int DrawOP(int levelFlag);

int DrawPrologue(int b);

int DrawManual(int b);

int DrawCredit();

int DrawPause(int count);

void DrawChore(int count, int HP,int levelFlag);

int SetBack(int stageFlag);

int UpdataBack(int count);

int DrawBack();

int EndBack();

int InputFile(std::string file);

int DrawData(int levelFlag);

int UpdataFile(std::string file,int levelFlag,int score);//�Ăяo�����->��l���̍X�V

int SetLoser(int levelFlag,int count);

int LoserUpdata(int count);

int DrawLoseBord(int count);

int DrawWinBord(int count);

int SetWinner(int levelFlag,int count,int* score);

int WinnerUpdata(int count);

void FpsTimeFanction();

#endif // !CHORE_H
