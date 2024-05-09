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
#include <QToolTip>
#include <QKeyEvent>
#include "imgClass.h"
class NKUexperimenter : public QMainWindow
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent* event) override; // 重写 resizeEvent
    
public:
    NKUexperimenter(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* k);
    ~NKUexperimenter();

   
private slots:
   void buttonUploadClicked();
   void buttonGenerateClicked();
   void buttonRetryClicked();
   void buttonEraseClicked();
   void buttonDownloadClicked();
   void buttonNewClicked();
   void onNewFileTriggered();
   void onSaveEdgeTriggered();
   void onFileDoubleClicked(const QModelIndex& index);
   
private:
    Ui::NKUexperimenterClass ui;
    QLabel* imgOriginal;
    QLabel* imgEdge;
    QLabel* imgRotate;
    QLabel* imgErase;
    QString filePath;
    QPushButton* buttonUpload;
    QFileSystemModel* model;
    ImageCV* imgToProcess=nullptr;
   
    QImage MatToQImage(const cv::Mat& mat);

};
