#include "maincharc.h"
#include"Select_course.h"
#include"Luo_Jia_Li_Xian_Ji.h"
#if _MSC_VER >=1600 //VS2010�汾����1600��ǿ��MSVC����������UTF-8�������ɿ�ִ���ļ�
#pragma execution_character_set("utf-8")
#endif
maincharc::maincharc(QObject* parent, int mv, int hp, int ml, int zl, int qs, int mn)
	: QObject(parent)
{
	this->HP = hp;
	this->movepoint = mv;
	this->meiLi = ml;
	this->zhiLI = zl;
	this->qinShang = qs;
	this->money = mn;
	this->selctedCourse = new Select_course[6]{ {001, "��ѧӢ��", 0, "����>=300"},
												{002, "��ѧ����", 0, "����>=300"},
												{003, "������ͼ", 0, "����>=300"},
												{004, "������ѧ", 0, "����>=300"},
												{005, "�߼��������", 0, "����>=300"},
												{006, "��ɢ��ѧ", 0, "����>=300"}, };
}
maincharc::~maincharc()
{
}

void maincharc::recover()
{
	this->movepoint = movepointMax;

}

//void maincharc::levup()
//{
//	if (this->exp>=10*this->LEVEL)
//	{
//	this->exp = this->exp - 10 * this->LEVEL;
//	this->LEVEL++;
//	this->ATK += 5;
//	this->DEF += 3;
//	this->ATS += 1;
//	this->ADF += 2;
//	this->HP +=15;
//	}
//}

//void maincharc::attack(monster * m1)
//{
//
//	m1->HP -= this->ATK - m1->DEF;
//
//}

/*
void maincharc::weapon_on(Weapon w)
{
	this->weapon = w;
}*/
/*
void maincharc::weapon_effect()
{
	switch (static_cast<int>(this->weapon))
	{
	case 0:  this->ATK += 5; break;
	case 1:this->ATK += 8; break;
	case 2:this->ATK += 10; this->DEF -= 3; break;

	default:
		break;
	}
}*/

//void maincharc::expget(monster *m1)
//{
//	switch (m1->num)
//	{
//		case 1: this->exp += 2; break;
//		case 2: this->exp += 4; break;
//		case 3: this->exp += 6; break;
//		case 4: this->exp += 8; break;
//		case 5: this->exp += 10; break;
//		case 6: this->exp += 12; break;
//		default: this->exp += 1;
//			break;
//	}
//
//}


