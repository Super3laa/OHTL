#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//Done By Alaa Essam

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

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int);

    void on_pushButton_3_clicked();

    void on_material_currentIndexChanged(int index);

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
