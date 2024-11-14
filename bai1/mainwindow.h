#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DisplayImage(QImage &img, QString title);
    void Histogram_GrayImage(const QImage &img, const int &his_height);
    void Histogram_ColorImage(const QImage &img, const int &his_height);
    QImage SuaChuaHistogram(const QImage &imgin);
    QImage CanBangHistogram(const QImage &imgin);
    int Random(int n);
    QImage imNoise_Gray(QImage &image_in, float level);



    
private slots:
    void on_pbtnBowse_clicked();

    void on_bt_HisSlide_Gray_clicked();

    void on_bt_HisSlide_Color_clicked();

    void on_bt_Xam_AmBan_clicked();

    void on_bt_Mau_AmBan_clicked();

    void on_btn_PhanNguong_clicked();

    void on_btn_Histogram_AnhXam_clicked();

    void on_btn_Histogram_AnhMau_clicked();

    void on_btn_XuLy_AnhXam_clicked();

    void on_btn_XyLy_AnhMau_clicked();

    void on_btn_BienDoiTuyenTinh_clicked();

    void on_btn_CanBanghistogram_clicked();

    void on_btn_loctrungbinh_clicked();

    void on_btn_Loctrungvi_clicked();

    void on_btn_Themnhieumuoitieu_clicked();

    void on_btn_Loc_Gradient_clicked();

    void on_btn_Loc_Sobel_clicked();

    void on_btn_Loc_Robert_clicked();

    void on_btn_Loc_Prewitt_clicked();

    void on_btn_Loc_Laplace_clicked();

    void on_btn_Loc_laplace_Gau_clicked();

    void on_btn_Gradient_color_clicked();

    void on_btn_Loc_RobertColor_clicked();

    void on_btn_Loc_SobelColor_clicked();

    void on_btn_Loc_PrewittColor_clicked();

    void on_btn_Loc_LaplaceColor_clicked();

    void on_btn_Loc_G_L_clicked();

    void on_btn_gtTuanTu_clicked();

    void on_btn_Anmon_clicked();

    void on_btn_Gianno_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
