#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_NKUexperimenter.h"
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QFileSystemModel>
#include <QTreeView>
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
   void buttonRetryClicked();
   void buttonEraseClicked();
   void buttonDownloadClicked();
   void buttonNewClicked();
   //void onFileDoubleClicked(const QModelIndex& index);
   
private:
    Ui::NKUexperimenterClass ui;
    QLabel* imgOriginal;
    QLabel* imgEdge;
    QLabel* imgRotate;
    QLabel* imgErase;
    QString filePath;
   // QTreeView* fileTreeView;
    //QFileSystemModel* fileSystemModel;
    ImageCV* imgToProcess=nullptr;
    //void showImage(QString labelName, QPixmap pixmap);
    QImage MatToQImage(const cv::Mat& mat);

};
