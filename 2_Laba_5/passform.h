#ifndef PASSFORM_H
#define PASSFORM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QRandomGenerator>
#include <QPixmap>
#include <QPainter>
#include <QRegularExpression>
#include <QCoreApplication>
#include <QEvent>
#include <QDebug>



class Person;

class PassForm : public QDialog {
    Q_OBJECT

private:
    Person* person_; // указатель на человека, для которого создаётся пропуск
    QLabel* nameLabel_; // метка для ФИО
    QLabel* birthLabel_; // метка для даты рождения
    QLabel* imageLabel_; // метка для картинки
    QPushButton* cancelButton_; // кнопка "Отмена"
    QPushButton* printButton_; // кнопка "Печать"

    static const int IMAGE_MODE_ = 3; // 1 - статичная, 2 - рандомная, 3 - уникальная

public:
    explicit PassForm(Person* person_, QWidget* parent_ = nullptr);
    ~PassForm();

signals:
    void personDeleted(Person* person_);  // Сигнал для удаления

private slots:
    void onCancel(); // закрыть форму
    void onPrint(); //печать – закрыть форму и удалить человека

private:
    void setupUI();
    void setupImage();
};

#endif
