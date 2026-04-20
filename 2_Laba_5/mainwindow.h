#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include "person.h"
#include "russianperson.h"
#include "americanperson.h"



class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QTableWidget* table_; // Слот для кнопки "Печать"
    QPushButton* loadButton_; // кнопка "Загрузить"
    QVector<Person*> persons_;  // вектор указателей на всех загруженных людей

public:
    MainWindow(QWidget* parent_ = nullptr);
    ~MainWindow();

private slots:
    void onLoadButtonClicked(); //Нажатие на кнопку загрузки
    void onTableDoubleClicked(const QModelIndex& index_); // двойной клик по строке таблицы
    void onPersonDeleted(Person* person_); // удаление человека после "печати"

private:
    void setupUI(); // создание интерфейса
    void loadFromFile(const QString& filename_); // чтение файла и создание объектов
    void updateTable();  // обновление содержимого таблицы
    void clearData(); // очистка вектора и таблицы

    //Методы для получения частей имени
    QString getLastNameFromPerson(Person* person_) const;
    QString getFirstNameFromPerson(Person* person_) const;
    QString getMiddleOrPatronymicFromPerson(Person* person_) const;
};

#endif
