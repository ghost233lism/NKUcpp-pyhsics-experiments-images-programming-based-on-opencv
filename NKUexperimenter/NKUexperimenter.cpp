#include "NKUexperimenter.h"
#include "ui_NKUexperimenter.h"
#include "imgClass.h"
bool isUpload = false;
bool isRotate = false;
bool isErase = false;
int windowsCount = 1;
int fallDown = 0;
NKUexperimenter::NKUexperimenter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 使用 findChild 来获取按钮的指针
    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
    buttonUpload->setToolTip(u8"上传");
    QPixmap pixmapUp("Icon/upload.png"); // 原始图片路径
    QSize buttonSizeForUp = buttonUpload->size(); // 获取按钮的当前大小
    pixmapUp = pixmapUp.scaled(buttonSizeForUp, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonUpload->setIcon(QIcon(pixmapUp));
    buttonUpload->setIconSize(buttonSizeForUp); // 确保图标尺寸与按钮尺寸一致

    if (buttonUpload)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonUpload, &QPushButton::clicked, this, &NKUexperimenter::buttonUploadClicked);
    }

    QLabel *imgOriginal = this->findChild<QLabel*>("imgOriginal");
    imgOriginal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    QPushButton* buttonGenerate = this->findChild<QPushButton*>("buttonGenerate");
    if (buttonGenerate)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonGenerate, &QPushButton::clicked, this, &NKUexperimenter::buttonGenerateClicked);
    }

    QPixmap pixmapGe("Icon/generate.png"); // 原始图片路径
    QSize buttonSizeForGe = buttonGenerate->size(); // 获取按钮的当前大小
    pixmapGe = pixmapGe.scaled(buttonSizeForGe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonGenerate->setIcon(QIcon(pixmapGe));
    buttonGenerate->setIconSize(buttonSizeForGe); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonRetry = this->findChild<QPushButton*>("buttonRetry");
    if (buttonRetry)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonRetry, &QPushButton::clicked, this, &NKUexperimenter::buttonRetryClicked);
    }

    QPixmap pixmapRe("Icon/retry.png"); // 原始图片路径
    QSize buttonSizeForRe = buttonRetry->size(); // 获取按钮的当前大小
    pixmapRe = pixmapRe.scaled(buttonSizeForRe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonRetry->setIcon(QIcon(pixmapRe));
    buttonRetry->setIconSize(buttonSizeForRe); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonErase = this->findChild<QPushButton*>("buttonErase");
    if (buttonErase)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonErase, &QPushButton::clicked, this, &NKUexperimenter::buttonEraseClicked);
    }

    QPixmap pixmapEr("Icon/erase.png"); // 原始图片路径
    QSize buttonSizeForEr = buttonErase->size(); // 获取按钮的当前大小
    pixmapEr = pixmapEr.scaled(buttonSizeForEr, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonErase->setIcon(QIcon(pixmapEr));
    buttonErase->setIconSize(buttonSizeForEr); // 确保图标尺寸与按钮尺寸一致


    QPushButton* buttonDownload = this->findChild<QPushButton*>("buttonDownload");
    if (buttonDownload)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonDownload, &QPushButton::clicked, this, &NKUexperimenter::buttonDownloadClicked);
    }

    QPixmap pixmapDo("Icon/download.png"); // 原始图片路径
    QSize buttonSizeForDo = buttonDownload->size(); // 获取按钮的当前大小
    pixmapDo = pixmapDo.scaled(buttonSizeForDo, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonDownload->setIcon(QIcon(pixmapDo));
    buttonDownload->setIconSize(buttonSizeForDo); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonNew = this->findChild<QPushButton*>("buttonNew");
    if (buttonNew)
    {
        // 连接按钮的 clicked 信号到槽函数
        connect(buttonNew, &QPushButton::clicked, this, &NKUexperimenter::buttonNewClicked);
    }

    QPixmap pixmapNe("Icon/new.png"); // 原始图片路径
    QSize buttonSizeForNe = buttonNew->size(); // 获取按钮的当前大小
    pixmapNe = pixmapNe.scaled(buttonSizeForNe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonNew->setIcon(QIcon(pixmapNe));
    buttonNew->setIconSize(buttonSizeForNe); // 确保图标尺寸与按钮尺寸一致

    
    QPixmap pixmapLoading1("Icon/loading.png"); // 原始图片路径
    QSize buttonSizeForLoading1 = imgOriginal->size(); // 获取按钮的当前大小
    pixmapLoading1 = pixmapLoading1.scaled(buttonSizeForLoading1/2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgOriginal->setPixmap(pixmapLoading1);
    imgOriginal->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
    QPixmap pixmapLoading2("Icon/loading2.png"); // 原始图片路径
    QSize buttonSizeForLoading2 = imgEdge->size(); // 获取按钮的当前大小
    pixmapLoading2 = pixmapLoading2.scaled(buttonSizeForLoading2 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgEdge->setPixmap(pixmapLoading2);
    imgEdge->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
    QPixmap pixmapLoading3("Icon/loading3.png"); // 原始图片路径
    QSize buttonSizeForLoading3 = imgRotate->size(); // 获取按钮的当前大小
    pixmapLoading3 = pixmapLoading3.scaled(buttonSizeForLoading3 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgRotate->setPixmap(pixmapLoading3);
    imgRotate->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QLabel* imgErase = this->findChild<QLabel*>("imgErase");
    QPixmap pixmapLoading4("Icon/loading4.png"); // 原始图片路径
    QSize buttonSizeForLoading4 = imgErase->size(); // 获取按钮的当前大小
    pixmapLoading4 = pixmapLoading4.scaled(buttonSizeForLoading4 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgErase->setPixmap(pixmapLoading4);
    imgErase->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QAction* newFile = this->findChild<QAction*>("newFile");
    connect(newFile, &QAction::triggered, this, &NKUexperimenter::onNewFileTriggered);

    QAction* saveEdge = this->findChild<QAction*>("saveEdge");
    connect(saveEdge, &QAction::triggered, this, &NKUexperimenter::onSaveEdgeTriggered);

    QAction* saveRotate = this->findChild<QAction*>("saveRotate");
    connect(saveRotate, &QAction::triggered, this, &NKUexperimenter::onSaveRotateTriggered);

    QTreeView* fileTreeView = this->findChild<QTreeView*>("treeView");
    connect(fileTreeView, &QTreeView::doubleClicked, this, &NKUexperimenter::onFileDoubleClicked); // 连接双击信号
    model = new QFileSystemModel(this);
    fileTreeView->setModel(model);
    // 设置显示的根目录
    model->setRootPath(QDir::homePath());
    fileTreeView->setRootIndex(model->index(QDir::homePath()));

    //this->showMaximized();
}
void NKUexperimenter::onNewFileTriggered()
{
    if (windowsCount <= 5)
    {
        NKUexperimenter* newWindow = new NKUexperimenter();
        windowsCount++;
        newWindow->show();
    }
    else
    {
        QMessageBox::warning(nullptr, tr("Warning"), tr(u8"窗口打开过多，请关闭窗口后重试"));
    }
    
}
void NKUexperimenter::onSaveEdgeTriggered()
{
    QPixmap myPixmap = imgToProcess->imgEdgeToShow;
    if (!myPixmap.isNull())
    {
        QString savePath = QFileDialog::getSaveFileName(nullptr,
            tr(u8"保存结果"),
            QDir::homePath(),
            tr("pic (*.png *.jpg )"));

        bool saved = myPixmap.save(savePath);
        if (saved)
        {
            QMessageBox::information(nullptr, tr(u8"保存成功"), tr(u8"至 ") + savePath);
        }
        else
        {
            QMessageBox::warning(nullptr, tr("Warning"), tr(u8"保存失败"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Pixmap null "));
    }
}
void NKUexperimenter::onSaveRotateTriggered()
{
    QPixmap myPixmap = imgToProcess->imgRotateToShow;
    if (!myPixmap.isNull())
    {
        QString savePath = QFileDialog::getSaveFileName(nullptr,
            tr(u8"保存结果"),
            QDir::homePath(),
            tr("pic (*.png *.jpg )"));

        bool saved = myPixmap.save(savePath);
        if (saved)
        {
            QMessageBox::information(nullptr, tr("save suceesfully"), tr("saved to ") + savePath);
        }
        else
        {
            QMessageBox::warning(nullptr, tr("Warning"), tr("fail to save"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("Pixmap null "));
    }
}
void NKUexperimenter::buttonUploadClicked()
{
    filePath = QFileDialog::getOpenFileName(this,
        tr(u8"上传文件"),
        "",
        tr("Image Files (*.png *.jpg )")); // 限制用户只能选择图片文件
    //创建Image对象
    delete imgToProcess;
    try {
        imgToProcess = new ImageCV(filePath.toStdString());
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
        return;
    }
    isUpload = true;
    if (!filePath.isEmpty()) {
        // 使用 QPixmap 加载图片
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            // 找到名为 imgOriginal 的 QLabel 控件
            QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgOriginal) 
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgOriginal->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
                imgOriginal->setPixmap(scaledPixmap);
                
            }

            model->setRootPath(QFileInfo(filePath).dir().absolutePath());
            QTreeView* fileTreeView= this->findChild<QTreeView*>("treeView");
            fileTreeView->setModel(model);
            fileTreeView->setRootIndex(model->index(model->rootPath()));
            fileTreeView->expandAll();
        }
        else 
        {
            QMessageBox::warning(this, tr("Warning"), tr(u8"路径有误，请选择正确的文件") + filePath);
        }
    }
}
void NKUexperimenter::buttonGenerateClicked()
{
    if (isUpload)
    {
        Mat imgEdge = imgToProcess->edge();
        Mat imgRotate = imgToProcess->rotate();
        QImage imgEdgeQI = MatToQImage(imgEdge);
        QImage imgRotateQI = MatToQImage(imgRotate);
        if (imgEdgeQI.isNull() || imgRotateQI.isNull())
        {
            QMessageBox::warning(this, tr("Warning"), tr("Fail to Image"));
        }

        QPixmap imgEdgeQP = QPixmap::fromImage(imgEdgeQI);
        QPixmap imgRotateQP = QPixmap::fromImage(imgRotateQI);
        imgToProcess->imgEdgeToShow = imgEdgeQP;
        imgToProcess->imgRotateToShow = imgRotateQP;
        if (!imgEdgeQP.isNull())
        {
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgEdge)
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgEdge->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = imgEdgeQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
                imgEdge->setPixmap(scaledPixmap);
                isRotate = true;

            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to find "));
            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr(u8"请上传图片！"));
        }
        if (!imgRotateQP.isNull())
        {
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgRotate)
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgRotate->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = imgRotateQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
                imgRotate->setPixmap(scaledPixmap);
                QMessageBox::warning(this, tr(u8"生成成功"), tr(u8"如对结果不满意，可点击重试按钮重新生成（旋转结果关系到文字擦除效果）"));
            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to find "));
            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: "));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr(u8"请上传图片！"));
    }
       
}
void NKUexperimenter::buttonRetryClicked()
{
    if (isUpload&&isRotate)
    {
        double angle = imgToProcess->getRotateAngle(imgToProcess->getImgAfterRotate());
        Mat imgRotate = imgToProcess->rotate(angle);
        QImage imgRotateQI = MatToQImage(imgRotate);
        QPixmap imgRotateQP = QPixmap::fromImage(imgRotateQI);
        imgToProcess->imgRotateToShow = imgRotateQP;
        if (!imgRotateQP.isNull())
        {
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgRotate)
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgRotate->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = imgRotateQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
                imgRotate->setPixmap(scaledPixmap);

            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to find "));
            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: "));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr(u8"请上传图片或先进行图像旋转！"));
    }
    

}
void NKUexperimenter::buttonEraseClicked()
{
    if (isUpload && isRotate)
    {
        imgToProcess->eraseText();
        QImage imgEraseQI = MatToQImage(imgToProcess->getImgOutput());
        QPixmap imgEraseQP = QPixmap::fromImage(imgEraseQI);
        if (!imgEraseQP.isNull())
        {
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgErase = this->findChild<QLabel*>("imgErase");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgErase)
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgErase->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = imgEraseQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
                imgErase->setPixmap(scaledPixmap);
                isErase = true;

            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to find "));
            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: "));
        }
        imgToProcess->imgToSave = imgEraseQP;
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr(u8"请上传图片或先进行图像旋转！"));
    }
    
}
void NKUexperimenter::buttonDownloadClicked()
{
    if (isUpload && isRotate && isErase)
    {
        QPixmap myPixmap = imgToProcess->imgToSave;
        if (!myPixmap.isNull())
        {
            QString savePath = QFileDialog::getSaveFileName(nullptr,
                tr(u8"保存结果"),
                QDir::homePath(),
                tr("pic (*.png *.jpg )"));

            bool saved = myPixmap.save(savePath);
            if (saved)
            {
                QMessageBox::information(nullptr, tr("save suceesfully"), tr("saved to ") + savePath);
            }
            else
            {
                QMessageBox::warning(nullptr, tr("Warning"), tr("fail to save"));
            }
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Pixmap null "));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr(u8"上传图片、点击生成、点击擦除后方可下载结果"));
    }
    
        
}
void NKUexperimenter::buttonNewClicked() 
{
    if (windowsCount <= 5)
    {
        NKUexperimenter* newWindow = new NKUexperimenter();
        windowsCount++;
        newWindow->show();
    }
    else
    {
        QMessageBox::warning(nullptr, tr("Warning"), tr(u8"窗口打开过多，请关闭窗口后重试"));
    }
}
QImage NKUexperimenter::MatToQImage(const cv::Mat& mat)
{
    QImage img;
    int chana = mat.channels();
    /// 依据通道数不同，改变不同的装换方式
    if (chana > 1) {
        //img = QImage(static_cast<uchar *>(mat.data),mat.cols,mat.rows,QImage::Format_RGB888);
        cv::cvtColor(mat, mat, COLOR_BGR2RGB);
        /// construct the QImage using the data of the mat, while do not copy the data
        img = QImage((const uchar*)(mat.data),
            mat.cols,
            mat.rows,
            mat.step,//TmpMat.cols*TmpMat.channels(),
            QImage::Format_RGB888);
    }
    else if (4 == chana) {
        cv::cvtColor(mat, mat, COLOR_BGR2RGB);
        /// construct the QImage using the data of the mat, while do not copy the data
        img = QImage((const uchar*)(mat.data),
            mat.cols,
            mat.rows,
            mat.step,//TmpMat.cols*TmpMat.channels(),
            QImage::Format_ARGB32);
    }
    else {
        /// 单通道，灰度图
        img = QImage(mat.cols, mat.rows, QImage::Format_Indexed8);
        uchar* matdata = mat.data;
        for (int row = 0; row < mat.rows; ++row) {
            uchar* rowdata = img.scanLine(row);
            memcpy(rowdata, matdata, mat.cols);
            matdata += mat.cols;
        }

        QVector<QRgb>  colorTable;

        for (int k = 0; k < 256; ++k)
        {
            colorTable.push_back(qRgb(k, k, k));
        }

        img.setColorTable(colorTable);
    }
    img.bits();
    return img;
}
void NKUexperimenter::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event); // 始终首先调用基类的事件处理函数

    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
    QPixmap pixmapUp("Icon/upload.png"); // 原始图片路径
    QSize buttonSizeforUp = buttonUpload->size(); // 获取按钮的当前大小
    pixmapUp = pixmapUp.scaled(buttonSizeforUp, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonUpload->setIcon(QIcon(pixmapUp));
    buttonUpload->setIconSize(buttonSizeforUp); // 确保图标尺寸与按钮尺寸一致

    QSize uploadSize = buttonUpload->size();
    if (uploadSize.width() > 350 &&fallDown<1)
    {
        QMessageBox::warning(nullptr, tr("Warning"), tr(u8"程序崩溃，测试版遗留问题，新建窗口并关闭本窗口即可解决，在放大窗口时请使用右上角最大化按键，不要进行拖拽，后续版本会进行修复"));
        fallDown++;
       
    }

    QPushButton* buttonGenerate = this->findChild<QPushButton*>("buttonGenerate");
    QPixmap pixmapGe("Icon/generate.png"); // 原始图片路径
    QSize buttonSizeforGe = buttonGenerate->size(); // 获取按钮的当前大小
    pixmapGe = pixmapGe.scaled(buttonSizeforGe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonGenerate->setIcon(QIcon(pixmapGe));
    buttonGenerate->setIconSize(buttonSizeforGe); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonRetry = this->findChild<QPushButton*>("buttonRetry");
    QPixmap pixmapRe("Icon/retry.png"); // 原始图片路径
    QSize buttonSizeForRe = buttonRetry->size(); // 获取按钮的当前大小
    pixmapRe = pixmapRe.scaled(buttonSizeForRe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonRetry->setIcon(QIcon(pixmapRe));
    buttonRetry->setIconSize(buttonSizeForRe); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonErase = this->findChild<QPushButton*>("buttonErase");
    QPixmap pixmapEr("Icon/erase.png"); // 原始图片路径
    QSize buttonSizeForEr = buttonErase->size(); // 获取按钮的当前大小
    pixmapEr = pixmapEr.scaled(buttonSizeForEr, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonErase->setIcon(QIcon(pixmapEr));
    buttonErase->setIconSize(buttonSizeForEr); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonDownload = this->findChild<QPushButton*>("buttonDownload");
    QPixmap pixmapDo("Icon/download.png"); // 原始图片路径
    QSize buttonSizeForDo = buttonDownload->size(); // 获取按钮的当前大小
    pixmapDo = pixmapDo.scaled(buttonSizeForDo, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonDownload->setIcon(QIcon(pixmapDo));
    buttonDownload->setIconSize(buttonSizeForDo); // 确保图标尺寸与按钮尺寸一致

    QPushButton* buttonNew = this->findChild<QPushButton*>("buttonNew");
    QPixmap pixmapNe("Icon/new.png"); // 原始图片路径
    QSize buttonSizeForNe = buttonNew->size(); // 获取按钮的当前大小
    pixmapNe = pixmapNe.scaled(buttonSizeForNe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonNew->setIcon(QIcon(pixmapNe));
    buttonNew->setIconSize(buttonSizeForNe); // 确保图标尺寸与按钮尺寸一致

    QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
    if (imgOriginal)
    {
        if (!filePath.isEmpty())
        {
            // 使用 QPixmap 加载图片
            QPixmap pixmap(filePath);
            // showImage("imgOriginal", pixmap);
            if (!pixmap.isNull())
            {
                // 找到名为 imgOriginal 的 QLabel 控件
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
                if (imgOriginal)
                {
                    // 获取 QLabel 的尺寸
                    QSize labelSize = imgOriginal->size();

                    // 根据 QLabel 的尺寸缩放图片，保持宽高比
                    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                    // 设置 QLabel 显示缩放后的图片
                    imgOriginal->setPixmap(scaledPixmap);

                }
            }
        }
    }
    QPixmap pixmapLoading1("Icon/loading.png"); // 原始图片路径
    QSize buttonSizeForLoading1 = imgOriginal->size(); // 获取按钮的当前大小
    pixmapLoading1 = pixmapLoading1.scaled(buttonSizeForLoading1/2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgOriginal->setPixmap(pixmapLoading1);
    
    QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
    QPixmap pixmapLoading2("Icon/loading2.png"); // 原始图片路径
    QSize buttonSizeForLoading2 = imgEdge->size(); // 获取按钮的当前大小
    pixmapLoading2 = pixmapLoading2.scaled(buttonSizeForLoading2 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgEdge->setPixmap(pixmapLoading2);
    imgEdge->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
    QPixmap pixmapLoading3("Icon/loading3.png"); // 原始图片路径
    QSize buttonSizeForLoading3 = imgRotate->size(); // 获取按钮的当前大小
    pixmapLoading3 = pixmapLoading3.scaled(buttonSizeForLoading3 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgRotate->setPixmap(pixmapLoading3);
    imgRotate->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片

    QLabel* imgErase = this->findChild<QLabel*>("imgErase");
    QPixmap pixmapLoading4("Icon/loading4.png"); // 原始图片路径
    QSize buttonSizeForLoading4 = imgOriginal->size(); // 获取按钮的当前大小
    pixmapLoading4 = pixmapLoading4.scaled(buttonSizeForLoading4 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgErase->setPixmap(pixmapLoading4);
    imgErase->setAlignment(Qt::AlignCenter); // 水平和垂直居中对齐图片
}
void NKUexperimenter::onFileDoubleClicked(const QModelIndex& index) {
    // 检查双击的文件是否是图片格式
    QString filePath = model->filePath(index);
    QFileInfo fileInfo(filePath);
    if (fileInfo.suffix().compare("png", Qt::CaseInsensitive) == 0 ||
        fileInfo.suffix().compare("jpg", Qt::CaseInsensitive) == 0 )
    {
        // TODO: 实现上传逻辑
        delete imgToProcess;
        try {
            imgToProcess = new ImageCV(filePath.toStdString());
        }
        catch (const std::exception& e) {
            QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
            return;
        }
        if (!filePath.isEmpty()) {
            // 使用 QPixmap 加载图片
            QPixmap pixmap(filePath);
            if (!pixmap.isNull()) {
                // 找到名为 imgOriginal 的 QLabel 控件
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
                if (imgOriginal)
                {
                    // 获取 QLabel 的尺寸
                    QSize labelSize = imgOriginal->size();

                    // 根据 QLabel 的尺寸缩放图片，保持宽高比
                    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                    // 设置 QLabel 显示缩放后的图片
                    imgOriginal->setPixmap(scaledPixmap);

                }
           
            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: ") + filePath);
            }
        }
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr(u8"请选择图片文件"));
    }
}
void NKUexperimenter::keyPressEvent(QKeyEvent* k)
{
    if (k->modifiers() == Qt::ControlModifier&&k->key()==Qt::Key_N)
    {
        if (windowsCount <= 5)
        {
            NKUexperimenter* newWindow = new NKUexperimenter();
            windowsCount++;
            newWindow->show();
        }
        else
        {
            QMessageBox::warning(nullptr, tr("Warning"), tr(u8"窗口打开过多，请关闭窗口后重试"));
        }
    }
}
NKUexperimenter::~NKUexperimenter()
{
    delete imgToProcess;
    delete model;
    
    // 销毁对象时的清理工作（如果有的话）
}