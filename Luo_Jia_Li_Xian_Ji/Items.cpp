#include "Items.h"

Items::Items(QObject *parent)
	: QObject(parent)
{
}

void Items::plus(maincharc*mm)
{
	mm->zhiLI += this->knowledge;
	mm->meiLi +=this->meili;
	mm->movepointMax += this->walk;
	mm->qinShang+=this->qingshang;
	mm->img += this->xxl;
	mm->money -= this->money;

}

Items::~Items()
{
}
