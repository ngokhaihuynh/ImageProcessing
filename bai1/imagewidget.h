#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

class ImageWidget : public QWidget
{
    Q_OBJECT
    QImage _image;
    void virtual paintEvent(QPaintEvent *);
public:
    explicit ImageWidget(QWidget *parent = 0);
    QImage getImage();
    void setImage(const QImage &img);
    
signals:
    
public slots:
    
};

#endif // IMAGEWIDGET_H
