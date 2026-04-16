#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>
#include "person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QVector<Person*> people;

    void loadFile(QString path);
    void fillTable();

private slots:
    void onLoadClicked();
    void onCellDoubleClicked(int row, int column);
};

#endif // MAINWINDOW_H
