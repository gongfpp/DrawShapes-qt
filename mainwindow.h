#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QToolBar>
#include <QAction>
#include <QPalette>
#include <QColor>
#include <QMenu>
#include <QFileDialog>
#include <QTextEdit>
#include "QInputDialog"
#include "shapes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    enum Shape{rect,tri,rightRri,square,circle,clear};
private slots:
    void on_btnRect_clicked();

    void on_btnClear_clicked();

    void on_btnTri_clicked();

    void on_btnSquare_clicked();

private:

    Ui::MainWindow *ui;
    QPixmap* _pixmap;
    Shape _shape;
    void paintEvent(QPaintEvent *);//重写窗体重绘事件

};

#endif // MAINWINDOW_H
