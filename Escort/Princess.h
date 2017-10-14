#ifndef PRINCESS_H
#define PRINCESS_H

#include"Chore.h"

class Princess
{
public:
	Princess();
	~Princess();
	int Initialize();
	int Updata();
	int End();

private:
	int HP;
	Dot center;
	Square week;
};

Princess::Princess()
{
}

Princess::~Princess()
{
}

#endif // !PRINCESS_H