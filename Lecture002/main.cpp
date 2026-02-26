#include "Student.h"
#include <iostream>
int main(){
    vector<string> d1 ={ "a", "b" };//Долги первого студента
    vector<string> d2 ={ "a", "c" };//Долги 2-го студента

    Student s1("A1", "A2", d1);//1-ый студент
    Student s2("B1", "B2", d2);//2-ой студент


    Student s3 = s1 + s2;//Проверка оператора (+)
    s3.printInfo();//Результат

    Student s4 = s1 -= s2;
    s4.printInfo();

    Student s5 = s1 / s2;
    s5.printInfo();


    return 0;

}