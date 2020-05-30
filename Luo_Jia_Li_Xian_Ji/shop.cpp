#include "shop.h"

shop::shop(maincharc*, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.close, &QPushButton::clicked, this, &QWidget::close);
	
}

shop::~shop()
{
}

