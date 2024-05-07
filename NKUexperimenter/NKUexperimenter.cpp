#include "NKUexperimenter.h"
#include "ui_NKUexperimenter.h"
#include "imgClass.h"
NKUexperimenter::NKUexperimenter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // ʹ�� findChild ����ȡ��ť��ָ��
    QPushButton* buttonUpload = this->findChild<QPushButton*>("buttonUpload");
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
}

void NKUexperimenter::buttonUploadClicked()
{
    file_path = QFileDialog::getOpenFileName(this,
        tr("�ϴ��ļ�"),
        "",
        tr("Image Files (*.png *.jpg )")); // �����û�ֻ��ѡ��ͼƬ�ļ�
    //����Image����
    delete imgToProcess;
    try {
        imgToProcess = new ImageCV(file_path.toStdString());
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to create Image object: ") + QString::fromStdString(e.what()));
        return;
    }
    if (!file_path.isEmpty()) {
        // ʹ�� QPixmap ����ͼƬ
        QPixmap pixmap(file_path);
        if (!pixmap.isNull()) {
            // �ҵ���Ϊ imgOriginal �� QLabel �ؼ�
            QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
            if (imgOriginal) {
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
            // �ҵ���Ϊ imgEdge �� QLabel �ؼ�
            QLabel* imgEdge = this->findChild<QLabel*>("imgEdge");
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
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
            //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
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
QImage NKUexperimenter::MatToQImage(const cv::Mat& mat) {
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
    QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
    if (imgOriginal)
    {
        if (!file_path.isEmpty())
        {
            // ʹ�� QPixmap ����ͼƬ
            QPixmap pixmap(file_path);
            // showImage("imgOriginal", pixmap);
            if (!pixmap.isNull())
            {
                // �ҵ���Ϊ imgOriginal �� QLabel �ؼ�
                QLabel* imgOriginal = this->findChild<QLabel*>("imgOriginal");
                //QLabel* imgCanny = this->findChild<QLabel*>("imgCanny");
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
}
NKUexperimenter::~NKUexperimenter()
{
    //delete imgToProcess;
    // ���ٶ���ʱ��������������еĻ���
}