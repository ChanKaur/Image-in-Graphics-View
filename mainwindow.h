#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>

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
    void on_openButton_pressed();

    void on_saveButton_pressed();

private:
    Ui::MainWindow *ui;

      QPixmap image;
      QImage  *imageObject;
      QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
