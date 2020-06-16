#pragma once

#include <QObject>
#include"maincharc.h"
class Items : public QObject
{
	Q_OBJECT

public:
	Items(QObject *parent);
	Items(int knowledge1,int meili, int xiang, int walk1, int money1,int qs, QObject* parent= Q_NULLPTR) :knowledge(knowledge1),
	 walk(walk1), money(money1), xxl(xiang), meili(meili), qingshang(qs) {};
	int knowledge;
	int walk;
	int money;
	int xxl;
	int meili;
	int qingshang;
	void plus(maincharc*);
	~Items();
};
