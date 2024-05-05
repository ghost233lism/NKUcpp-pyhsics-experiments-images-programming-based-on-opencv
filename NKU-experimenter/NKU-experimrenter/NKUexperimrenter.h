#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NKUexperimrenter.h"

class NKUexperimrenter : public QMainWindow
{
    Q_OBJECT

public:
    NKUexperimrenter(QWidget *parent = nullptr);
    ~NKUexperimrenter();

private:
    Ui::NKUexperimrenterClass ui;
};
