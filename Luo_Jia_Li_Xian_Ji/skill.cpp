#include "skill.h"
#include <QPushButton>
#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
skill::skill(maincharc*mm, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.detailsAllWidget->hide();
	setFixedSize(450, 630);
	connect(ui.exit, &QPushButton::clicked, [=]()
		{
			emit backToMainScence();
		});
	connect(ui.close, &QPushButton::clicked, [=]()
		{
		ui.detailsAllWidget->hide();
		setFixedSize(450, 630);
		});
	connect(ui.detail1, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("����һ��ר����־");
		ui.details->append("���ѧϰרע��,�ڸ߶�רע��ѧϰ֮�£��������ŵĿ����Խ���.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("ѧϰЧ�ʲ������");
		ui.details->append("�������᳤���Ե�С������ߣ�");
		ui.details->append("�����Ե��������������");
		ui.details->append("�ж�����΢�½���");
		setFixedSize(710, 630);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail2, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("���ܶ������ѧϰ");
		ui.details->append("��ר����־��ͬ��ʹ�����ѧϰ������߶�רע��ѧϰ״̬����ȫ�����������ŵ�.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("ѧϰЧ����������");
		ui.details->append("�����Ե����������������������");
		ui.details->append("�������᳤���Ե�С������ߣ�");
		ui.details->append("�ж����ж��½���");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail3, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("����������˼����");
		ui.details->append("����˼����������£�������⡢д���ĵ�ʱ���������.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("�����Եش����������������������������");
		ui.details->append("�������᳤���Ե�С������ߣ�");
		ui.details->append("�ж�����΢�½���");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail4, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("�����ģ��Ƹ�����");
		ui.details->append("ʹ���Ƹ����۹������������ж�����ȫ����Ͷ��ѧϰ�У�����κ���ҵ����Ӧ��.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("�����Եش���������������������");
		ui.details->append("�������᳤���Ե�С�����½���");
		ui.details->append("�ж����ж��½���");
		ui.details->append("�ڶ����ж������޻���Ƚ���");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail5, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("�����壺������ʳ");
		ui.details->append("��⣬��ҵ��ûѧ�꣬����ֻ�ܰ�ҹ����ҵ��");
		ui.details->append("ʹ�÷�����ʳȫ����Ͷ��ѧϰ�У�����κ���ҵ����Ӧ��.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("�����Եس�����������������������");
		ui.details->append("�������᳤���Ե�С�����½���");
		ui.details->append("�ж���������½���");
		ui.details->append("��һ���ж���������Ƚ���");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail6, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("��������͵������");
		ui.details->append("��⣬��ҵ��ûѧ�꣬������۲��밾ҹ���Ѷ�");
		ui.details->append("ʹ�øü��ܣ�����������Ѽ����ҵ�������л�ȡһЩ����Ϣ��.");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("���������������������ͣ�");
		ui.details->append("�������᳤���Ե�С�����½���");
		ui.details->append("�ж����������䡣");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail7, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("�����ߣ��һ��ܶ�");
		ui.details->append("���ڽ���������̫�࣬�ж�������");
		ui.details->append("ʹ�øü��ܣ���ͬ���˴����裬����Ҳ�ܶ�");
		ui.details->append(" ");
		ui.details->append("ʹ�ý����");
		ui.details->append("�����������������½�");
		ui.details->append("�ָ��Լ�������ж����İٷ�֮��ʮ");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
}

skill::~skill()
{
}
