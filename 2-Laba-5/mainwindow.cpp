#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rup.h"
#include "amp.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels({"ФИО и дата"});
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->loadButton, &QPushButton::clicked,
            this, &MainWindow::onLoadClicked);

    connect(ui->tableWidget, &QTableWidget::cellDoubleClicked,
            this, &MainWindow::onCellDoubleClicked);
}

MainWindow::~MainWindow()
{
    for (auto p : people) delete p;
    delete ui;
}

void MainWindow::onLoadClicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Выбрать файл");
    if (file.isEmpty()) return;

    loadFile(file);
    fillTable();
}

void MainWindow::loadFile(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QStringList parts = in.readLine().split(",");

        int type = parts[0].toInt();

        if (type == 1) {
            RuP* p = new RuP();
            p->lastName = parts[1];
            p->firstName = parts[2];
            p->patronymic = parts[3];
            p->birthDate = QDate(parts[6].toInt(),
                                 parts[5].toInt(),
                                 parts[4].toInt());
            people.push_back(p);
        } else {
            AmP* p = new AmP();
            p->firstName = parts[1];
            p->secondName = parts[2];
            p->lastName = parts[3];
            p->birthDate = QDate(parts[6].toInt(),
                                 parts[5].toInt(),
                                 parts[4].toInt());
            people.push_back(p);
        }
    }
}

void MainWindow::fillTable()
{
    ui->tableWidget->setRowCount(people.size());

    for (int i = 0; i < people.size(); i++) {
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(people[i]->toString()));
    }
}

void MainWindow::onCellDoubleClicked(int row, int)
{
    Person* p = people[row];

    QMessageBox msg;
    msg.setText(p->craft());

    QPushButton* printBtn = msg.addButton("Печать", QMessageBox::AcceptRole);
    QPushButton* cancelBtn = msg.addButton("Отмена", QMessageBox::RejectRole);

    msg.exec();

    if (msg.clickedButton() == printBtn) {
        delete p;
        people.remove(row);
        fillTable();
    }
}
