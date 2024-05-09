#include "NKUexperimenter.h"
#include "ui_NKUexperimenter.h"
#include "imgClass.h"
NKUexperimenter::NKUexperimenter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // ʹ�� findChild ����ȡ��ť��ָ��
    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
    QPixmap pixmapUp("Icon/upload.png"); // ԭʼͼƬ·��
    QSize buttonSizeForUp = buttonUpload->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapUp = pixmapUp.scaled(buttonSizeForUp, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonUpload->setIcon(QIcon(pixmapUp));
    buttonUpload->setIconSize(buttonSizeForUp); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    if (buttonUpload)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonUpload, &QPushButton::clicked, this, &NKUexperimenter::buttonUploadClicked);
    }

    QLabel *imgOriginal = this->findChild<QLabel*>("imgOriginal");
    imgOriginal->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    QPushButton* buttonGenerate = this->findChild<QPushButton*>("buttonGenerate");
    if (buttonGenerate)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonGenerate, &QPushButton::clicked, this, &NKUexperimenter::buttonGenerateClicked);
    }

    QPixmap pixmapGe("Icon/generate.png"); // ԭʼͼƬ·��
    QSize buttonSizeForGe = buttonGenerate->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapGe = pixmapGe.scaled(buttonSizeForGe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonGenerate->setIcon(QIcon(pixmapGe));
    buttonGenerate->setIconSize(buttonSizeForGe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonRetry = this->findChild<QPushButton*>("buttonRetry");
    if (buttonRetry)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonRetry, &QPushButton::clicked, this, &NKUexperimenter::buttonRetryClicked);
    }

    QPixmap pixmapRe("Icon/retry.png"); // ԭʼͼƬ·��
    QSize buttonSizeForRe = buttonRetry->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapRe = pixmapRe.scaled(buttonSizeForRe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonRetry->setIcon(QIcon(pixmapRe));
    buttonRetry->setIconSize(buttonSizeForRe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonErase = this->findChild<QPushButton*>("buttonErase");
    if (buttonErase)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonErase, &QPushButton::clicked, this, &NKUexperimenter::buttonEraseClicked);
    }

    QPixmap pixmapEr("Icon/erase.png"); // ԭʼͼƬ·��
    QSize buttonSizeForEr = buttonErase->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapEr = pixmapEr.scaled(buttonSizeForEr, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonErase->setIcon(QIcon(pixmapEr));
    buttonErase->setIconSize(buttonSizeForEr); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��


    QPushButton* buttonDownload = this->findChild<QPushButton*>("buttonDownload");
    if (buttonDownload)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonDownload, &QPushButton::clicked, this, &NKUexperimenter::buttonDownloadClicked);
    }

    QPixmap pixmapDo("Icon/download.png"); // ԭʼͼƬ·��
    QSize buttonSizeForDo = buttonDownload->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapDo = pixmapDo.scaled(buttonSizeForDo, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonDownload->setIcon(QIcon(pixmapDo));
    buttonDownload->setIconSize(buttonSizeForDo); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonNew = this->findChild<QPushButton*>("buttonNew");
    if (buttonNew)
    {
        // ���Ӱ�ť�� clicked �źŵ��ۺ���
        connect(buttonNew, &QPushButton::clicked, this, &NKUexperimenter::buttonNewClicked);
    }

    QPixmap pixmapNe("Icon/new.png"); // ԭʼͼƬ·��
    QSize buttonSizeForNe = buttonNew->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapNe = pixmapNe.scaled(buttonSizeForNe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonNew->setIcon(QIcon(pixmapNe));
    buttonNew->setIconSize(buttonSizeForNe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    
    QPixmap pixmapLoading1("Icon/loading.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading1 = imgOriginal->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading1 = pixmapLoading1.scaled(buttonSizeForLoading1/2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgOriginal->setPixmap(pixmapLoading1);
    imgOriginal->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ

    QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
    QPixmap pixmapLoading2("Icon/loading2.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading2 = imgEdge->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading2 = pixmapLoading2.scaled(buttonSizeForLoading2 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgEdge->setPixmap(pixmapLoading2);
    imgEdge->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ

    QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
    QPixmap pixmapLoading3("Icon/loading3.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading3 = imgRotate->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading3 = pixmapLoading3.scaled(buttonSizeForLoading3 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgRotate->setPixmap(pixmapLoading3);
    imgRotate->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ

    QLabel* imgErase = this->findChild<QLabel*>("imgErase");
    QPixmap pixmapLoading4("Icon/loading4.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading4 = imgOriginal->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading4 = pixmapLoading4.scaled(buttonSizeForLoading4 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgErase->setPixmap(pixmapLoading4);
    imgErase->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ


    QTreeView* fileTreeView = this->findChild<QTreeView*>("treeView");
    connect(fileTreeView, &QTreeView::doubleClicked, this, &NKUexperimenter::onFileDoubleClicked); // ����˫���ź�
    model = new QFileSystemModel(this);
    fileTreeView->setModel(model);
    // ������ʾ�ĸ�Ŀ¼
    model->setRootPath(QDir::homePath());
    fileTreeView->setRootIndex(model->index(QDir::homePath()));
}

void NKUexperimenter::buttonUploadClicked()
{
    filePath = QFileDialog::getOpenFileName(this,
        tr("�ϴ��ļ�"),
        "",
        tr("Image Files (*.png *.jpg )")); // �����û�ֻ��ѡ��ͼƬ�ļ�
    //����Image����
    delete imgToProcess;
    try {
        imgToProcess = new ImageCV(filePath.toStdString());
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
        return;
    }
    if (!filePath.isEmpty()) {
        // ʹ�� QPixmap ����ͼƬ
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            // �ҵ���Ϊ imgOriginal �� QLabel �ؼ�
            QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgOriginal) 
            {
                // ��ȡ QLabel �ĳߴ�
                QSize labelSize = imgOriginal->size();

                // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
                QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // ���� QLabel ��ʾ���ź��ͼƬ
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
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: ") + filePath);
        }
    }
}
void NKUexperimenter::buttonGenerateClicked()
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

        if (!imgEdgeQP.isNull())
        {
            // �ҵ���Ϊ imgEdge �� QLabel �ؼ�
            QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgEdge)
            {
                // ��ȡ QLabel �ĳߴ�
                QSize labelSize = imgEdge->size();

                // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
                QPixmap scaledPixmap = imgEdgeQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // ���� QLabel ��ʾ���ź��ͼƬ
                imgEdge->setPixmap(scaledPixmap);

            }
            else
            {
                QMessageBox::warning(this, tr("Warning"), tr("Failed to find ") );
            }

        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: "));
        }
        if (!imgRotateQP.isNull())
        {
            // �ҵ���Ϊ imgEdge �� QLabel �ؼ�
            QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
            //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            if (imgRotate)
            {
                // ��ȡ QLabel �ĳߴ�
                QSize labelSize = imgRotate->size();

                // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
                QPixmap scaledPixmap = imgRotateQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // ���� QLabel ��ʾ���ź��ͼƬ
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
void NKUexperimenter::buttonRetryClicked()
{
    double angle = imgToProcess->getRotateAngle(imgToProcess->getImgAfterRotate());
    Mat imgRotate=imgToProcess->rotate(angle);
    QImage imgRotateQI = MatToQImage(imgRotate);
    QPixmap imgRotateQP = QPixmap::fromImage(imgRotateQI);
    if (!imgRotateQP.isNull())
    {
        // �ҵ���Ϊ imgEdge �� QLabel �ؼ�
        QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
        //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
        if (imgRotate)
        {
            // ��ȡ QLabel �ĳߴ�
            QSize labelSize = imgRotate->size();

            // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
            QPixmap scaledPixmap = imgRotateQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            // ���� QLabel ��ʾ���ź��ͼƬ
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
void NKUexperimenter::buttonEraseClicked()
{
    imgToProcess->eraseText();
    QImage imgEraseQI = MatToQImage(imgToProcess->getImgOutput());
    QPixmap imgEraseQP = QPixmap::fromImage(imgEraseQI);
    if (!imgEraseQP.isNull())
    {
        // �ҵ���Ϊ imgEdge �� QLabel �ؼ�
        QLabel* imgErase = this->findChild<QLabel*>("imgErase");
        //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
        if (imgErase)
        {
            // ��ȡ QLabel �ĳߴ�
            QSize labelSize = imgErase->size();

            // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
            QPixmap scaledPixmap = imgEraseQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            // ���� QLabel ��ʾ���ź��ͼƬ
            imgErase->setPixmap(scaledPixmap);

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
void NKUexperimenter::buttonDownloadClicked()
{
   
    QPixmap myPixmap = imgToProcess->imgToSave;
    if (!myPixmap.isNull())
    {
        QString savePath = QFileDialog::getSaveFileName(nullptr,
            tr("save"),
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
void NKUexperimenter::buttonNewClicked() 
{
    // �رյ�ǰ����
    this->close();

    // ��������ʾ�´���
    NKUexperimenter* newWindow = new NKUexperimenter();
    newWindow->show();
}
QImage NKUexperimenter::MatToQImage(const cv::Mat& mat)
{
    QImage img;
    int chana = mat.channels();
    /// ����ͨ������ͬ���ı䲻ͬ��װ����ʽ
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
        /// ��ͨ�����Ҷ�ͼ
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
    QMainWindow::resizeEvent(event); // ʼ�����ȵ��û�����¼�������

    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
    QPixmap pixmapUp("Icon/upload.png"); // ԭʼͼƬ·��
    QSize buttonSizeforUp = buttonUpload->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapUp = pixmapUp.scaled(buttonSizeforUp, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonUpload->setIcon(QIcon(pixmapUp));
    buttonUpload->setIconSize(buttonSizeforUp); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonGenerate = this->findChild<QPushButton*>("buttonGenerate");
    QPixmap pixmapGe("Icon/generate.png"); // ԭʼͼƬ·��
    QSize buttonSizeforGe = buttonGenerate->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapGe = pixmapGe.scaled(buttonSizeforGe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonGenerate->setIcon(QIcon(pixmapGe));
    buttonGenerate->setIconSize(buttonSizeforGe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonRetry = this->findChild<QPushButton*>("buttonRetry");
    QPixmap pixmapRe("Icon/retry.png"); // ԭʼͼƬ·��
    QSize buttonSizeForRe = buttonRetry->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapRe = pixmapRe.scaled(buttonSizeForRe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonRetry->setIcon(QIcon(pixmapRe));
    buttonRetry->setIconSize(buttonSizeForRe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonErase = this->findChild<QPushButton*>("buttonErase");
    QPixmap pixmapEr("Icon/erase.png"); // ԭʼͼƬ·��
    QSize buttonSizeForEr = buttonErase->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapEr = pixmapEr.scaled(buttonSizeForEr, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonErase->setIcon(QIcon(pixmapEr));
    buttonErase->setIconSize(buttonSizeForEr); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonDownload = this->findChild<QPushButton*>("buttonDownload");
    QPixmap pixmapDo("Icon/download.png"); // ԭʼͼƬ·��
    QSize buttonSizeForDo = buttonDownload->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapDo = pixmapDo.scaled(buttonSizeForDo, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonDownload->setIcon(QIcon(pixmapDo));
    buttonDownload->setIconSize(buttonSizeForDo); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QPushButton* buttonNew = this->findChild<QPushButton*>("buttonNew");
    QPixmap pixmapNe("Icon/new.png"); // ԭʼͼƬ·��
    QSize buttonSizeForNe = buttonNew->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapNe = pixmapNe.scaled(buttonSizeForNe, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    buttonNew->setIcon(QIcon(pixmapNe));
    buttonNew->setIconSize(buttonSizeForNe); // ȷ��ͼ��ߴ��밴ť�ߴ�һ��

    QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
    if (imgOriginal)
    {
        if (!filePath.isEmpty())
        {
            // ʹ�� QPixmap ����ͼƬ
            QPixmap pixmap(filePath);
            // showImage("imgOriginal", pixmap);
            if (!pixmap.isNull())
            {
                // �ҵ���Ϊ imgOriginal �� QLabel �ؼ�
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
                if (imgOriginal)
                {
                    // ��ȡ QLabel �ĳߴ�
                    QSize labelSize = imgOriginal->size();

                    // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
                    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                    // ���� QLabel ��ʾ���ź��ͼƬ
                    imgOriginal->setPixmap(scaledPixmap);

                }
            }
        }
    }
    QPixmap pixmapLoading1("Icon/loading.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading1 = imgOriginal->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading1 = pixmapLoading1.scaled(buttonSizeForLoading1/2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgOriginal->setPixmap(pixmapLoading1);

    QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
    QPixmap pixmapLoading2("Icon/loading2.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading2 = imgEdge->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading2 = pixmapLoading2.scaled(buttonSizeForLoading2 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgEdge->setPixmap(pixmapLoading2);
    imgEdge->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ

    QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
    QPixmap pixmapLoading3("Icon/loading3.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading3 = imgRotate->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading3 = pixmapLoading3.scaled(buttonSizeForLoading3 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgRotate->setPixmap(pixmapLoading3);
    imgRotate->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ

    QLabel* imgErase = this->findChild<QLabel*>("imgErase");
    QPixmap pixmapLoading4("Icon/loading4.png"); // ԭʼͼƬ·��
    QSize buttonSizeForLoading4 = imgOriginal->size(); // ��ȡ��ť�ĵ�ǰ��С
    pixmapLoading4 = pixmapLoading4.scaled(buttonSizeForLoading4 / 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imgErase->setPixmap(pixmapLoading4);
    imgErase->setAlignment(Qt::AlignCenter); // ˮƽ�ʹ�ֱ���ж���ͼƬ
}
void NKUexperimenter::onFileDoubleClicked(const QModelIndex& index) {
    // ���˫�����ļ��Ƿ���ͼƬ��ʽ
    QString filePath = model->filePath(index);
    QFileInfo fileInfo(filePath);
    if (fileInfo.suffix().compare("png", Qt::CaseInsensitive) == 0 ||
        fileInfo.suffix().compare("jpg", Qt::CaseInsensitive) == 0 )
    {
        // TODO: ʵ���ϴ��߼�
        delete imgToProcess;
        try {
            imgToProcess = new ImageCV(filePath.toStdString());
        }
        catch (const std::exception& e) {
            QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
            return;
        }
        if (!filePath.isEmpty()) {
            // ʹ�� QPixmap ����ͼƬ
            QPixmap pixmap(filePath);
            if (!pixmap.isNull()) {
                // �ҵ���Ϊ imgOriginal �� QLabel �ؼ�
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
                if (imgOriginal)
                {
                    // ��ȡ QLabel �ĳߴ�
                    QSize labelSize = imgOriginal->size();

                    // ���� QLabel �ĳߴ�����ͼƬ�����ֿ�߱�
                    QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                    // ���� QLabel ��ʾ���ź��ͼƬ
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
        QMessageBox::warning(this, tr("Warning"), tr("Please select an image file."));
    }
}
NKUexperimenter::~NKUexperimenter()
{
    delete imgToProcess;
    // ���ٶ���ʱ��������������еĻ���
}