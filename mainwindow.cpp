#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QPixmap>

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

void MainWindow::on_openButton_pressed()
{
    QString imagePath = QFileDialog::getOpenFileName(
                        this,
                        tr("Open File"),
                        "",
                        tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                        );

            imageObject = new QImage();
            imageObject->load(imagePath);

            image = QPixmap::fromImage(*imageObject);

            scene = new QGraphicsScene(this);
            scene->addPixmap(image);
            scene->setSceneRect(image.rect());
            ui->graphicsView->setScene(scene);

}


void MainWindow::on_saveButton_pressed()
{
    QString imagePath = QFileDialog::getSaveFileName(
                        this,
                        tr("Save File"),
                        "",
                        tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
                        );

            *imageObject = image.toImage();

            imageObject->save(imagePath);
}
