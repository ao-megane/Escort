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
	//int Updata(int count);	//キャラごとに作る
	int Draw();			//描画
	//int End();

protected:
	Dot center;			//中心座標
	Square weekArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	int HP;				//HP
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int width;
	int height;
	int bodyClock;		//アニメーション用体内時計
	int starClock;		//出現時時間
	int existFlag;		//存在(判定)フラグ
	int stateFlag;		//現状態フラグ
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
	int Set(int count); //出現時処理
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
	int Set(int count); //出現時処理
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

int EnemyMngInitialize();			//画像ハンドル周り
int EnemyMngSet(int stageFlag, int count);	//ステージ、時間ごとに配置
int EnemyMngUpdata(int count);		//移動やらアニメやら、攻撃に入るのはJudgeで行う
int EnemyMngJudge(Player* player, Princess* girl,int count);	//判定、state、HP等の更新
int EnemyMngDraw();

#endif // !ENEMYMNG_H
