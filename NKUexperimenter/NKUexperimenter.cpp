#include "NKUexperimenter.h"
#include "ui_NKUexperimenter.h"
#include "imgClass.h"
NKUexperimenter::NKUexperimenter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // 使用 findChild 来获取按钮的指针
    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
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
}

void NKUexperimenter::buttonUploadClicked()
{
    file_path = QFileDialog::getOpenFileName(this,
        tr("上传文件"),
        "",
        tr("Image Files (*.png *.jpg )")); // 限制用户只能选择图片文件
    //创建Image对象
    delete imgToProcess;
    try {
        imgToProcess = new ImageCV(file_path.toStdString());
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
        return;
    }
    if (!file_path.isEmpty()) {
        // 使用 QPixmap 加载图片
        QPixmap pixmap(file_path);
        if (!pixmap.isNull()) {
            // 找到名为 imgOriginal 的 QLabel 控件
            QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
            if (imgOriginal) {
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
            QMessageBox::warning(this, tr("Warning"), tr("Failed to load image: ") + file_path);
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
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
            if (imgEdge)
            {
                // 获取 QLabel 的尺寸
                QSize labelSize = imgEdge->size();

                // 根据 QLabel 的尺寸缩放图片，保持宽高比
                QPixmap scaledPixmap = imgEdgeQP.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                // 设置 QLabel 显示缩放后的图片
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
            // 找到名为 imgEdge 的 QLabel 控件
            QLabel* imgRotate = this->findChild<QLabel*>("imgRotate");
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
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
QImage NKUexperimenter::MatToQImage(const cv::Mat& mat) {
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
    QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
    if (imgOriginal)
    {
        if (!file_path.isEmpty())
        {
            // 使用 QPixmap 加载图片
            QPixmap pixmap(file_path);
            // showImage("imgOriginal", pixmap);
            if (!pixmap.isNull())
            {
                // 找到名为 imgOriginal 的 QLabel 控件
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
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
}
NKUexperimenter::~NKUexperimenter()
{
    //delete imgToProcess;
    // 销毁对象时的清理工作（如果有的话）
}