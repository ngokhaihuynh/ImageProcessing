/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lb_FileName;
    QLineEdit *ln_filename;
    QPushButton *pbtnBowse;
    QLabel *label;
    QLineEdit *ln_c;
    QLabel *label_2;
    QPushButton *bt_HisSlide_Gray;
    QPushButton *bt_HisSlide_Color;
    QLabel *label_3;
    QPushButton *bt_Xam_AmBan;
    QPushButton *bt_Mau_AmBan;
    QLabel *label_4;
    QLineEdit *LineDoTuongPhan;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *LinePhanNguong;
    QLabel *label_7;
    QPushButton *btn_PhanNguong;
    QPushButton *btn_Histogram_AnhXam;
    QPushButton *btn_Histogram_AnhMau;
    QPushButton *btn_XuLy_AnhXam;
    QPushButton *btn_XyLy_AnhMau;
    QPushButton *btn_BienDoiTuyenTinh;
    QPushButton *btn_CanBanghistogram;
    QLabel *Kichthuocmatna;
    QLabel *label_9;
    QLineEdit *ln_Kichthuocmatna;
    QLineEdit *ln_tilenhieu;
    QPushButton *btn_loctrungbinh;
    QPushButton *btn_Themnhieumuoitieu;
    QPushButton *btn_Loctrungvi;
    QPushButton *btn_Themnhieuanhmau;
    QPushButton *btn_Loc_Gradient;
    QPushButton *btn_Loc_Sobel;
    QPushButton *btn_Loc_Robert;
    QPushButton *btn_Loc_Prewitt;
    QPushButton *btn_Loc_Laplace;
    QPushButton *btn_Gradient_color;
    QPushButton *btn_Loc_RobertColor;
    QPushButton *pushButton_8;
    QPushButton *btn_Loc_SobelColor;
    QPushButton *btn_Loc_PrewittColor;
    QPushButton *btn_Loc_LaplaceColor;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1196, 934);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lb_FileName = new QLabel(centralWidget);
        lb_FileName->setObjectName(QStringLiteral("lb_FileName"));
        lb_FileName->setGeometry(QRect(20, 30, 161, 41));
        ln_filename = new QLineEdit(centralWidget);
        ln_filename->setObjectName(QStringLiteral("ln_filename"));
        ln_filename->setGeometry(QRect(230, 30, 491, 31));
        pbtnBowse = new QPushButton(centralWidget);
        pbtnBowse->setObjectName(QStringLiteral("pbtnBowse"));
        pbtnBowse->setGeometry(QRect(810, 30, 150, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 130, 121, 41));
        ln_c = new QLineEdit(centralWidget);
        ln_c->setObjectName(QStringLiteral("ln_c"));
        ln_c->setGeometry(QRect(230, 130, 131, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 130, 111, 41));
        bt_HisSlide_Gray = new QPushButton(centralWidget);
        bt_HisSlide_Gray->setObjectName(QStringLiteral("bt_HisSlide_Gray"));
        bt_HisSlide_Gray->setGeometry(QRect(680, 140, 181, 31));
        bt_HisSlide_Color = new QPushButton(centralWidget);
        bt_HisSlide_Color->setObjectName(QStringLiteral("bt_HisSlide_Color"));
        bt_HisSlide_Color->setGeometry(QRect(880, 140, 231, 31));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 141, 31));
        bt_Xam_AmBan = new QPushButton(centralWidget);
        bt_Xam_AmBan->setObjectName(QStringLiteral("bt_Xam_AmBan"));
        bt_Xam_AmBan->setGeometry(QRect(680, 80, 181, 31));
        bt_Mau_AmBan = new QPushButton(centralWidget);
        bt_Mau_AmBan->setObjectName(QStringLiteral("bt_Mau_AmBan"));
        bt_Mau_AmBan->setGeometry(QRect(880, 80, 231, 31));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 171, 61));
        LineDoTuongPhan = new QLineEdit(centralWidget);
        LineDoTuongPhan->setObjectName(QStringLiteral("LineDoTuongPhan"));
        LineDoTuongPhan->setGeometry(QRect(230, 190, 131, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(410, 180, 131, 51));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 250, 71, 16));
        LinePhanNguong = new QLineEdit(centralWidget);
        LinePhanNguong->setObjectName(QStringLiteral("LinePhanNguong"));
        LinePhanNguong->setGeometry(QRect(230, 249, 131, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(410, 240, 121, 51));
        btn_PhanNguong = new QPushButton(centralWidget);
        btn_PhanNguong->setObjectName(QStringLiteral("btn_PhanNguong"));
        btn_PhanNguong->setGeometry(QRect(680, 250, 181, 31));
        btn_Histogram_AnhXam = new QPushButton(centralWidget);
        btn_Histogram_AnhXam->setObjectName(QStringLiteral("btn_Histogram_AnhXam"));
        btn_Histogram_AnhXam->setGeometry(QRect(210, 300, 161, 31));
        btn_Histogram_AnhMau = new QPushButton(centralWidget);
        btn_Histogram_AnhMau->setObjectName(QStringLiteral("btn_Histogram_AnhMau"));
        btn_Histogram_AnhMau->setGeometry(QRect(680, 300, 181, 31));
        btn_XuLy_AnhXam = new QPushButton(centralWidget);
        btn_XuLy_AnhXam->setObjectName(QStringLiteral("btn_XuLy_AnhXam"));
        btn_XuLy_AnhXam->setGeometry(QRect(680, 190, 181, 31));
        btn_XyLy_AnhMau = new QPushButton(centralWidget);
        btn_XyLy_AnhMau->setObjectName(QStringLiteral("btn_XyLy_AnhMau"));
        btn_XyLy_AnhMau->setGeometry(QRect(880, 190, 231, 31));
        btn_BienDoiTuyenTinh = new QPushButton(centralWidget);
        btn_BienDoiTuyenTinh->setObjectName(QStringLiteral("btn_BienDoiTuyenTinh"));
        btn_BienDoiTuyenTinh->setGeometry(QRect(210, 340, 161, 31));
        btn_CanBanghistogram = new QPushButton(centralWidget);
        btn_CanBanghistogram->setObjectName(QStringLiteral("btn_CanBanghistogram"));
        btn_CanBanghistogram->setGeometry(QRect(680, 340, 181, 31));
        Kichthuocmatna = new QLabel(centralWidget);
        Kichthuocmatna->setObjectName(QStringLiteral("Kichthuocmatna"));
        Kichthuocmatna->setGeometry(QRect(10, 390, 111, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 420, 71, 16));
        ln_Kichthuocmatna = new QLineEdit(centralWidget);
        ln_Kichthuocmatna->setObjectName(QStringLiteral("ln_Kichthuocmatna"));
        ln_Kichthuocmatna->setGeometry(QRect(150, 390, 71, 20));
        ln_tilenhieu = new QLineEdit(centralWidget);
        ln_tilenhieu->setObjectName(QStringLiteral("ln_tilenhieu"));
        ln_tilenhieu->setGeometry(QRect(150, 420, 71, 20));
        btn_loctrungbinh = new QPushButton(centralWidget);
        btn_loctrungbinh->setObjectName(QStringLiteral("btn_loctrungbinh"));
        btn_loctrungbinh->setGeometry(QRect(310, 390, 161, 23));
        btn_Themnhieumuoitieu = new QPushButton(centralWidget);
        btn_Themnhieumuoitieu->setObjectName(QStringLiteral("btn_Themnhieumuoitieu"));
        btn_Themnhieumuoitieu->setGeometry(QRect(310, 420, 161, 23));
        btn_Loctrungvi = new QPushButton(centralWidget);
        btn_Loctrungvi->setObjectName(QStringLiteral("btn_Loctrungvi"));
        btn_Loctrungvi->setGeometry(QRect(570, 390, 171, 23));
        btn_Themnhieuanhmau = new QPushButton(centralWidget);
        btn_Themnhieuanhmau->setObjectName(QStringLiteral("btn_Themnhieuanhmau"));
        btn_Themnhieuanhmau->setGeometry(QRect(570, 420, 171, 23));
        btn_Loc_Gradient = new QPushButton(centralWidget);
        btn_Loc_Gradient->setObjectName(QStringLiteral("btn_Loc_Gradient"));
        btn_Loc_Gradient->setGeometry(QRect(30, 470, 191, 41));
        btn_Loc_Sobel = new QPushButton(centralWidget);
        btn_Loc_Sobel->setObjectName(QStringLiteral("btn_Loc_Sobel"));
        btn_Loc_Sobel->setGeometry(QRect(490, 470, 181, 41));
        btn_Loc_Robert = new QPushButton(centralWidget);
        btn_Loc_Robert->setObjectName(QStringLiteral("btn_Loc_Robert"));
        btn_Loc_Robert->setGeometry(QRect(260, 470, 191, 41));
        btn_Loc_Prewitt = new QPushButton(centralWidget);
        btn_Loc_Prewitt->setObjectName(QStringLiteral("btn_Loc_Prewitt"));
        btn_Loc_Prewitt->setGeometry(QRect(700, 470, 181, 41));
        btn_Loc_Laplace = new QPushButton(centralWidget);
        btn_Loc_Laplace->setObjectName(QStringLiteral("btn_Loc_Laplace"));
        btn_Loc_Laplace->setGeometry(QRect(920, 470, 191, 41));
        btn_Gradient_color = new QPushButton(centralWidget);
        btn_Gradient_color->setObjectName(QStringLiteral("btn_Gradient_color"));
        btn_Gradient_color->setGeometry(QRect(30, 520, 191, 41));
        btn_Loc_RobertColor = new QPushButton(centralWidget);
        btn_Loc_RobertColor->setObjectName(QStringLiteral("btn_Loc_RobertColor"));
        btn_Loc_RobertColor->setGeometry(QRect(260, 520, 191, 41));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(640, 630, 181, 41));
        btn_Loc_SobelColor = new QPushButton(centralWidget);
        btn_Loc_SobelColor->setObjectName(QStringLiteral("btn_Loc_SobelColor"));
        btn_Loc_SobelColor->setGeometry(QRect(490, 520, 181, 41));
        btn_Loc_PrewittColor = new QPushButton(centralWidget);
        btn_Loc_PrewittColor->setObjectName(QStringLiteral("btn_Loc_PrewittColor"));
        btn_Loc_PrewittColor->setGeometry(QRect(700, 520, 181, 41));
        btn_Loc_LaplaceColor = new QPushButton(centralWidget);
        btn_Loc_LaplaceColor->setObjectName(QStringLiteral("btn_Loc_LaplaceColor"));
        btn_Loc_LaplaceColor->setGeometry(QRect(920, 520, 191, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1196, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lb_FileName->setText(QApplication::translate("MainWindow", "T\303\252n file", 0));
        pbtnBowse->setText(QApplication::translate("MainWindow", "Ch\341\273\215n", 0));
        label->setText(QApplication::translate("MainWindow", "M\341\273\251c s\303\241ng", 0));
        label_2->setText(QApplication::translate("MainWindow", "> 0 t\304\203ng; < 0 gi\341\272\243m", 0));
        bt_HisSlide_Gray->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        bt_HisSlide_Color->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        label_3->setText(QApplication::translate("MainWindow", "Anh \303\242m b\341\272\243n", 0));
        bt_Xam_AmBan->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        bt_Mau_AmBan->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        label_4->setText(QApplication::translate("MainWindow", "\304\220\341\273\231 t\306\260\306\241ng ph\341\272\243n", 0));
        label_5->setText(QApplication::translate("MainWindow", "> 1 t\304\203ng; 0 < c < 1 gi\341\272\243m", 0));
        label_6->setText(QApplication::translate("MainWindow", "Ch\341\273\215n ng\306\260\341\273\241ng", 0));
        label_7->setText(QApplication::translate("MainWindow", "> n tr\341\272\257ng; < n \304\221en", 0));
        btn_PhanNguong->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 ph\303\242n ng\306\260\341\273\241ng", 0));
        btn_Histogram_AnhXam->setText(QApplication::translate("MainWindow", "V\341\272\275 Histogram cho \341\272\243nh X\303\241m", 0));
        btn_Histogram_AnhMau->setText(QApplication::translate("MainWindow", "V\341\272\275 histogram cho \341\272\243nh m\303\240u", 0));
        btn_XuLy_AnhXam->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_XyLy_AnhMau->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        btn_BienDoiTuyenTinh->setText(QApplication::translate("MainWindow", "Bi\341\272\277n \304\221\341\273\225i tuy\341\272\277n t\303\255nh histogram", 0));
        btn_CanBanghistogram->setText(QApplication::translate("MainWindow", "C\303\242n  b\341\272\261ng Histogram", 0));
        Kichthuocmatna->setText(QApplication::translate("MainWindow", "K\303\255ch Th\306\260\341\273\233c m\341\272\267t n\341\272\241", 0));
        label_9->setText(QApplication::translate("MainWindow", "T\341\273\211 l\341\273\207 nhi\341\273\205u", 0));
        btn_loctrungbinh->setText(QApplication::translate("MainWindow", "L\341\273\215c trung b\303\254nh", 0));
        btn_Themnhieumuoitieu->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u mu\341\273\221i ti\303\252u", 0));
        btn_Loctrungvi->setText(QApplication::translate("MainWindow", "L\341\273\215c trung v\341\273\213", 0));
        btn_Themnhieuanhmau->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u \341\272\243nh m\303\240u", 0));
        btn_Loc_Gradient->setText(QApplication::translate("MainWindow", "L\341\273\215c Gradient", 0));
        btn_Loc_Sobel->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel", 0));
        btn_Loc_Robert->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert", 0));
        btn_Loc_Prewitt->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt", 0));
        btn_Loc_Laplace->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace", 0));
        btn_Gradient_color->setText(QApplication::translate("MainWindow", "Gradient \341\272\243nh m\303\240u", 0));
        btn_Loc_RobertColor->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert \341\272\243nh m\303\240u", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "PushButton", 0));
        btn_Loc_SobelColor->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel \341\272\243nh m\303\240u", 0));
        btn_Loc_PrewittColor->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt \341\272\243nh m\303\240u", 0));
        btn_Loc_LaplaceColor->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace \341\272\243nh m\303\240u", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
