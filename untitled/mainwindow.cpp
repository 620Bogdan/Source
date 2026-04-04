#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Сброс формы
void MainWindow::on_resetButton_clicked() {
    ui->nameEdit->clear();
    ui->countryEdit->clear();
    ui->weightEdit->clear();
    ui->priceEdit->clear();

    // Сброс radio (чтобы не было выбранного по умолчанию)
    ui->planeRadio->setAutoExclusive(false);
    ui->shipRadio->setAutoExclusive(false);
    ui->planeRadio->setChecked(false);
    ui->shipRadio->setChecked(false);
    ui->planeRadio->setAutoExclusive(true);
    ui->shipRadio->setAutoExclusive(true);

    // Сброс чекбоксов
    ui->fragileCheck->setChecked(false);
    ui->newCheck->setChecked(false);
    ui->noReturnCheck->setChecked(false);
}

// Валидация полей
bool MainWindow::validate(QString &error) {
    QRegularExpression textRegex("^[A-ZА-Я][a-zа-я]+$");
    QRegularExpression numRegex("^[0-9]+$");

    if (!textRegex.match(ui->nameEdit->text()).hasMatch()) {
        error = "Груз";
        return false;
    }

    if (!textRegex.match(ui->countryEdit->text()).hasMatch()) {
        error = "Страна";
        return false;
    }

    if (!numRegex.match(ui->weightEdit->text()).hasMatch() ||
        ui->weightEdit->text().toInt() > 100000) {
        error = "Вес";
        return false;
    }

    if (!numRegex.match(ui->priceEdit->text()).hasMatch()) {
        error = "Цена";
        return false;
    }

    if (!ui->planeRadio->isChecked() && !ui->shipRadio->isChecked()) {
        error = "Способ доставки";
        return false;
    }

    return true;
}

// Сохранение
void MainWindow::on_saveButton_clicked() {
    QString error;
    if (!validate(error)) {
        QMessageBox::warning(this, "Ошибка", "Ошибка в поле: " + error);
        return;
    }

    QString delivery = ui->planeRadio->isChecked() ? "Самолет" : "Корабль";

    Product product(
        ui->nameEdit->text(),
        ui->countryEdit->text(),
        ui->weightEdit->text().toInt(),
        ui->priceEdit->text().toInt(),
        delivery,
        ui->fragileCheck->isChecked(),
        ui->newCheck->isChecked(),
        ui->noReturnCheck->isChecked()
        );

    product.saveToFile();

    QMessageBox::information(this, "Успех", "Данные сохранены!");
}
