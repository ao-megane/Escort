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
	Dot center;			//中心座標
	Square weekArea;	//被ダメ範囲
	Square attackArea;	//与ダメ範囲
	int HP;				//HP
	int attack;			//現在の攻撃力
	int Image;			//現在の画像
	int width;
	int height;
	int bodyClock;		//アニメーション用体内時計
	int clockKeeper;	//被ダメ時のカウントキーパー
	int startClock;		//出現時時間
	int existFlag;		//存在(判定)フラグ
	int stateFlag;		//現状態フラグ
	int stateKeeper;
	int dirFlag;		//向いてる方向フラグ（0で左 1で右）
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
//	int Set(int count); //出現時処理
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
//	int Set(int count); //出現時処理
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
	int Set(int count,int position); //出現時処理
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
	int Set(int count,int position); //出現時処理
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

int EnemyMngInitialize();			//画像ハンドル周り
int EnemyMngSet(int levelFlag,int stageFlag, int count);	//ステージ、時間ごとに配置
int EnemyMngUpdata(int count);		//移動やらアニメやら、攻撃に入るのはJudgeで行う
int EnemyMngJudge(Player* player, Princess* girl,int count);	//判定、state、HP等の更新
int EnemyMngDraw();

#endif // !ENEMYMNG_H
