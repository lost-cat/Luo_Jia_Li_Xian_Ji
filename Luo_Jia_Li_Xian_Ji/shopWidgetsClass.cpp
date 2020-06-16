#include "shopWidgetsClass.h"
#include<QPushButton>
#include<QColor>
#include"shop.h"
#include"maincharc.h"
#include<QMessageBox>
#include<QIcon>

shopWidgetsClass::shopWidgetsClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    //��ʼ������
    maincharc me(100, 100, 3, 100, 100);//��ʼ����������
    maincharc* me1 = &me;
    shop gaoji(10, 0, 0, 0, 100);//"�߼����Գ������"
    shop shuzi(10, 0, 0, 0, 150);//"���ֵ�·��Ƽ�Verilog"
    shop lisan(0, 0, 0, 10, 100);//"��ɢ��ѧ"
    shop ruhe(0, 20, 0, 0, 150);//"����������ദ"
    shop lanqiu(0, 0, 1, 0, 70);//"����������"
    shop gaodeng(12, 0, 0, 0, 120);//"�ߵ���ѧ"
    shop dianzi(0, 5, 0, 0, 100);//"���Ӿ�������"
    shop ruyu(0, 0, 0, 20, 80);//"��������"
    shop* goods1 = &gaoji;
    shop* goods2 = &shuzi;
    shop* goods3 = &lisan;
    shop* goods4 = &ruhe;
    shop* goods5 = &lanqiu;
    shop* goods6 = &gaodeng;
    shop* goods7 = &dianzi;
    shop* goods8 = &ruyu;
    //���ô��ڴ�С
    resize(800, 800);
    //���ô�������
    setWindowTitle("�Զ��");
    //���ùرհ�ť
    QPushButton* btn0 = new QPushButton;
    btn0->show();
    btn0->setParent(this);
    btn0->setText("�뿪�̵�");
    btn0->resize(100, 50);
    btn0->move(700, 600);
    connect(btn0, QPushButton::clicked, this, QWidget::close);
    //������һ����Ʒ����ť���߼����Գ������
    QPushButton* btn1 = new QPushButton;
    btn1->show();
    btn1->setParent(this);
    btn1->setText("�߼����Գ������\n���ԣ��ǻ�+10\n�۸�100");
    btn1->resize(200, 100);
    btn1->move(100, 0);
    //�����ڶ�����Ʒ����ť�����ֵ�·��Ƽ�Verilog
    QPushButton* btn2 = new QPushButton;
    btn2->show();
    btn2->setParent(this);
    btn2->setText("���ֵ�·��Ƽ�Verilog\n���ԣ��ǻ�+10\n�۸�150");
    btn2->resize(200, 100);
    btn2->move(450, 0);
    //������������Ʒ����ť����ɢ��ѧ
    QPushButton* btn3 = new QPushButton;
    btn3->show();
    btn3->setParent(this);
    btn3->setText("��ɢ��ѧ\n���ԣ�������+10\n�۸�100");
    btn3->resize(200, 100);
    btn3->move(100, 150);
    //�������ļ���Ʒ����ť����κ������ദ
    QPushButton* btn4 = new QPushButton;
    btn4->show();
    btn4->setParent(this);
    btn4->setText("��κ������ദ\n���ԣ�����+20\n�۸�150");
    btn4->resize(200, 100);
    btn4->move(450, 150);
    //�����������Ʒ����ť������������
    QPushButton* btn5 = new QPushButton;
    btn5->show();
    btn5->setParent(this);
    btn5->setText("����������\n���ԣ��ж���+1\n�۸�70");
    btn5->resize(200, 100);
    btn5->move(100, 300);
    //������������Ʒ����ť���ߵ���ѧ
    QPushButton* btn6 = new QPushButton;
    btn6->show();
    btn6->setParent(this);
    btn6->setText("�ߵ���ѧ\n���ԣ��ǻ�+12\n�۸�120");
    btn6->resize(200, 100);
    btn6->move(450, 300);
    //�������߼���Ʒ����ť�����Ӿ�������
    QPushButton* btn7 = new QPushButton;
    btn7->show();
    btn7->setParent(this);
    btn7->setText("���Ӿ�������\n���ԣ�����+5\n�۸�100");
    btn7->resize(200, 100);
    btn7->move(100, 450);
    //�����ڰ˼���Ʒ����ť����������
    QPushButton* btn8 = new QPushButton;
    btn8->show();
    btn8->setParent(this);
    btn8->setText("��������\ns���ԣ�������+20\n�۸�80");
    btn8->resize(200, 100);
    btn8->move(450, 450);
    //���������Ի�����ʾ������
    QMessageBox* box = new QMessageBox;
    //������һ�����lambda���ʽ��λ������
    connect(btn1, QPushButton::clicked, box, [=]() {
        if (goods1->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods1->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods1->getcharm();//����������
            me1->movepoint = me1->movepoint + goods1->getwalk();//���ж�������
            me1->remember = me1->remember + goods1->getremember();//�Ӽ���������
            me1->money = me1->money - goods1->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");


        }
        else
            box->critical(this, "������", "��������");
        });
    //�����ڶ������
    connect(btn2, QPushButton::clicked, box, [=]() {
        if (goods2->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods2->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods2->getcharm();//����������
            me1->movepoint = me1->movepoint + goods2->getwalk();//���ж�������
            me1->remember = me1->remember + goods2->getremember();//�Ӽ���������
            me1->money = me1->money - goods2->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");
        }
        else
            box->critical(this, "������", "��������");
        });
    //��������������
    connect(btn3, QPushButton::clicked, box, [=]() {
        if (goods3->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods3->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods3->getcharm();//����������
            me1->movepoint = me1->movepoint + goods3->getwalk();//���ж�������
            me1->remember = me1->remember + goods3->getremember();//�Ӽ���������
            me1->money = me1->money - goods3->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "������", "��������");
        });
    //�������ĸ����
    connect(btn4, QPushButton::clicked, box, [=]() {
        if (goods4->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods4->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods4->getcharm();//����������
            me1->movepoint = me1->movepoint + goods4->getwalk();//���ж�������
            me1->remember = me1->remember + goods4->getremember();//�Ӽ���������
            me1->money = me1->money - goods4->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "������", "��������");
        });
    //������������
    connect(btn5, QPushButton::clicked, box, [=]() {
        if (goods5->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods5->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods5->getcharm();//����������
            me1->movepoint = me1->movepoint + goods5->getwalk();//���ж�������
            me1->remember = me1->remember + goods5->getremember();//�Ӽ���������
            me1->money = me1->money - goods5->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "������", "��������");
        });
    //�������������
    connect(btn6, QPushButton::clicked, box, [=]() {
        if (goods6->getmoney() < me1->money)
        {
            me1->zhiLI= me1->zhiLI + goods6->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods6->getcharm();//����������
            me1->movepoint = me1->movepoint + goods6->getwalk();//���ж�������
            me1->remember = me1->remember + goods6->getremember();//�Ӽ���������
            me1->money = me1->money - goods6->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "critcal", "��������");
        });
    //�������߸����
    connect(btn7, QPushButton::clicked, box, [=]() {
        if (goods7->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods7->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods7->getcharm();//����������
            me1->movepoint = me1->movepoint + goods7->getwalk();//���ж�������
            me1->remember = me1->remember + goods7->getremember();//�Ӽ���������
            me1->money = me1->money - goods7->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "������", "��������");
        });
    //�����ڰ˸����
    connect(btn8, QPushButton::clicked, box, [=]() {
        if (goods8->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods8->getknowledge();//���ǻ�����
            me1->meiLi = me1->meiLi + goods8->getcharm();//����������
            me1->movepoint = me1->movepoint + goods8->getwalk();//���ж�������
            me1->remember = me1->remember + goods8->getremember();//�Ӽ���������
            me1->money = me1->money - goods8->getmoney();//�۳���Ӧ��Ǯ
            box->information(this, "������", "����ɹ�");

        }
        else
            box->critical(this, "������", "��������");
        });

}

shopWidgetsClass::~shopWidgetsClass()
{
}
