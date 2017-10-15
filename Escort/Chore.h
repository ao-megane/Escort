#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"

//全部クラス管理でも良くね

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
	int KumoImage;		//画像ハンドル
	Square Kumo[2];		//描画位置(二枚分(ループ用))
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
