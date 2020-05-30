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
		ui.detailsAllWidget->setTitle("技能一：专心致志");
		ui.details->append("提高学习专注度,在高度专注的学习之下，受外界干扰的可能性降低.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("学习效率部分提高");
		ui.details->append("记忆力会长期性地小幅度提高；");
		ui.details->append("短暂性地少量提高智力；");
		ui.details->append("行动力略微下降。");
		setFixedSize(710, 630);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail2, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能二：深度学习");
		ui.details->append("与专心致志不同，使用深度学习将进入高度专注的学习状态，完全屏蔽受外界干扰的.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("学习效率提升显著");
		ui.details->append("短暂性地少量提高智力和想象力；");
		ui.details->append("记忆力会长期性地小幅度提高；");
		ui.details->append("行动力中度下降。");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail3, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能三：奇思妙想");
		ui.details->append("在奇思妙想的作用下，解答难题、写论文等时会更加轻松.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("短暂性地大幅度提高想象力，少量提高智力；");
		ui.details->append("记忆力会长期性地小幅度提高；");
		ui.details->append("行动力略微下降。");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail4, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能四：破釜沉舟");
		ui.details->append("使用破釜沉舟过后，消耗中上行动力，全身心投入学习中，面对任何作业得心应手.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("短暂性地大幅度提高智力和想象力；");
		ui.details->append("记忆力会长期性地小幅度下降；");
		ui.details->append("行动力中度下降。");
		ui.details->append("第二天行动力上限会轻度降低");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail5, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能五：废寝忘食");
		ui.details->append("糟糕，作业还没学完，看来只能熬夜赶作业了");
		ui.details->append("使用废寝忘食全身心投入学习中，面对任何作业得心应手.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("短暂性地超大幅度提高智力和想象力；");
		ui.details->append("记忆力会长期性地小幅度下降；");
		ui.details->append("行动力大幅度下降。");
		ui.details->append("这一周行动力上限轻度降低");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail6, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能六：偷梁换柱");
		ui.details->append("糟糕，作业还没学完，今天好累不想熬夜，难顶");
		ui.details->append("使用该技能，将会帮助室友检查作业，并从中获取一些“信息”.");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("长期性智力和想象力降低；");
		ui.details->append("记忆力会长期性地小幅度下降；");
		ui.details->append("行动力几乎不变。");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
	connect(ui.detail7, &QPushButton::clicked, [=]() {
		ui.details->clear();
		ui.detailsAllWidget->setTitle("技能七：我还能顶");
		ui.details->append("由于今天做的事太多，行动力极低");
		ui.details->append("使用该技能，如同吃了大力丸，不顶也能顶");
		ui.details->append(" ");
		ui.details->append("使用结果：");
		ui.details->append("智力想象力记忆力下降");
		ui.details->append("恢复自己已损耗行动力的百分之七十");
		setFixedSize(710, 650);
		ui.detailsAllWidget->show();
		});
}

skill::~skill()
{
}
