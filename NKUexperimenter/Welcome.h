#pragma once

#include <QWidget>
#include "ui_Welcome.h"

class Welcome : public QWidget
{
	Q_OBJECT

public:
	Welcome(QWidget *parent = nullptr);
	~Welcome();

private:
	Ui::WelcomeClass ui;
};
