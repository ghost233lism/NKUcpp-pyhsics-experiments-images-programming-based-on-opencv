#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NKUexperimenter.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include "imgClass.h"
class NKUexperimenter : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent* event) override; // ÖØÐ´ resizeEvent
public:
    NKUexperimenter(QWidget *parent = nullptr);
    ~NKUexperimenter();

   
private slots:
   void buttonUploadClicked();
   void buttonGenerateClicked();
   
private:
    Ui::NKUexperimenterClass ui;
    QLabel* imgOriginal;
    QLabel* imgEdge;
    QLabel* imgRotate;
    QString file_path;
    ImageCV* imgToProcess=nullptr;
    //void showImage(QString labelName, QPixmap pixmap);
    QImage MatToQImage(const cv::Mat& mat);

};
