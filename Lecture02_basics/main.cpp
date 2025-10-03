#include <iostream>
#include <cmath>//подключение math для использования функции pow
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int a, b;
	float c, s;
	cin >> a >> b;
	c = pow(((a * a) + (b * b)), 0.5);
	s = (a + b + c);
	cout << "Гипотинуза: " << c << " float" << endl;
	cout << "Периметр: " << s << " float" << endl;
	cout << "int " << sizeof(int) * 8 << "бита, " << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
	cout << "float : " << sizeof(float) * 8 << "бита, " << numeric_limits<float>::lowest() << " " << numeric_limits<float>::max() << endl;
	/*Завершение
	программы*/
	return 0;
}