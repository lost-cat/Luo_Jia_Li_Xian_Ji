#pragma once

#include <QtWidgets/QWidget>
#include "maincharc.h"
#include <ui_TeachingBuilding.h>

class TeachingBuilding : public QWidget
{
    Q_OBJECT

public:
    TeachingBuilding(maincharc *mm,QWidget *parent = Q_NULLPTR);
   // void which(int* a,maincharc *b);
    static int count;
signals:
    void backToChoose();
private:
    Ui::TeachingBuildingClass ui;
};
