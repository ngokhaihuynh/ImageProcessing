#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QPixmap"
#include "QLabel"
#include <QDebug>
#include <cstdlib>
#include "QMdiSubWindow"
#include "imagewidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbtnBowse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "E:\\bakupa\\USB\\2024-2025\\XuLyAnh\\Images",
                                                    "All Files (*.*);;BMP Files (*.bmp);;JPEG Files (*.jpeg);;PPM Files (*.ppm);;PNG Files (*.png);;JPG Files (*.jpg)");


    if (filename.isEmpty()) {
        return;
    }

    ui->ln_filename->setText(filename);

    // Tạo QPixmap từ file
    QPixmap pixmap(filename);

    // Kích thước mới mà bạn muốn
    int newWidth = 400;  // ví dụ: 400 pixels rộng
    int newHeight = 300; // ví dụ: 300 pixels cao

    // Thay đổi kích thước QPixmap
    QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

    QLabel *label = new QLabel();
    label->setPixmap(scaledPixmap);
    label->setWindowTitle(QFileInfo(filename).fileName());

}


void MainWindow::DisplayImage(QImage &img, QString title){
    QLabel *label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(img));
    label -> setWindowTitle(title);
    label -> show();
}

void MainWindow::on_bt_HisSlide_Gray_clicked()
{
    QString filename = ui -> ln_filename -> text();
    QImage image_in(filename); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    int c = ui -> ln_c -> text().toInt(); // doi chuoi thanh so
    for(int x = 0; x < image_in.width(); x++)
        for(int y = 0; y < image_in.height();y++){
            QRgb color = image_in.pixel(x, y); // lay mau gia tri pixel(x, y)
            int gray_in = qGray(color); // doi gia tri mau thanh muc xam
            int gray_out = gray_in + c; // thay doi do sang toi
            if(gray_out > 255)
                gray_out = 255;
            else if(gray_out < 0)
                gray_out = 0;
            QRgb color_out = qRgb(gray_out, gray_out, gray_out); // anh xam (R=G=B)
            image_out.setPixel(x, y, color_out);
            image_in.setPixel(x, y, color);
        }
    // Thay đổi kích thước ảnh đầu ra
       int newWidth = image_out.width() / 2;
       int newHeight = image_out.height() / 2;
       QImage image_out_scaled = image_out.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

       QImage image_in_scaled = image_in.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
       // Hiển thị ảnh gốc và ảnh đã xử lý
    //DisplayImage(image_in, QFileInfo(filename).fileName());
     DisplayImage(image_in_scaled, QFileInfo(filename).fileName());
    //DisplayImage(image_out, QFileInfo(filename).fileName()+ "_His_Slide");
    DisplayImage(image_out_scaled, QFileInfo(filename).fileName() + "_His_Slide");
}

void MainWindow::on_bt_HisSlide_Color_clicked()
{
    QString filename = ui -> ln_filename -> text();
    QImage image_in(filename); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_ARGB32);
    int c = ui -> ln_c -> text().toInt(); // doi chuoi thanh so
    for(int x = 0; x < image_in.width(); x++)
        for(int y = 0; y < image_in.height();y++){
            QRgb rgb = image_in.pixel(x, y);
            QColor color_in(rgb);
            int h, s, v;
            color_in.getHsv(&h, &s, &v); // lay 3 thanh phan hsv tu color
            int v_out = v + c;
            if(v_out > 255)
                v_out = 255;
            else if(v_out < 0)
                v_out = 0;
            QColor color_out = QColor::fromHsv(h, s, v_out);
            image_out.setPixel(x, y, color_out.rgb());
        }
    DisplayImage(image_in,QFileInfo(filename).fileName());
    DisplayImage(image_out,QFileInfo(filename).fileName() + "_His_Slide");
}

// ÂM BẢN CỦA ẢNH XÁM
void MainWindow::on_bt_Xam_AmBan_clicked()
{

    QImage image_in(ui ->ln_filename -> text()); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    for(int i = 0; i< image_in.width(); i++){
        for(int j = 0; j < image_in.height(); j++){
            QRgb rgb = image_in.pixel(i, j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i, j, color_in);
            int out = 255 - gray;
            if(out > 255) out = 255;
            else if(out < 0) out = 0;

            QRgb color_out = qRgb(out, out, out);
            image_out.setPixel(i, j, color_out);
        }
    }
    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in));
    label_in -> show();
    QLabel* label_out = new QLabel();
    label_out -> setPixmap(QPixmap::fromImage(image_out));
    label_out -> show();

}

// ẢNH ÂM BẢNG CỦA ẢNH MÀU
void MainWindow::on_bt_Mau_AmBan_clicked()
{
    QImage image_in(ui ->ln_filename -> text()); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    for(int i = 0; i< image_in.width(); i++){
        for(int j = 0; j < image_in.height(); j++){
            QRgb rgb = image_in.pixel(i, j);
            QColor color(rgb);
            int red = color.red();
            int green = color.green();
            int blue =  color.blue();
            int n_red = 255 - red;
            int n_green = 255 - green;
            int n_blue = 255 - blue;
            QRgb color_out = qRgb(n_red, n_green, n_blue);
            image_out.setPixel(i, j, color_out);

        }
    }
    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in));
    label_in -> show();
    QLabel* label_out = new QLabel();
    label_out -> setPixmap(QPixmap::fromImage(image_out));
    label_out -> show();

}

// PHÂN NGƯỠNG
void MainWindow::on_btn_PhanNguong_clicked()
{
    QImage image_in(ui ->ln_filename -> text()); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    int c = ui -> LinePhanNguong -> text().toInt();
    for(int i = 0; i< image_in.width(); i++){
        for(int j = 0; j < image_in.height(); j++){
            QRgb rgb = image_in.pixel(i, j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i, j, color_in);
            int out = gray;

            if(out > c) out = 255;
            else if(out < c) out = 0;

            QRgb color_out = qRgb(out, out, out);
            image_out.setPixel(i, j, color_out);

        }

    }
    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in));
    label_in -> show();

    QLabel* label_out = new QLabel();
    label_out -> setPixmap(QPixmap::fromImage(image_out));
    label_out -> show();
}

// VẼ HISTOGRAM CHO ẢNH XÁM
void MainWindow::Histogram_GrayImage(const QImage &img, const int &his_height){
    int h[256];
    for (int i = 0; i < 256; i++)
        h[i] = 0;
    QImage image_in(img);
    for(int x = 0; x < img.width(); x++)
        for(int  y = 0; y < img.height(); y++){
            QRgb color = img.pixel(x, y);
            int gray = qGray(color);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(x, y, color_in);
            h[gray]++;
        }
    int max = 0;
    for(int i = 0; i < 256; i++)
        if(h[i] > max) max = h[i];
    QImage img_his = QImage(256, his_height, QImage::Format_RGB888);
    img_his.fill(Qt::white);

    int lineHeight;
    for(int i = 0; i < 256; i++){
        lineHeight = his_height * h[i]/max;
        for(int j = his_height - 1; j >= his_height - 1 - lineHeight; j--)
            img_his.setPixel(i, j, qRgb(0, 0, 0));
    }

    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in));
    label_in -> show();

    QLabel* label_out = new QLabel();
    label_out -> setPixmap(QPixmap::fromImage(img_his));
    label_out -> show();

}

// VẼ HISTOGRAM CHO ẢNH MÀU
void MainWindow::Histogram_ColorImage(const QImage &img, const int &his_height){
    int hr[256];
    int hg[256];
    int hb[256];
    for(int i = 0; i < 256; i++){
        hr[i] = 0;
        hg[i] = 0;
        hb[i] = 0;
    }
    QImage image_in(img);
    for(int x = 0; x < img.width(); x++)
        for(int y =0; y < img.height(); y++)
        {
            QRgb color = img.pixel(x, y);
            int green = qGreen(color);
            int red = qRed(color);
            int blue = qBlue(color);
            hr[red]++;
            hg[green]++;
            hb[blue]++;
        }
    int maxr = 0, maxg = 0, maxb =0;
    for(int i =0; i < 256; i++)
    {
        if(hr[i] > maxr) maxr = hr[i];
        if(hg[i] > maxg) maxg = hg[i];
        if(hb[i] > maxb) maxb = hb[i];
    }

    QImage img_hisr = QImage(256, his_height, QImage::Format_RGB888);
    img_hisr.fill(Qt::white);

    QImage img_hisg = QImage(256, his_height, QImage::Format_RGB888);
    img_hisg.fill(Qt::white);

    QImage img_hisb = QImage(256, his_height, QImage::Format_RGB888);
    img_hisb.fill(Qt::white);

    int liner, lineg, lineb;
    for(int i =0; i < 256; i++){
        liner = his_height * hr[i]/maxr;
        lineg = his_height * hg[i]/maxg;
        lineb = his_height * hb[i]/maxb;

        for(int j = his_height - 1; j >= his_height - 1 -liner; j--)
            img_hisr.setPixel(i, j, qRgb(255,0,0));

        for(int j = his_height - 1; j >= his_height - 1 -lineg; j--)
            img_hisg.setPixel(i, j, qRgb(0,255,0));

        for(int j = his_height - 1; j >= his_height - 1 -lineb; j--)
            img_hisb.setPixel(i, j, qRgb(0,0,255));

    }

    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in));
    label_in -> show();

    QLabel* label_out1 = new QLabel();
    label_out1 -> setPixmap(QPixmap::fromImage(img_hisr));
    label_out1 -> show();

    QLabel* label_out2 = new QLabel();
    label_out2 -> setPixmap(QPixmap::fromImage(img_hisg));
    label_out2 -> show();

    QLabel* label_out3 = new QLabel();
    label_out3 -> setPixmap(QPixmap::fromImage(img_hisb));
    label_out3 -> show();



}


void MainWindow::on_btn_Histogram_AnhXam_clicked()
{
    QImage img(ui ->ln_filename -> text());
    Histogram_GrayImage(img, 200);
}

void MainWindow::on_btn_Histogram_AnhMau_clicked()
{

    QImage img(ui ->ln_filename -> text());
    Histogram_ColorImage(img, 200);
}

void MainWindow::on_btn_XuLy_AnhXam_clicked()
{
    QImage image_in(ui ->ln_filename -> text()); // doc anh tu file
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    float c = ui -> LineDoTuongPhan -> text().toFloat();
    for(int i = 0; i< image_in.width(); i++){
        for(int j = 0; j < image_in.height(); j++){
            QRgb rgb = image_in.pixel(i, j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i, j, color_in);
            int out = gray * c;
            if(out > 255) out = 255;
            else if(out < 0) out = 0;

            QRgb color_out = qRgb(out, out, out);
            image_out.setPixel(i, j, color_out);
        }
    }
    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
    label_in -> show();
    QLabel* label_out = new QLabel();
    label_out -> setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
    label_out -> show();

}

void MainWindow::on_btn_XyLy_AnhMau_clicked()
{
        QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
        float c = ui->LineDoTuongPhan->text().toFloat();

        // Duyệt qua từng pixel của ảnh đầu vào
        for(int i = 0; i < image_in.width(); i++){
            for(int j = 0; j < image_in.height(); j++){
                QRgb rgb = image_in.pixel(i, j);
                int red = qRed(rgb);
                int green = qGreen(rgb);
                int blue = qBlue(rgb);

                int red_out = red * c;
                int green_out = green * c;
                int blue_out = blue * c;

                // Đảm bảo giá trị không vượt quá 255 hoặc dưới 0
                red_out = qBound(0, red_out, 255);
                green_out = qBound(0, green_out, 255);
                blue_out = qBound(0, blue_out, 255);

                // Tạo màu mới và thiết lập cho ảnh đầu ra
                QRgb color_out = qRgb(red_out, green_out, blue_out);
                image_out.setPixel(i, j, color_out);
            }
        }

        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
        label_in->show();

        QLabel* label_out = new QLabel();
        label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640, 480)));
        label_out->show();
}

QImage MainWindow::SuaChuaHistogram(const QImage &imgin){
    int max = 0;
    int min = 255;
    QImage image_in(imgin);
    QImage image_out(image_in.width(), image_in.height(),QImage::Format_ARGB32);

    for(int x =0; x < imgin.width(); x++){
        for(int y =0; y < imgin.height(); y++){
            QRgb color = imgin.pixel(x, y);
            int gray = qGray(color);
            QRgb color_in = qGray(gray, gray, gray);
            image_in.setPixel(x, y, color_in);
            if(gray > max) max = gray;
            if(gray < min) min = gray;
        }
    }

    for(int x =0; x < imgin.width(); x++){
        for(int y =0; y < imgin.height(); y++){

            int newgray =0;
            QRgb color = imgin.pixel(x, y);
            int gray = qGray(color);
            newgray = (((gray - min)*255)/(max - min));
            QRgb color_out = qRgb(newgray, newgray, newgray);
            image_out.setPixel(x, y, color_out);
        }
    }
    return image_out;

}

void MainWindow::on_btn_BienDoiTuyenTinh_clicked()
{
    QImage img(ui -> ln_filename -> text());
    Histogram_GrayImage(img, 200);

    QImage new_img = SuaChuaHistogram(img);
    Histogram_GrayImage(new_img, 200);
}


// Can bang histogram
QImage MainWindow::CanBangHistogram(const QImage &imgin){
    double h[256];
    for(int i = 0; i < 256; i++)
        h[i] = 0;
    QImage image_in(imgin);
    QImage image_out(image_in.width(), imgin.height(), QImage::Format_ARGB32);
    for(int x = 0; x < imgin.width(); x++)
    {
        for(int y = 0; y < imgin.height(); y++)
        {
            QRgb color = imgin.pixel(x, y);
            int gray = qGray(color);
            h[gray]++;
        }
    }

    double hn[256];
    int numpix = imgin.width() * imgin.height();
    for(int i = 0; i < 256; i++)
        hn[i] = h[i]/(numpix);

    double c[256];
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < i; j++)
        {
            c[i] = c[i] + hn[j];
        }
    }

    for(int x = 0; x < imgin.width(); x++)
    {
        for(int y = 0; y < imgin.height(); y++)
        {
            QRgb color = imgin.pixel(x, y);
            int gray = qGray(color);
            int newgray = (int)(c[gray] * 256);
            QRgb color_out = qRgb(newgray, newgray, newgray);
            image_out.setPixel(x, y, color_out);
        }
    }
    return image_out;

}

void MainWindow::on_btn_CanBanghistogram_clicked()
{
    QImage img(ui -> ln_filename -> text());
    Histogram_GrayImage(img, 200);

    QImage new_img = CanBangHistogram(img);
    Histogram_GrayImage(new_img, 200);
}

void MainWindow::on_btn_loctrungbinh_clicked()
{
   QImage image_in(ui->ln_filename->text());
  //khai bao cho mat na 3x3
   int size = ui ->ln_Kichthuocmatna->text().toInt();
   int margin = (size - 1)/2;
   int cells = size* size;

   QImage image_out(image_in.width() - margin, image_in.height() - margin, QImage::Format_RGB32);
   int sumR, sumG, sumB;
   QColor color;
   for(int x = margin; x < image_in.width() - margin; x++)
       for(int y = margin; y < image_in.height() - margin; y++){
           sumR = sumG = sumB = 0;
           for(int i =-margin; i<= margin; i++)
               for(int j = -margin; j<=margin; j++){
                   color = image_in.pixel(x+i, y+j);
                   sumR += color.red();
                   sumG += color.green();
                   sumB += color.blue();
               }
           image_out.setPixel(x,y,qRgb(sumR/cells, sumG/cells, sumB/cells));
       }

   QLabel* label_in = new QLabel();
   label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
   label_in -> setToolTip("Hinh goc");
   label_in -> show();

   QLabel* label = new QLabel();
   label -> setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
   label -> setToolTip("Hinh da xu ly");
   label -> show();
   QString fname = QFileDialog::getSaveFileName();
   image_out.save(fname);


}


void MainWindow::on_btn_Loctrungvi_clicked()
{
    QImage image_in(ui->ln_filename->text());
   //khai bao cho mat na 3x3
    int size = ui ->ln_Kichthuocmatna->text().toInt();
    int margin = (size - 1)/2;
    int cells = size* size;

    QImage image_out(image_in.width() - margin, image_in.height() - margin, QImage::Format_RGB32);

    for(int x = margin; x < image_in.width() - margin; x++)
        for(int y = margin; y < image_in.height() - margin; y++){
            int h[cells];
            int k =0;
            for(int i =-margin; i<= margin; i++)
                for(int j = -margin; j<=margin; i++){
                    QRgb color = image_in.pixel(x+i, y+j);
                    int gray = qGray(color);
                    h[k] = gray;
                    k++;
                }
            qSort(h, h+cells);
            int meanV = h[(cells - 1)/2];
            image_out.setPixel(x,y,qRgb(meanV, meanV, meanV));
        }

    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in -> setToolTip("Hinh goc");
    label_in -> show();

    QLabel* label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
    label -> setToolTip("Hinh da xu ly");
    label -> show();
    QString fname = QFileDialog::getSaveFileName();
    image_out.save(fname);
}


int MainWindow::Random(int n)
{
    return rand()%n;
}

QImage MainWindow::imNoise_Gray(QImage &image_in, float level)
{
    QImage image_out = image_in;
    int noisePoint = image_in.width() * image_in.height()* level;
    for(int i = 0; i< noisePoint; i++)
    {
        int x = Random(image_in.width());
        int y = Random(image_in.height());
        int a = Random(2);
        if(a == 0)
            image_out.setPixel(x,y,qRgb(0, 0, 0));
        else
            image_out.setPixel(x, y,qRgb(255,255,255));
    }
    return image_out;
}

void MainWindow::on_btn_Themnhieumuoitieu_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_inGray(image_in.width(), image_in.height(), QImage::Format_RGB32);

    for(int i = 0; i < image_in.width(); i++)
        for(int j = 0; j < image_in.height(); i++){
           QRgb rgb = image_in.pixel(i, j);
           int gray = qGray(rgb);
           QRgb color_in = qRgb(gray, gray, gray);
           image_inGray.setPixel(i,j,color_in);

        }

    float percentage = (ui -> ln_tilenhieu->text().toFloat())/100;
    QImage image_out = imNoise_Gray(image_inGray, percentage);

    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_inGray.scaled(1024, 768)));
    label_in -> setToolTip("Hinh goc");
    label_in -> show();

    QLabel *label = new QLabel();
    label -> setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
    label -> setToolTip("Hinh da xu ly");
    label -> show();
//    QString fname = QFileDialog::getSaveFileName();
//    image_out.save(fname);
}


// Loc gradient anh xam
void MainWindow::on_btn_Loc_Gradient_clicked()
{
    QImage image_in(ui -> ln_filename -> text());
    QImage image_out_Gx(image_in.width() - 1, image_in.height(), QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width(), image_in.height() - 1, QImage::Format_RGB32);

    for(int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height(); j++)
        {
            QRgb color1 = image_in.pixel(i, j);
            int gray1 = qGray(color1);

            QRgb color_in = qRgb(gray1, gray1, gray1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i+1, j);
            int gray2 = qGray(color2);
            int newgray = abs (gray2 - gray1);
            image_out_Gx.setPixel(i, j, qRgb(newgray, newgray, newgray));

        }
    }

    for(int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height() - 1; j++)
        {
            QRgb color1 = image_in.pixel(i, j);
            int gray1 = qGray(color1);

            QRgb color_in = qRgb(gray1, gray1, gray1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i, j+1);
            int gray2 = qGray(color2);
            int newgray = abs (gray2 - gray1);
            image_out_Gy.setPixel(i, j, qRgb(newgray, newgray, newgray));

        }
    }

    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in -> show();

    QLabel *label_Gx = new QLabel();
    label_Gx -> setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
    label_Gx-> show();

    QLabel *label_Gy = new QLabel();
    label_Gy -> setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
    label_Gy-> show();


}


// loc Robert cho anh xam
void MainWindow::on_btn_Loc_Robert_clicked()
{
    QImage image_in(ui -> ln_filename -> text());
    QImage image_out_Gx(image_in.width() - 1, image_in.height() - 1, QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width() - 1, image_in.height() - 1, QImage::Format_RGB32);

    for(int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height() -1; j++)
        {
            QRgb color1 = image_in.pixel(i, j);
            int gray1 = qGray(color1);

            QRgb color2 = image_in.pixel(i+1, j);
            int gray2 = qGray(color2);

            QRgb color3 = image_in.pixel(i, j+1);
            int gray3 = qGray(color3);

            QRgb color4 = image_in.pixel(i+1, j+1);
            int gray4 = qGray(color4);


            int newgray_gx = abs (gray1 - gray4);
            int newgray_gy = abs (gray2 - gray3);

            image_out_Gx.setPixel(i, j, qRgb(newgray_gx, newgray_gx, newgray_gx));

            image_out_Gy.setPixel(i, j, qRgb(newgray_gy, newgray_gy, newgray_gy));
        }
    }
    QLabel* label_in = new QLabel();
    label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in -> show();

    QLabel *label_Gx = new QLabel();
    label_Gx -> setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
    label_Gx-> show();

    QLabel *label_Gy = new QLabel();
    label_Gy -> setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
    label_Gy-> show();
}


// Loc Sobel cho anh xam
void MainWindow::on_btn_Loc_Sobel_clicked()
{
    QImage image_in(ui -> ln_filename -> text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2(image_in.width(), image_in.height(), QImage::Format_RGB32);

    int maskSize = 3;
        int margin = maskSize / 2;
        //int cells  = maskSize * maskSize;

        int mask[maskSize][maskSize];
        mask[0][0] = -1; mask[0][1] = 0; mask[0][2] = 1;
        mask[1][0] = -2; mask[1][1] = 0; mask[1][2] = 2;
        mask[2][0] = -1; mask[2][1] = 0; mask[2][2] = 1;

        int mask2[maskSize][maskSize];
        mask2[0][0] = -1; mask2[0][1] = -2; mask2[0][2] = -1;
        mask2[1][0] = 0; mask2[1][1] = 0; mask2[1][2] = 0;
        mask2[2][0] = 1; mask2[2][1] = 2; mask2[2][2] = 1;

        QRgb color;
        int sum1, sum2;
        for(int y = margin; y < image_in.height() - margin; y++)
            for(int x = margin; x < image_in.width() - margin; x++)
            {
                sum1=sum2 = 0;
                for(int j = -margin; j <= margin; j++)
                    for(int i = -margin; i <= margin; i++)
                    {
                        color = image_in.pixel(x + i, y + j);
                        int gray = qGray(color);
                        sum1 += gray * mask[j+margin][i+margin];
                        sum2 += gray * mask2[j+margin][i+margin];
                    }

                image_out.setPixel(x, y, qRgb(abs(sum1), abs(sum1), abs(sum1)));
                image_out2.setPixel(x, y, qRgb(abs(sum2), abs(sum2), abs(sum2)));
            }

        QLabel* label_in = new QLabel();
        label_in -> setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
        label_in -> show();

        QLabel *label_Gx = new QLabel();
        label_Gx -> setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
        label_Gx-> show();

        QLabel *label_Gy = new QLabel();
        label_Gy -> setPixmap(QPixmap::fromImage(image_out2.scaled(1024, 768)));
        label_Gy-> show();
}


// Loc Prewitt cho anh xam
void MainWindow::on_btn_Loc_Prewitt_clicked()
{
    // Đọc ảnh đầu vào
       QImage image_in(ui -> ln_filename -> text());
       QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
       QImage image_out2(image_in.width(), image_in.height(), QImage::Format_RGB32);

       int maskSize = 3;
       int margin = maskSize / 2;

       // Mặt nạ Prewitt cho trục x (Gx)
       int mask[maskSize][maskSize];
       mask[0][0] = -1; mask[0][1] = 0; mask[0][2] = 1;
       mask[1][0] = -1; mask[1][1] = 0; mask[1][2] = 1;
       mask[2][0] = -1; mask[2][1] = 0; mask[2][2] = 1;

       // Mặt nạ Prewitt cho trục y (Gy)
       int mask2[maskSize][maskSize];
       mask2[0][0] = -1; mask2[0][1] = -1; mask2[0][2] = -1;
       mask2[1][0] = 0;  mask2[1][1] = 0;  mask2[1][2] = 0;
       mask2[2][0] = 1;  mask2[2][1] = 1;  mask2[2][2] = 1;

       QRgb color;
       int sum1, sum2;

       // Duyệt qua từng pixel trong ảnh (trừ các biên)
       for(int y = margin; y < image_in.height() - margin; y++) {
           for(int x = margin; x < image_in.width() - margin; x++) {
               sum1 = sum2 = 0;

               // Tính toán tích chập với mặt nạ Prewitt theo Gx và Gy
               for(int j = -margin; j <= margin; j++) {
                   for(int i = -margin; i <= margin; i++) {
                       color = image_in.pixel(x + i, y + j);
                       int gray = qGray(color);  // Chuyển sang giá trị xám
                       sum1 += gray * mask[j+margin][i+margin];
                       sum2 += gray * mask2[j+margin][i+margin];
                   }
               }

               // Đặt pixel theo độ lớn gradient
               image_out.setPixel(x, y, qRgb(abs(sum1), abs(sum1), abs(sum1)));
               image_out2.setPixel(x, y, qRgb(abs(sum2), abs(sum2), abs(sum2)));
           }
       }

       // Hiển thị ảnh gốc và ảnh sau khi lọc
       QLabel* label_in = new QLabel();
       label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
       label_in->show();

       QLabel* label_Gx = new QLabel();
       label_Gx->setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
       label_Gx->show();

       QLabel* label_Gy = new QLabel();
       label_Gy->setPixmap(QPixmap::fromImage(image_out2.scaled(1024, 768)));
       label_Gy->show();
}


// Loc laplace cho anh xam
void MainWindow::on_btn_Loc_Laplace_clicked()
{
    // Đọc ảnh đầu vào
    QImage image_in(ui->ln_filename->text());
    QImage image_out_x(image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out_y(image_in.width(), image_in.height(), QImage::Format_RGB32);

    int maskSize = 3;
    int margin = maskSize / 2;

    // Mặt nạ Laplace cho trục x (Gx)
    int mask_x[maskSize][maskSize];
    mask_x[0][0] = 0; mask_x[0][1] = 1; mask_x[0][2] = 0;
    mask_x[1][0] = 1; mask_x[1][1] = -4; mask_x[1][2] = 1;
    mask_x[2][0] = 0; mask_x[2][1] = 1; mask_x[2][2] = 0;

    // Mặt nạ Laplace cho trục y (Gy)
    int mask_y[maskSize][maskSize];
    mask_y[0][0] = 1; mask_y[0][1] = -1; mask_y[0][2] = 1;
    mask_y[1][0] = 1;  mask_y[1][1] = -8;  mask_y[1][2] = 1;
    mask_y[2][0] = 1;  mask_y[2][1] = 1;  mask_y[2][2] = 1;

    QRgb color;
    int sum_x, sum_y;

    // Duyệt qua từng pixel trong ảnh (trừ các biên)
    for (int y = margin; y < image_in.height() - margin; y++) {
        for (int x = margin; x < image_in.width() - margin; x++) {
            sum_x = sum_y = 0;

            // Tính toán tích chập với mặt nạ Laplace
            for (int j = -margin; j <= margin; j++) {
                for (int i = -margin; i <= margin; i++) {
                    color = image_in.pixel(x + i, y + j);
                    int gray = qGray(color);  // Chuyển pixel sang mức xám
                    sum_x += gray * mask_x[j + margin][i + margin];
                    sum_y += gray * mask_y[j + margin][i + margin];

                }
            }

            // Đặt pixel theo độ lớn gradient


            // Chuẩn hóa giá trị về khoảng 0-255


            int laplaceValue_x = (abs(sum_x) < 0) ? 0 : ((abs(sum_x) > 255) ? 255 : abs(sum_x));
            //int laplaceValue_y = (abs(sum_y) < 0) ? 0 : ((abs(sum_y) > 255) ? 255 : abs(sum_y));
            int laplaceValue_y = qBound(0, sum_y + 128, 255);

            // Đặt pixel vào ảnh kết quả
           image_out_x.setPixel(x, y, qRgb(laplaceValue_x, laplaceValue_x, laplaceValue_x));
           image_out_y.setPixel(x, y, qRgb(laplaceValue_y, laplaceValue_y, laplaceValue_y));
        }
    }

    // Hiển thị ảnh gốc và ảnh sau khi lọc
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in->setWindowTitle("Ảnh gốc");
    label_in->show();

    QLabel* label_Gx = new QLabel();
    label_Gx->setPixmap(QPixmap::fromImage(image_out_x.scaled(1024, 768)));
    label_Gx->setWindowTitle("Kết quả Gx (Laplace)");
    label_Gx->show();

    QLabel* label_Gy = new QLabel();
    label_Gy->setPixmap(QPixmap::fromImage(image_out_y.scaled(1024, 768)));
    label_Gy->setWindowTitle("Kết quả Gy (Laplace)");
    label_Gy->show();
}

// Loc Gauss + Laplace cho anh xam
void MainWindow::on_btn_Loc_laplace_Gau_clicked()
{// Đọc ảnh đầu vào
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

    int maskSize = 5;
    int margin = maskSize / 2;

    // Mặt nạ Gaussian 5x5
    float gaussian_mask[5][5] = {
        { 1/273.0f,  4/273.0f,  6/273.0f,  4/273.0f,  1/273.0f },
        { 4/273.0f, 16/273.0f, 24/273.0f, 16/273.0f,  4/273.0f },
        { 6/273.0f, 24/273.0f, 36/273.0f, 24/273.0f,  6/273.0f },
        { 4/273.0f, 16/273.0f, 24/273.0f, 16/273.0f,  4/273.0f },
        { 1/273.0f,  4/273.0f,  6/273.0f,  4/273.0f,  1/273.0f }
    };

    // Mặt nạ Laplace 5x5
    int laplace_mask[5][5] = {
        { 0,  0, -1,  0,  0 },
        { 0, -1, -2, -1,  0 },
        { -1, -2, 16, -2, -1 },
        { 0, -1, -2, -1,  0 },
        { 0,  0, -1,  0,  0 }
    };

    QRgb color;
    float sum;

    // Lọc Gaussian
    QImage image_gaussian(image_in.size(), QImage::Format_RGB32);
    for (int y = margin; y < image_in.height() - margin; y++) {
        for (int x = margin; x < image_in.width() - margin; x++) {
            sum = 0.0f;
            for (int j = -margin; j <= margin; j++) {
                for (int i = -margin; i <= margin; i++) {
                    color = image_in.pixel(x + i, y + j);
                    int gray = qGray(color);
                    sum += gray * gaussian_mask[j + margin][i + margin];
                }
            }
            int gaussianValue = qBound(0, static_cast<int>(sum), 255);
            image_gaussian.setPixel(x, y, qRgb(gaussianValue, gaussianValue, gaussianValue));
        }
    }

    // Lọc Laplace
    for (int y = margin; y < image_gaussian.height() - margin; y++) {
        for (int x = margin; x < image_gaussian.width() - margin; x++) {
            sum = 0.0f;
            for (int j = -margin; j <= margin; j++) {
                for (int i = -margin; i <= margin; i++) {
                    color = image_gaussian.pixel(x + i, y + j);
                    int gray = qGray(color);
                    sum += gray * laplace_mask[j + margin][i + margin];
                }
            }
            int laplaceValue = qBound(0, static_cast<int>(sum), 255);
            image_out.setPixel(x, y, qRgb(laplaceValue, laplaceValue, laplaceValue));
        }
    }

    // Hiển thị ảnh kết quả
    QLabel* label_result = new QLabel();
    label_result->setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
    label_result->setWindowTitle("Kết quả Gauss + Laplace");
    label_result->show();
}


// lọc gradient cho anh mau
void MainWindow::on_btn_Gradient_color_clicked()
{
    // Đọc ảnh đầu vào
    QImage image_in(ui->ln_filename->text());
    QImage image_out_Gx(image_in.size(), QImage::Format_RGB32);
    QImage image_out_Gy(image_in.size(), QImage::Format_RGB32);

    // Tính gradient cho từng kênh màu
    for(int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height() - 1; j++)
        {
            // Lấy màu của pixel hiện tại
            QRgb color1 = image_in.pixel(i, j);
            int red1 = qRed(color1);
            int green1 = qGreen(color1);
            int blue1 = qBlue(color1);

            // Lấy màu của pixel bên phải
            QRgb color2 = image_in.pixel(i + 1, j);
            int red2 = qRed(color2);
            int green2 = qGreen(color2);
            int blue2 = qBlue(color2);

            // Tính gradient theo trục x (Gx)
            int gradient_red_x = abs(red2 - red1);
            int gradient_green_x = abs(green2 - green1);
            int gradient_blue_x = abs(blue2 - blue1);

            // Lấy màu của pixel bên dưới
            QRgb color3 = image_in.pixel(i, j + 1);
            int red3 = qRed(color3);
            int green3 = qGreen(color3);
            int blue3 = qBlue(color3);

            // Tính gradient theo trục y (Gy)
            int gradient_red_y = abs(red3 - red1);
            int gradient_green_y = abs(green3 - green1);
            int gradient_blue_y = abs(blue3 - blue1);

            // Tính giá trị màu cho ảnh Gx
            int final_red_Gx = qBound(0, gradient_red_x, 255);
            int final_green_Gx = qBound(0, gradient_green_x, 255);
            int final_blue_Gx = qBound(0, gradient_blue_x, 255);
            image_out_Gx.setPixel(i, j, qRgb(final_red_Gx, final_green_Gx, final_blue_Gx));

            // Tính giá trị màu cho ảnh Gy
            int final_red_Gy = qBound(0, gradient_red_y, 255);
            int final_green_Gy = qBound(0, gradient_green_y, 255);
            int final_blue_Gy = qBound(0, gradient_blue_y, 255);
            image_out_Gy.setPixel(i, j, qRgb(final_red_Gy, final_green_Gy, final_blue_Gy));
        }
    }

    // Hiển thị ảnh gốc
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in->setWindowTitle("Ảnh gốc");
    label_in->show();

    // Hiển thị kết quả Gx
    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
    label_Gx->setWindowTitle("Kết quả Gx (Gradient)");
    label_Gx->show();

    // Hiển thị kết quả Gy
    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
    label_Gy->setWindowTitle("Kết quả Gy (Gradient)");
    label_Gy->show();
}


// loc robert cho anh mau
void MainWindow::on_btn_Loc_RobertColor_clicked()
{
    // Đọc ảnh đầu vào
        QImage image_in(ui->ln_filename->text());
        QImage image_out_Gx(image_in.size(), QImage::Format_RGB32);
        QImage image_out_Gy(image_in.size(), QImage::Format_RGB32);

        // Duyệt qua từng pixel (trừ biên)
        for(int i = 0; i < image_in.width() - 1; i++)
        {
            for(int j = 0; j < image_in.height() - 1; j++)
            {
                // Lấy màu của pixel hiện tại
                QRgb color1 = image_in.pixel(i, j);
                int red1 = qRed(color1);
                int green1 = qGreen(color1);
                int blue1 = qBlue(color1);

                // Lấy màu của pixel bên phải
                QRgb color2 = image_in.pixel(i + 1, j);
                int red2 = qRed(color2);
                int green2 = qGreen(color2);
                int blue2 = qBlue(color2);

                // Lấy màu của pixel bên dưới
                QRgb color3 = image_in.pixel(i, j + 1);
                int red3 = qRed(color3);
                int green3 = qGreen(color3);
                int blue3 = qBlue(color3);

                // Lấy màu của pixel chéo
                QRgb color4 = image_in.pixel(i + 1, j + 1);
                int red4 = qRed(color4);
                int green4 = qGreen(color4);
                int blue4 = qBlue(color4);

                // Tính gradient theo Gx và Gy cho từng kênh màu
                int gradient_red_Gx = abs(red1 - red4);
                int gradient_green_Gx = abs(green1 - green4);
                int gradient_blue_Gx = abs(blue1 - blue4);

                int gradient_red_Gy = abs(red2 - red3);
                int gradient_green_Gy = abs(green2 - green3);
                int gradient_blue_Gy = abs(blue2 - blue3);

                // Tính giá trị màu cho ảnh Gx
                int final_red_Gx = qBound(0, gradient_red_Gx, 255);
                int final_green_Gx = qBound(0, gradient_green_Gx, 255);
                int final_blue_Gx = qBound(0, gradient_blue_Gx, 255);
                image_out_Gx.setPixel(i, j, qRgb(final_red_Gx, final_green_Gx, final_blue_Gx));

                // Tính giá trị màu cho ảnh Gy
                int final_red_Gy = qBound(0, gradient_red_Gy, 255);
                int final_green_Gy = qBound(0, gradient_green_Gy, 255);
                int final_blue_Gy = qBound(0, gradient_blue_Gy, 255);
                image_out_Gy.setPixel(i, j, qRgb(final_red_Gy, final_green_Gy, final_blue_Gy));
            }
        }

        // Hiển thị ảnh gốc
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
        label_in->setWindowTitle("Ảnh gốc");
        label_in->show();

        // Hiển thị kết quả Gx
        QLabel *label_Gx = new QLabel();
        label_Gx->setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
        label_Gx->setWindowTitle("Kết quả Gx (Robert)");
        label_Gx->show();

        // Hiển thị kết quả Gy
        QLabel *label_Gy = new QLabel();
        label_Gy->setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
        label_Gy->setWindowTitle("Kết quả Gy (Robert)");
        label_Gy->show();
}

// Loc sobel cho anh mau
void MainWindow::on_btn_Loc_SobelColor_clicked()
{
    // Đọc ảnh đầu vào
      QImage image_in(ui->ln_filename->text());
      QImage image_out_Gx(image_in.size(), QImage::Format_RGB32);
      QImage image_out_Gy(image_in.size(), QImage::Format_RGB32);

      int maskSize = 3;
      int margin = maskSize / 2;

      // Khởi tạo mặt nạ Sobel cho Gx
          const int mask_x[3][3] = {
              {-1, 0, 1},
              {-2, 0, 2},
              {-1, 0, 1}
          };

          // Khởi tạo mặt nạ Sobel cho Gy
          const int mask_y[3][3] = {
              {-1, -2, -1},
              {0, 0, 0},
              {1, 2, 1}
          };

      // Duyệt qua từng pixel (trừ biên)
      for (int y = margin; y < image_in.height() - margin; y++) {
          for (int x = margin; x < image_in.width() - margin; x++) {
              int sum_x_red = 0, sum_x_green = 0, sum_x_blue = 0;
              int sum_y_red = 0, sum_y_green = 0, sum_y_blue = 0;

              // Tính toán tích chập với mặt nạ Sobel
              for (int j = -margin; j <= margin; j++) {
                  for (int i = -margin; i <= margin; i++) {
                      QRgb color = image_in.pixel(x + i, y + j);

                      // Lấy giá trị màu cho từng kênh
                      int red = qRed(color);
                      int green = qGreen(color);
                      int blue = qBlue(color);

                      // Tính tích chập cho Gx
                      sum_x_red += red * mask_x[j + margin][i + margin];
                      sum_x_green += green * mask_x[j + margin][i + margin];
                      sum_x_blue += blue * mask_x[j + margin][i + margin];

                      // Tính tích chập cho Gy
                      sum_y_red += red * mask_y[j + margin][i + margin];
                      sum_y_green += green * mask_y[j + margin][i + margin];
                      sum_y_blue += blue * mask_y[j + margin][i + margin];
                  }
              }

              // Chuẩn hóa giá trị về khoảng 0-255
              int final_red_Gx = qBound(0, abs(sum_x_red), 255);
              int final_green_Gx = qBound(0, abs(sum_x_green), 255);
              int final_blue_Gx = qBound(0, abs(sum_x_blue), 255);
              image_out_Gx.setPixel(x, y, qRgb(final_red_Gx, final_green_Gx, final_blue_Gx));

              int final_red_Gy = qBound(0, abs(sum_y_red), 255);
              int final_green_Gy = qBound(0, abs(sum_y_green), 255);
              int final_blue_Gy = qBound(0, abs(sum_y_blue), 255);
              image_out_Gy.setPixel(x, y, qRgb(final_red_Gy, final_green_Gy, final_blue_Gy));
          }
      }

      // Hiển thị ảnh gốc
      QLabel* label_in = new QLabel();
      label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
      label_in->setWindowTitle("Ảnh gốc");
      label_in->show();

      // Hiển thị kết quả Gx
      QLabel* label_Gx = new QLabel();
      label_Gx->setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
      label_Gx->setWindowTitle("Kết quả Gx (Sobel)");
      label_Gx->show();

      // Hiển thị kết quả Gy
      QLabel* label_Gy = new QLabel();
      label_Gy->setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
      label_Gy->setWindowTitle("Kết quả Gy (Sobel)");
      label_Gy->show();
}

// Loc Prewitt cho anh mau
void MainWindow::on_btn_Loc_PrewittColor_clicked()
{
    // Đọc ảnh đầu vào
        QImage image_in(ui->ln_filename->text());
        QImage image_out_Gx(image_in.size(), QImage::Format_RGB32);
        QImage image_out_Gy(image_in.size(), QImage::Format_RGB32);

        // Mặt nạ Prewitt cho trục x (Gx)
        const int mask_x[3][3] = {
            {-1, 0, 1},
            {-1, 0, 1},
            {-1, 0, 1}
        };

        // Mặt nạ Prewitt cho trục y (Gy)
        const int mask_y[3][3] = {
            {-1, -1, -1},
            {0, 0, 0},
            {1, 1, 1}
        };

        // Duyệt qua từng pixel trong ảnh (trừ các biên)
        for (int y = 1; y < image_in.height() - 1; y++) {
            for (int x = 1; x < image_in.width() - 1; x++) {
                int sum_x_red = 0, sum_x_green = 0, sum_x_blue = 0;
                int sum_y_red = 0, sum_y_green = 0, sum_y_blue = 0;

                // Tính toán tích chập với mặt nạ Prewitt theo Gx và Gy
                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {
                        QRgb color = image_in.pixel(x + i, y + j);

                        // Lấy giá trị màu cho từng kênh
                        int red = qRed(color);
                        int green = qGreen(color);
                        int blue = qBlue(color);

                        // Tính tích chập cho Gx
                        sum_x_red += red * mask_x[j + 1][i + 1];
                        sum_x_green += green * mask_x[j + 1][i + 1];
                        sum_x_blue += blue * mask_x[j + 1][i + 1];

                        // Tính tích chập cho Gy
                        sum_y_red += red * mask_y[j + 1][i + 1];
                        sum_y_green += green * mask_y[j + 1][i + 1];
                        sum_y_blue += blue * mask_y[j + 1][i + 1];
                    }
                }

                // Chuẩn hóa giá trị về khoảng 0-255 và lưu vào ảnh kết quả
                int final_red_Gx = qBound(0, abs(sum_x_red), 255);
                int final_green_Gx = qBound(0, abs(sum_x_green), 255);
                int final_blue_Gx = qBound(0, abs(sum_x_blue), 255);
                image_out_Gx.setPixel(x, y, qRgb(final_red_Gx, final_green_Gx, final_blue_Gx));

                int final_red_Gy = qBound(0, abs(sum_y_red), 255);
                int final_green_Gy = qBound(0, abs(sum_y_green), 255);
                int final_blue_Gy = qBound(0, abs(sum_y_blue), 255);
                image_out_Gy.setPixel(x, y, qRgb(final_red_Gy, final_green_Gy, final_blue_Gy));
            }
        }

        // Hiển thị ảnh gốc
        QLabel* label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
        label_in->setWindowTitle("Ảnh gốc");
        label_in->show();

        // Hiển thị kết quả Gx
        QLabel* label_Gx = new QLabel();
        label_Gx->setPixmap(QPixmap::fromImage(image_out_Gx.scaled(1024, 768)));
        label_Gx->setWindowTitle("Kết quả Gx (Prewitt)");
        label_Gx->show();

        // Hiển thị kết quả Gy
        QLabel* label_Gy = new QLabel();
        label_Gy->setPixmap(QPixmap::fromImage(image_out_Gy.scaled(1024, 768)));
        label_Gy->setWindowTitle("Kết quả Gy (Prewitt)");
        label_Gy->show();
}


//Loc Laplace cho anh mau
void MainWindow::on_btn_Loc_LaplaceColor_clicked()
{
    // Đọc ảnh đầu vào
    QImage image_in(ui->ln_filename->text());
    QImage image_out_x(image_in.size(), QImage::Format_RGB32);
    QImage image_out_y(image_in.size(), QImage::Format_RGB32);

    int maskSize = 3;
    int margin = maskSize / 2;

    // Mặt nạ Laplace cho Gx
    const int mask_x[3][3] = {
        {0,  1,  0},
        {1, -4,  1},
        {0,  1,  0}
    };

    // Mặt nạ Laplace cho Gy
    const int mask_y[3][3] = {
        {1,  1,  1},
        {1, -8,  1},
        {1,  1,  1}
    };

    QRgb color;
    int sum_x_red, sum_x_green, sum_x_blue;
    int sum_y_red, sum_y_green, sum_y_blue;

    // Duyệt qua từng pixel trong ảnh (trừ các biên)
    for (int y = margin; y < image_in.height() - margin; y++) {
        for (int x = margin; x < image_in.width() - margin; x++) {
            sum_x_red = sum_x_green = sum_x_blue = 0;
            sum_y_red = sum_y_green = sum_y_blue = 0;

            // Tính toán tích chập với mặt nạ Laplace
            for (int j = -margin; j <= margin; j++) {
                for (int i = -margin; i <= margin; i++) {
                    color = image_in.pixel(x + i, y + j);
                    int red = qRed(color);
                    int green = qGreen(color);
                    int blue = qBlue(color);

                    // Tính gradient cho từng kênh màu
                    sum_x_red += red * mask_x[j + margin][i + margin];
                    sum_x_green += green * mask_x[j + margin][i + margin];
                    sum_x_blue += blue * mask_x[j + margin][i + margin];

                    sum_y_red += red * mask_y[j + margin][i + margin];
                    sum_y_green += green * mask_y[j + margin][i + margin];
                    sum_y_blue += blue * mask_y[j + margin][i + margin];
                }
            }

            // Chuẩn hóa giá trị về khoảng 0-255
            int laplaceValue_x_red = qBound(0, abs(sum_x_red), 255);
            int laplaceValue_x_green = qBound(0, abs(sum_x_green), 255);
            int laplaceValue_x_blue = qBound(0, abs(sum_x_blue), 255);

            int laplaceValue_y_red = qBound(0, abs(sum_y_red), 255);
            int laplaceValue_y_green = qBound(0, abs(sum_y_green), 255);
            int laplaceValue_y_blue = qBound(0, abs(sum_y_blue), 255);

            // Đặt pixel vào ảnh kết quả
            image_out_x.setPixel(x, y, qRgb(laplaceValue_x_red, laplaceValue_x_green, laplaceValue_x_blue));
            image_out_y.setPixel(x, y, qRgb(laplaceValue_y_red, laplaceValue_y_green, laplaceValue_y_blue));
        }
    }

    // Hiển thị ảnh gốc và ảnh sau khi lọc
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024, 768)));
    label_in->setWindowTitle("Ảnh gốc");
    label_in->show();

    QLabel* label_Gx = new QLabel();
    label_Gx->setPixmap(QPixmap::fromImage(image_out_x.scaled(1024, 768)));
    label_Gx->setWindowTitle("Kết quả Gx (Laplace)");
    label_Gx->show();

    QLabel* label_Gy = new QLabel();
    label_Gy->setPixmap(QPixmap::fromImage(image_out_y.scaled(1024, 768)));
    label_Gy->setWindowTitle("Kết quả Gy (Laplace)");
    label_Gy->show();
}

void MainWindow::on_btn_Loc_G_L_clicked()
{
    // Đọc ảnh đầu vào
        QImage image_in(ui->ln_filename->text());
        QImage image_out(image_in.size(), QImage::Format_RGB32);

        int maskSize = 5;
        int margin = maskSize / 2;

        // Mặt nạ Gaussian 5x5
        float gaussian_mask[5][5] = {
            { 1/273.0f,  4/273.0f,  6/273.0f,  4/273.0f,  1/273.0f },
            { 4/273.0f, 16/273.0f, 24/273.0f, 16/273.0f,  4/273.0f },
            { 6/273.0f, 24/273.0f, 36/273.0f, 24/273.0f,  6/273.0f },
            { 4/273.0f, 16/273.0f, 24/273.0f, 16/273.0f,  4/273.0f },
            { 1/273.0f,  4/273.0f,  6/273.0f,  4/273.0f,  1/273.0f }
        };

        // Mặt nạ Laplace 5x5
        int laplace_mask[5][5] = {
            { 0,  0, -1,  0,  0 },
            { 0, -1, -2, -1,  0 },
            { -1, -2, 16, -2, -1 },
            { 0, -1, -2, -1,  0 },
            { 0,  0, -1,  0,  0 }
        };

        QRgb color;
        float sum;

        // Lọc Gaussian cho từng kênh màu
        QImage image_gaussian(image_in.size(), QImage::Format_RGB32);
        for (int y = margin; y < image_in.height() - margin; y++) {
            for (int x = margin; x < image_in.width() - margin; x++) {
                float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
                for (int j = -margin; j <= margin; j++) {
                    for (int i = -margin; i <= margin; i++) {
                        color = image_in.pixel(x + i, y + j);
                        sumR += qRed(color) * gaussian_mask[j + margin][i + margin];
                        sumG += qGreen(color) * gaussian_mask[j + margin][i + margin];
                        sumB += qBlue(color) * gaussian_mask[j + margin][i + margin];
                    }
                }
                int gaussianValueR = qBound(0, static_cast<int>(sumR), 255);
                int gaussianValueG = qBound(0, static_cast<int>(sumG), 255);
                int gaussianValueB = qBound(0, static_cast<int>(sumB), 255);
                image_gaussian.setPixel(x, y, qRgb(gaussianValueR, gaussianValueG, gaussianValueB));
            }
        }

        // Lọc Laplace cho từng kênh màu
        for (int y = margin; y < image_gaussian.height() - margin; y++) {
            for (int x = margin; x < image_gaussian.width() - margin; x++) {
                sum = 0.0f;
                float sumLaplaceR = 0.0f, sumLaplaceG = 0.0f, sumLaplaceB = 0.0f;
                for (int j = -margin; j <= margin; j++) {
                    for (int i = -margin; i <= margin; i++) {
                        color = image_gaussian.pixel(x + i, y + j);
                        sumLaplaceR += qRed(color) * laplace_mask[j + margin][i + margin];
                        sumLaplaceG += qGreen(color) * laplace_mask[j + margin][i + margin];
                        sumLaplaceB += qBlue(color) * laplace_mask[j + margin][i + margin];
                    }
                }

                // Chuẩn hóa giá trị về khoảng 0-255 cho từng kênh màu
                int laplaceValueR = qBound(0, static_cast<int>(abs(sumLaplaceR)), 255);
                int laplaceValueG = qBound(0, static_cast<int>(abs(sumLaplaceG)), 255);
                int laplaceValueB = qBound(0, static_cast<int>(abs(sumLaplaceB)), 255);

                // Đặt pixel vào ảnh kết quả
                image_out.setPixel(x, y, qRgb(laplaceValueR, laplaceValueG, laplaceValueB));
            }
        }

        // Hiển thị ảnh kết quả
        QLabel* label_result = new QLabel();
        label_result->setPixmap(QPixmap::fromImage(image_out.scaled(1024, 768)));
        label_result->setWindowTitle("Kết quả Gauss + Laplace");
        label_result->show();
}

void MainWindow::on_btn_gtTuanTu_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out2(image_in.width(), image_in.height(), QImage::Format_RGB32);

    int c = 127;
    int newc = c;

    do {
        int G1 = 0;
        int count1 = 0;
        int G2 = 0;
        int count2 = 0;
        c = newc;

        for (int i = 0; i < image_in.width(); i++) {
            for (int j = 0; j < image_in.height(); j++) {
                QRgb rgb = image_in.pixel(i, j);
                int gray = qGray(rgb);
                QRgb color_in = qRgb(gray, gray, gray);
                image_in.setPixel(i, j, color_in);

                if (gray <= c) {
                    G1 = G1 + gray;
                    count1++;
                } else {
                    G2 = G2 + gray;
                    count2++;
                }
            }
        }

        int M1 = G1 / count1;
        int M2 = G2 / count2;
        newc = (M1 + M2) / 2;

    } while (abs(newc - c) != 0);
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
    label_in->show();

    QLabel* label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out2.scaled(640, 480)));
    label_out->show();

}

void MainWindow::on_btn_Anmon_clicked()
{
    int kernel[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};  // Kernel cho ăn mòn
    int margin = 1;  // Kích thước lề
    int c_gray;  // Giá trị xám của pixel

    // Đọc ảnh đầu vào
    QImage image_in(ui->ln_filename->text());
    // Khởi tạo ảnh đầu ra
    QImage image_out2(image_in.size(), QImage::Format_RGB32);
    image_out2.fill(Qt::white);  // Mặc định màu trắng

    // Duyệt từng pixel trong ảnh đầu vào
    for (int x = margin; x < image_in.width() - margin; x++) {
        for (int y = margin; y < image_in.height() - margin; y++) {
            bool erode = true;  // Giả định sẽ ăn mòn

            // Kiểm tra các pixel xung quanh theo kernel
            for (int i = -margin; i <= margin; i++) {
                for (int j = -margin; j <= margin; j++) {
                    c_gray = qGray(image_in.pixel(x + i, y + j));  // Lấy giá trị xám từ ảnh đầu vào

                    // Nếu pixel không phải là đen, không ăn mòn
                    if (kernel[i + margin][j + margin] && c_gray != 0) {
                        erode = false;  // Nếu có pixel không đen, không ăn mòn
                    }
                }
            }

            // Nếu erode là true, thì pixel đó sẽ được ăn mòn
            if (erode) {
                image_out2.setPixel(x, y, qRgb(0, 0, 0));  // Đặt pixel thành đen
            } else {
                image_out2.setPixel(x, y, qRgb(255, 255, 255));  // Đặt pixel thành trắng
            }
        }
    }

    // Hiển thị ảnh đầu vào
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
    label_in->show();

    // Hiển thị ảnh đầu ra
    QLabel* label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out2.scaled(640, 480)));
    label_out->show();
}





void MainWindow::on_btn_Gianno_clicked()
{
    int kernel[3][3] = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    int margin = 1;
    int c_gray;

    QImage image_in(ui->ln_filename->text());
    QImage image_out2(image_in.width(), image_in.height(), QImage::Format_RGB32);
    image_out2.fill(Qt::white);

    // Process the input image for dilation
    for (int x = margin; x < image_in.width() - margin; x++) {
        for (int y = margin; y < image_in.height() - margin; y++) {
            // Get grayscale value from the input image
            c_gray = qGray(image_in.pixel(x, y));

            if (c_gray == 0) {  // Dilate if the input pixel is black
                for (int i = -margin; i <= margin; i++) {
                    for (int j = -margin; j <= margin; j++) {
                        if (kernel[i + margin][j + margin]) {
                            // Set corresponding pixels in the output image to black
                            image_out2.setPixel(x + i, y + j, qRgb(0, 0, 0));
                        }
                    }
                }
            }
        }
    }

    // Display the input and output images
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640, 480)));
    label_in->show();

    QLabel* label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out2.scaled(640, 480)));
    label_out->show();
}
