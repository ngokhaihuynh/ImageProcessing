#include "imagewidget.h"
#include "QWidget"
#include "QPainter"

ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent)
{
}
QImage ImageWidget::getImage()
{
    return _image;
}
void ImageWidget::setImage(const QImage &img)
{
    _image = img;
    repaint();
}
void ImageWidget::paintEvent(QPaintEvent *pe)
{
    QWidget::paintEvent(pe);
    QPainter painter(this);
    painter.drawImage(this->rect(), _image);
}
