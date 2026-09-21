import math  # Подключаем математический модуль


class Angle:  # Создаём класс для хранения углов

    def __init__(self, radians):  # Конструктор класса
        self.__radians = float(radians)  # Храним внутреннее значение угла в радианах

    # ---------- Фабричные методы ----------

    @classmethod  # Объявляем метод класса
    def from_radians(cls, radians):  # Создаём угол, заданный в радианах
        return cls(radians)  # Возвращаем новый объект Angle

    @classmethod  # Объявляем метод класса
    def from_degrees(cls, degrees):  # Создаём угол, заданный в градусах
        return cls(math.radians(degrees))  # Переводим градусы в радианы и создаём объект

    # ---------- Геттеры и сеттеры ----------

    def get_radians(self):  # Метод получения угла в радианах
        return self.__radians  # Возвращаем значение угла в радианах

    def set_radians(self, radians):  # Метод изменения угла в радианах
        self.__radians = float(radians)  # Записываем новое значение

    def get_degrees(self):  # Метод получения угла в градусах
        return math.degrees(self.__radians)  # Переводим радианы в градусы

    def set_degrees(self, degrees):  # Метод изменения угла в градусах
        self.__radians = math.radians(degrees)  # Переводим градусы в радианы

    # ---------- Вспомогательные методы ----------

    def normalized(self):  # Метод нормализации угла
        return self.__radians % (2 * math.pi)  # Приводим угол к диапазону от 0 до 2π

    @staticmethod  # Метод не зависит от конкретного объекта
    def _to_radians(value):  # Преобразуем значение в радианы
        if isinstance(value, Angle):  # Проверяем, является ли значение объектом Angle
            return value.get_radians()  # Получаем радианы из объекта

        if isinstance(value, (int, float)):  # Проверяем, является ли значение числом
            return float(value)  # Считаем число заданным в радианах

        raise TypeError("Ожидался Angle, int или float")  # Вызываем ошибку при неправильном типе

    # ---------- Строковое представление ----------

    def __str__(self):  # Метод преобразования объекта в строку
        return f"{self.get_degrees():.2f}° ({self.__radians:.4f} рад)"  # Выводим градусы и радианы

    def __repr__(self):  # Метод представления объекта для разработчика
        return f"Angle.from_radians({self.__radians})"  # Возвращаем строку создания объекта

    # ---------- Сравнение ----------

    def __eq__(self, other):  # Оператор ==
        try:  # Пытаемся выполнить сравнение
            a = self.normalized()  # Нормализуем первый угол
            b = Angle._to_radians(other) % (2 * math.pi)  # Нормализуем второй угол
            return math.isclose(a, b, abs_tol=1e-9)  # Сравниваем с учётом погрешности
        except TypeError:  # Если передан неподходящий тип
            return NotImplemented  # Сообщаем Python, что сравнение невозможно

    def __ne__(self, other):  # Оператор !=
        return not self == other  # Неравенство является отрицанием равенства

    def __lt__(self, other):  # Оператор <
        return self.normalized() < Angle._to_radians(other) % (2 * math.pi)  # Сравниваем нормализованные углы

    def __le__(self, other):  # Оператор <=
        return self < other or self == other  # Проверяем меньше или равно

    def __gt__(self, other):  # Оператор >
        return not self <= other  # Проверяем больше через отрицание <=

    def __ge__(self, other):  # Оператор >=
        return not self < other  # Проверяем больше или равно

    # ---------- Преобразование в float и int ----------

    def __float__(self):  # Метод преобразования Angle в float
        return self.__radians  # Возвращаем значение в радианах

    def __int__(self):  # Метод преобразования Angle в int
        return int(self.__radians)  # Возвращаем целую часть радианного значения

    # ---------- Арифметические операции ----------

    def __add__(self, other):  # Оператор сложения
        return Angle(self.__radians + Angle._to_radians(other))  # Складываем два угла

    def __radd__(self, other):  # Сложение, когда Angle находится справа
        return self + other  # Выполняем обычное сложение

    def __sub__(self, other):  # Оператор вычитания
        return Angle(self.__radians - Angle._to_radians(other))  # Вычитаем углы

    def __rsub__(self, other):  # Вычитание, когда Angle находится справа
        return Angle(Angle._to_radians(other) - self.__radians)  # Вычитаем угол из числа

    def __mul__(self, other):  # Оператор умножения
        if not isinstance(other, (int, float)):  # Проверяем, что множитель является числом
            return NotImplemented  # Если это не число, операция не поддерживается
        return Angle(self.__radians * other)  # Умножаем угол на число

    def __rmul__(self, other):  # Умножение, когда число находится слева
        return self * other  # Используем обычное умножение

    def __truediv__(self, other):  # Оператор деления
        if not isinstance(other, (int, float)):  # Проверяем, что делитель является числом
            return NotImplemented  # Если это не число, операция не поддерживается

        if other == 0:  # Проверяем деление на ноль
            raise ZeroDivisionError("Деление на ноль")  # Вызываем ошибку

        return Angle(self.__radians / other)  # Делим угол на число


class AngleRange:  # Создаём класс для хранения промежутка углов

    def __init__(
        self,
        start,
        end,
        start_inclusive=True,
        end_inclusive=True
    ):  # Конструктор промежутка

        self.start = self._to_angle(start)  # Сохраняем начальную границу
        self.end = self._to_angle(end)  # Сохраняем конечную границу

        self.start_inclusive = start_inclusive  # Запоминаем, включена ли левая граница
        self.end_inclusive = end_inclusive  # Запоминаем, включена ли правая граница

    @staticmethod  # Объявляем статический метод
    def _to_angle(value):  # Преобразуем значение в объект Angle
        if isinstance(value, Angle):  # Проверяем, является ли значение Angle
            return value  # Если да, возвращаем его без изменений

        if isinstance(value, (int, float)):  # Проверяем, является ли значение числом
            return Angle.from_radians(value)  # Считаем число радианами

        raise TypeError("Граница должна быть Angle, int или float")  # Ошибка при неправильном типе

    # ---------- Длина промежутка ----------

    def __abs__(self):  # Метод определения длины промежутка
        start = self.start.normalized()  # Нормализуем начальную границу
        end = self.end.normalized()  # Нормализуем конечную границу

        length = end - start  # Находим разницу между границами

        if length < 0:  # Если промежуток проходит через 0°
            length += 2 * math.pi  # Добавляем полный круг

        return length  # Возвращаем длину в радианах

    def length(self):  # Отдельный метод получения длины
        return abs(self)  # Используем метод __abs__()

    # ---------- Строковое представление ----------

    def __str__(self):  # Метод преобразования промежутка в строку
        left = "[" if self.start_inclusive else "("  # Определяем левую скобку
        right = "]" if self.end_inclusive else ")"  # Определяем правую скобку

        return (
            f"{left}{self.start.get_degrees():.2f}°, "  # Выводим начальную границу
            f"{self.end.get_degrees():.2f}°{right}"  # Выводим конечную границу
        )

    def __repr__(self):  # Метод представления объекта
        return (
            f"AngleRange("  # Начало представления объекта
            f"{self.start!r}, "  # Выводим начальную границу
            f"{self.end!r}, "  # Выводим конечную границу
            f"{self.start_inclusive}, "  # Выводим состояние левой границы
            f"{self.end_inclusive})"  # Выводим состояние правой границы
        )

    # ---------- Проверка принадлежности ----------

    def contains_angle(self, angle):  # Проверяем, входит ли угол в промежуток
        angle = self._to_angle(angle)  # Преобразуем значение в Angle

        start = self.start.normalized()  # Нормализуем начало
        end = self.end.normalized()  # Нормализуем конец
        value = angle.normalized()  # Нормализуем проверяемый угол

        if start <= end:  # Проверяем обычный промежуток, не проходящий через 0°

            left_ok = (  # Проверяем левую границу
                value >= start  # Если левая граница включена
                if self.start_inclusive  # Проверяем флаг включения
                else value > start  # Если граница исключена
            )

            right_ok = (  # Проверяем правую границу
                value <= end  # Если правая граница включена
                if self.end_inclusive  # Проверяем флаг включения
                else value < end  # Если граница исключена
            )

            return left_ok and right_ok  # Возвращаем результат проверки

        left_part = value >= start  # Проверяем часть промежутка после начала
        right_part = value <= end  # Проверяем часть промежутка перед концом

        if value == start:  # Если угол совпадает с начальной границей
            left_part = self.start_inclusive  # Учитываем включение границы

        if value == end:  # Если угол совпадает с конечной границей
            right_part = self.end_inclusive  # Учитываем включение границы

        return left_part or right_part  # Возвращаем результат проверки

    def contains_range(self, other):  # Проверяем, входит ли один промежуток в другой
        if not isinstance(other, AngleRange):  # Проверяем тип объекта
            return False  # Если это не промежуток, возвращаем False

        return (  # Проверяем обе границы другого промежутка
            self.contains_angle(other.start)  # Проверяем начало
            and self.contains_angle(other.end)  # Проверяем конец
        )

    def __contains__(self, item):  # Реализуем оператор in
        if isinstance(item, AngleRange):  # Если проверяем другой промежуток
            return self.contains_range(item)  # Проверяем его принадлежность

        return self.contains_angle(item)  # Иначе проверяем принадлежность угла

    # ---------- Эквивалентность ----------

    def __eq__(self, other):  # Оператор сравнения ==
        if not isinstance(other, AngleRange):  # Проверяем тип второго объекта
            return NotImplemented  # Если это не AngleRange, сравнение невозможно

        return (  # Сравниваем все параметры промежутков
            self.start == other.start  # Сравниваем начальные границы
            and self.end == other.end  # Сравниваем конечные границы
            and self.start_inclusive == other.start_inclusive  # Сравниваем левые границы
            and self.end_inclusive == other.end_inclusive  # Сравниваем правые границы
        )

    # ---------- Сравнение промежутков ----------

    def __lt__(self, other):  # Оператор <
        if not isinstance(other, AngleRange):  # Проверяем тип объекта
            return NotImplemented  # Возвращаем невозможность сравнения
        return self.length() < other.length()  # Сравниваем длины промежутков

    def __le__(self, other):  # Оператор <=
        if not isinstance(other, AngleRange):  # Проверяем тип объекта
            return NotImplemented  # Возвращаем невозможность сравнения
        return self.length() <= other.length()  # Сравниваем длины

    def __gt__(self, other):  # Оператор >
        if not isinstance(other, AngleRange):  # Проверяем тип объекта
            return NotImplemented  # Возвращаем невозможность сравнения
        return self.length() > other.length()  # Сравниваем длины

    def __ge__(self, other):  # Оператор >=
        if not isinstance(other, AngleRange):  # Проверяем тип объекта
            return NotImplemented  # Возвращаем невозможность сравнения
        return self.length() >= other.length()  # Сравниваем длины

    # ---------- Сложение промежутков ----------

    def __add__(self, other):  # Оператор сложения промежутков
        if not isinstance(other, AngleRange):  # Проверяем тип второго объекта
            return NotImplemented  # Если это не промежуток, операция невозможна

        new_start = self.start + other.start  # Складываем начальные границы
        new_end = self.end + other.end  # Складываем конечные границы

        return [  # Возвращаем список промежутков
            AngleRange(  # Создаём новый промежуток
                new_start,  # Передаём новую начальную границу
                new_end,  # Передаём новую конечную границу
                self.start_inclusive and other.start_inclusive,  # Проверяем левую границу
                self.end_inclusive and other.end_inclusive  # Проверяем правую границу
            )
        ]

    # ---------- Вычитание промежутков ----------

    def __sub__(self, other):  # Оператор вычитания промежутков
        if not isinstance(other, AngleRange):  # Проверяем тип второго объекта
            return NotImplemented  # Если это не промежуток, операция невозможна

        new_start = self.start - other.end  # Вычисляем новую начальную границу
        new_end = self.end - other.start  # Вычисляем новую конечную границу

        return [  # Возвращаем список промежутков
            AngleRange(  # Создаём новый промежуток
                new_start,  # Передаём начальную границу
                new_end,  # Передаём конечную границу
                self.start_inclusive and other.end_inclusive,  # Проверяем левую границу
                self.end_inclusive and other.start_inclusive  # Проверяем правую границу
            )
        ]


# ==========================================================
#                 ДЕМОНСТРАЦИЯ РАБОТЫ
# ==========================================================

print("========== ANGLE ==========")  # Выводим заголовок

a1 = Angle.from_degrees(90)  # Создаём угол 90 градусов
a2 = Angle.from_radians(math.pi)  # Создаём угол π радиан

print("a1 =", a1)  # Выводим первый угол
print("a2 =", a2)  # Выводим второй угол

print("\nГеттеры:")  # Выводим название раздела
print("a1 в радианах:", a1.get_radians())  # Получаем угол в радианах
print("a1 в градусах:", a1.get_degrees())  # Получаем угол в градусах

print("\nСеттеры:")  # Выводим название раздела

a1.set_degrees(180)  # Устанавливаем угол 180 градусов
print("После set_degrees(180):", a1)  # Выводим изменённый угол

a1.set_radians(math.pi / 2)  # Устанавливаем угол π/2 радиан
print("После set_radians(π/2):", a1)  # Выводим изменённый угол

print("\nПреобразования:")  # Выводим название раздела
print("float(a1) =", float(a1))  # Преобразуем Angle в float
print("int(a1) =", int(a1))  # Преобразуем Angle в int

print("\nСравнение:")  # Выводим название раздела

a3 = Angle.from_degrees(360)  # Создаём угол 360 градусов
a4 = Angle.from_degrees(0)  # Создаём угол 0 градусов

print("360° == 0°:", a3 == a4)  # Проверяем периодичность углов

print(
    "90° < 180°:",
    Angle.from_degrees(90) < Angle.from_degrees(180)
)  # Проверяем оператор <

print("\nАрифметика:")  # Выводим название раздела

a = Angle.from_degrees(90)  # Создаём угол 90 градусов

print("90° + 30° =", a + Angle.from_degrees(30))  # Складываем два угла
print("90° + π =", a + math.pi)  # Складываем Angle и число в радианах
print("90° - 30° =", a - Angle.from_degrees(30))  # Вычитаем два угла
print("90° * 2 =", a * 2)  # Умножаем угол на число
print("90° / 2 =", a / 2)  # Делим угол на число


print("\n========== ANGLE RANGE ==========")  # Выводим заголовок

r1 = AngleRange(  # Создаём первый промежуток
    Angle.from_degrees(30),  # Начальная граница 30°
    Angle.from_degrees(120)  # Конечная граница 120°
)

r2 = AngleRange(  # Создаём второй промежуток
    60,  # Начальная граница 60 радиан
    180,  # Конечная граница 180 радиан
    False,  # Левая граница исключена
    True  # Правая граница включена
)

print("r1 =", r1)  # Выводим первый промежуток
print("r2 =", r2)  # Выводим второй промежуток

print("\nДлина:")  # Выводим название раздела
print("r1 =", math.degrees(abs(r1)), "градусов")  # Получаем длину первого промежутка
print("r2 =", math.degrees(abs(r2)), "градусов")  # Получаем длину второго промежутка

print("\nПринадлежность угла:")  # Выводим название раздела

print(
    "90° входит в r1:",
    Angle.from_degrees(90) in r1
)  # Проверяем, входит ли 90° в промежуток

print(
    "150° входит в r1:",
    Angle.from_degrees(150) in r1
)  # Проверяем, входит ли 150° в промежуток

print("\nПринадлежность промежутка:")  # Выводим название раздела

r3 = AngleRange(  # Создаём третий промежуток
    Angle.from_degrees(50),  # Начальная граница 50°
    Angle.from_degrees(100)  # Конечная граница 100°
)

print("r3 входит в r1:", r3 in r1)  # Проверяем, входит ли r3 в r1

print("\nСравнение промежутков:")  # Выводим название раздела

print("r1 == r2:", r1 == r2)  # Проверяем равенство промежутков
print("r1 < r2:", r1 < r2)  # Сравниваем длины промежутков
print("r1 > r2:", r1 > r2)  # Сравниваем длины промежутков

print("\nСложение промежутков:")  # Выводим название раздела

result_add = r1 + r2  # Складываем два промежутка

for r in result_add:  # Перебираем полученные промежутки
    print(r)  # Выводим результат сложения

print("\nВычитание промежутков:")  # Выводим название раздела

result_sub = r1 - r2  # Вычитаем второй промежуток из первого

for r in result_sub:  # Перебираем полученные промежутки
    print(r)  # Выводим результат вычитания