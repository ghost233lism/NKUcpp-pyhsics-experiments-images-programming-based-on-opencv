#pragma once

#include <QMainWindow>
#include <QScrollArea>
#include "ui_helpDoc.h"

class helpDoc : public QMainWindow
{
	Q_OBJECT

public:
	helpDoc(QWidget *parent = nullptr);
	~helpDoc();

private:
	Ui::helpDocClass ui;
};
