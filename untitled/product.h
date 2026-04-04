#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Product {
public:
    QString name;
    QString country;
    int weight;
    int price;
    QString delivery;
    bool fragile;
    bool newItem;
    bool noReturn;

    Product(QString n, QString c, int w, int p,
            QString d, bool f, bool ni, bool nr)
        : name(n), country(c), weight(w), price(p),
        delivery(d), fragile(f), newItem(ni), noReturn(nr) {}

    void saveToFile() {
        QFile file("result.txt");
        if (file.open(QIODevice::Append)) {
            QTextStream out(&file);
            out << "Груз: " << name << "\n";
            out << "Страна: " << country << "\n";
            out << "Вес: " << weight << "\n";
            out << "Цена: " << price << "\n";
            out << "Доставка: " << delivery << "\n";
            out << "Маркеры: "
                << (fragile ? "Хрупкое " : "")
                << (newItem ? "Новинка " : "")
                << (noReturn ? "Безвозвратное" : "")
                << "\n-------------------\n";
            file.close();
        }
    }
};

#endif
