#include <iostream>   
#include <string>     

using namespace std;  

//|||Класс|||
class Student{   //Объявление класса 

private:
    string name;        
    string surname;     

protected:
    string direction;  //направление

public:
    int course;     //номер курса
    int group;       //номер группы
    int variant;    //номер варианта

    //|||Конструктор по умолчанию|||
    Student(){
        name = "";              
        surname = "";           
        direction = "";         
        course = 1;        //Курс(стандарт)
        group = 1;         //Группа(стандарт)
        variant = 1;       //Вариант(стандарт)
    }

    //|||Конструктор копирования|||
    Student(const Student& s){
        name = s.name;     //Копирование имени(ниже, тоже происходитт копирование)
        surname = s.surname;   
        direction = s.direction;
        course = s.course;
        group = s.group;
        variant = s.variant;
    }

    // |||Конструктор полного заполнения|||
    Student(string n, string s, string d, int c, int g, int v){       //Конструктор заполнения
        name = n;     //Присваение имени(ниже происходит тоже самое)
        surname = s;
        direction = d;
        course = c;
        group = g;
        variant = v;
    }

    // |||Деструктор|||
    ~Student(){     //Объявление деструктора
        cout<<"Деструктор Student вызван"<< endl;       //Выводим сообщение, о его запуске 
    }

    // |||Геттеры|||
    string getName(){     //Геттер имени(ниже происходит тоже самое)
        return name;     //Возвращаем имя(ниже происходит тоже самое)
    }

    string getSurname(){
        return surname;
    }

    string getDirection(){
        return direction;
    }

    int getCourse(){
        return course;
    }

    int getGroup(){
        return group;
    }

    int getVariant(){
        return variant;
    }
    // |||Сеттеры (на вар)
    void setVariant(int v){ //Сеттер для варианта
        if (v > 0) {
                          //(ниже происходит тоже самое)
            variant = v;        //Присваение значения
        }
    }
    void setCourse(int c){      
        if (c >= 1 && c <= 6){
            course = c;      
        }
    }

    void setGroup(int g) {
        if (g > 0) {
            group = g;
        }
    }

    //Полный вывод данных ()
    void printInfo() { //вывод информации 
        cout<< "Имя: "<< name<< endl;                 
        cout<< "Фамилия: "<< surname<<endl;         
        cout<< "Направление:" << direction<< endl;   
        cout<< "Курс: "<< course<<endl;             
        cout<< "Группа: "<< group<<endl;            
        cout<< "Вариант: "<< variant<< endl;         
    }

    //Функция перевода на след. курс 
    void nextCourse(){  //Переход на след. курс без параметров
        if (course < 4){ 
            course++;    //Переход на след. курс
        }
    }
};

int main() {

    cout << "Конструкторы по умолчанию" << endl;
    Student st1;          // Конструктор по умолчанию
    st1.printInfo();
    cout << "\nКонструктор полного заполнения" << endl;
    Student st2("Богдан", "Иванов", "Прикладная математика и информатика", 1, 1, 1);
    st2.printInfo();
    cout << "\nКонструктор копирования " << endl;
    Student st3(st2);     // Конструктор копирования
    st3.printInfo();
    cout << "\nГеттеры" << endl;
    cout << "Имя: " << st2.getName() << endl;
    cout << "Фамилия: " << st2.getSurname() << endl;
    cout << "Курс: " << st2.getCourse() << endl;
    cout << "\nСледующий курс" << endl;
    st2.nextCourse();
    cout << "Новый курс: " << st2.getCourse() << endl;
    return 0;
}