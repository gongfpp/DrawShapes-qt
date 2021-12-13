#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QSpinBox>
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _pixmap = new QPixmap(ui->label->size());
    _pixmap->fill(Qt::white);
    _shape = Shape::clear;
    ui->label->setPixmap(*_pixmap);

}
void MainWindow::paintEvent(QPaintEvent *event){


    QPainter p(_pixmap);

    ui->label->setPixmap(*_pixmap);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRect_clicked()
{
    double width = QInputDialog::getDouble(this,"输入宽度","输入宽度",rand()%150);
    double height = QInputDialog::getDouble(this,"输入高度","输入高度",rand()%200);
    QPainter painter(_pixmap);
    painter.drawRect(10,10,width,height);
    Rectange rec(width,height);
    rec.printInfo();
    ui->textEdit->append("矩形周长为:"+QString::number( rec.calcPerimeter()));
    ui->textEdit->append("矩形面积为:"+QString::number( rec.calcArea()));


}

void MainWindow::on_btnClear_clicked()
{
    _pixmap->fill(Qt::white);
}

void MainWindow::on_btnTri_clicked()
{
//    double a = QInputDialog::getDouble(this,"输入边长","a:");
//    double b = QInputDialog::getDouble(this,"输入边长","b:");
//    double c = QInputDialog::getDouble(this,"输入边长","c:");

    QDialog dialog(this);
    QFormLayout form(&dialog);
    form.addRow(new QLabel("输入三角形三个点的坐标"));
    int ax,bx,cx,ay,by,cy;
    QList<QLineEdit *> fields;
    for(int i = 0; i < 3; ++i) {
        QLineEdit *lineEditX = new QLineEdit(QString::number(i*10+rand()%400),&dialog);
        QLineEdit *lineEditY = new QLineEdit(QString::number(i*12+rand()%200),&dialog);
        QLabel label(QString("顶点%1坐标X Y ").arg(i + 1),this);
        form.addRow(&label);
        form.addRow(lineEditX,lineEditY);


        fields << lineEditX << lineEditY;
    }

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));
    QPainter painter(_pixmap);
    if (dialog.exec() == QDialog::Accepted) {
        ax=fields[0]->text().toInt();
        ay=fields[1]->text().toInt();
        bx=fields[2]->text().toInt();
        by=fields[3]->text().toInt();
        cx=fields[4]->text().toInt();
        cy=fields[5]->text().toInt();


        painter.drawLine(ax,ay,bx,by);
        painter.drawLine(ax,ay,cx,cy);
        painter.drawLine(bx,by,cx,cy);

    }else {return;}


    double a = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
    double b = sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
    double c = sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy));
    Triangle tri(a,b,c);
    tri.printInfo();
    ui->textEdit->append("三角形面积为"+QString::number(tri.calcArea()));
    ui->textEdit->append("三角形周长为"+QString::number(tri.calcPerimeter()));

}

void MainWindow::on_btnSquare_clicked()
{
    double width = QInputDialog::getDouble(this,"正方形","输入边长",rand()%200);
    QPainter painter(_pixmap);
    painter.drawRect(10,10,width,width);
    Rectange rec(width,width);
    rec.printInfo();
    ui->textEdit->append("正方形周长为:"+QString::number( rec.calcPerimeter()));
    ui->textEdit->append("正方形面积为:"+QString::number( rec.calcArea()));

}
