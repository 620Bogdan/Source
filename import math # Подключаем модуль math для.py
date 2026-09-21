import math  # Подключаем модуль math для работы с π и тригонометрией


# ============================================================
# КЛАСС ANGLE
# ============================================================

class Angle:

    # Константа полного оборота в радианах
    FULL_TURN = 2 * math.pi

    # --------------------------------------------------------
    # Конструктор класса
    # --------------------------------------------------------

    def __init__(self, radians):
        # Храним внутреннее состояние угла именно в радианах
        self._radians = float(radians) % self.FULL_TURN


    # --------------------------------------------------------
    # ФАБРИЧНЫЙ МЕТОД ДЛЯ СОЗДАНИЯ УГЛА В РАДИАНАХ
    # --------------------------------------------------------

    @classmethod
    def from_radians(cls, radians):
        # Создаём объект класса из радианного значения
        return cls(radians)


    # --------------------------------------------------------
    # ФАБРИЧНЫЙ МЕТОД ДЛЯ СОЗДАНИЯ УГЛА В ГРАДУСАХ
    # --------------------------------------------------------

    @classmethod
    def from_degrees(cls, degrees):
        # Переводим градусы в радианы
        radians = math.radians(degrees)

        # Создаём объект класса
        return cls(radians)


    # --------------------------------------------------------
    # ГЕТТЕР РАДИАНОВ
    # --------------------------------------------------------

    def get_radians(self):
        # Возвращаем значение угла в радианах
        return self._radians


    # --------------------------------------------------------
    # СЕТТЕР РАДИАНОВ
    # --------------------------------------------------------

    def set_radians(self, radians):
        # Записываем новое значение угла в радианах
        self._radians = float(radians) % self.FULL_TURN


    # --------------------------------------------------------
    # ГЕТТЕР ГРАДУСОВ
    # --------------------------------------------------------

    def get_degrees(self):
        # Переводим радианы в градусы
        return math.degrees(self._radians)


    # --------------------------------------------------------
    # СЕТТЕР ГРАДУСОВ
    # --------------------------------------------------------

    def set_degrees(self, degrees):
        # Переводим градусы в радианы
        self._radians = math.radians(degrees) % self.FULL_TURN


    # --------------------------------------------------------
    # ВСПОМОГАТЕЛЬНЫЙ МЕТОД
    # --------------------------------------------------------

    def _to_radians(self, value):
        # Если передали объект Angle
        if isinstance(value, Angle):
            # Возвращаем его значение в радианах
            return value._radians

        # Если передали число
        if isinstance(value, (int, float)):
            # Число считаем радианами
            return float(value)

        # Если передан неизвестный тип
        return NotImplemented


    # --------------------------------------------------------
    # СТРОКОВОЕ ПРЕДСТАВЛЕНИЕ
    # --------------------------------------------------------

    def __str__(self):
        # Метод вызывается через print() или str()
        return f"{self.get_degrees():.2f}°"


    # --------------------------------------------------------
    # ПРЕДСТАВЛЕНИЕ ОБЪЕКТА
    # --------------------------------------------------------

    def __repr__(self):
        # Возвращаем представление, удобное для программиста
        return f"Angle.from_radians({self._radians})"


    # --------------------------------------------------------
    # ПРЕОБРАЗОВАНИЕ В FLOAT
    # --------------------------------------------------------

    def __float__(self):
        # При float(angle) возвращаем радианы
        return self._radians


    # --------------------------------------------------------
    # ПРЕОБРАЗОВАНИЕ В INT
    # --------------------------------------------------------

    def __int__(self):
        # При int(angle) возвращаем целую часть радианов
        return int(self._radians)


    # --------------------------------------------------------
    # СРАВНЕНИЕ НА РАВЕНСТВО
    # --------------------------------------------------------

    def __eq__(self, other):
        # Получаем значение второго угла в радианах
        other_rad = self._to_radians(other)

        # Если тип неизвестный, возвращаем NotImplemented
        if other_rad is NotImplemented:
            return NotImplemented

        # Сравниваем углы с учётом периодичности
        return math.isclose(
            self._radians % self.FULL_TURN,
            other_rad % self.FULL_TURN,
            abs_tol=1e-9
        )


    # --------------------------------------------------------
    # МЕТОД ДЛЯ СРАВНЕНИЯ УГЛОВ С УЧЁТОМ ПЕРИОДИЧНОСТИ
    # --------------------------------------------------------

    def _normalized(self):
        # Приводим угол к диапазону [0; 2π)
        return self._radians % self.FULL_TURN


    # --------------------------------------------------------
    # МЕНЬШЕ
    # --------------------------------------------------------

    def __lt__(self, other):
        # Получаем значение второго угла
        other_rad = self._to_radians(other)

        # Проверяем тип
        if other_rad is NotImplemented:
            return NotImplemented

        # Сравниваем нормализованные значения
        return self._normalized() < other_rad % self.FULL_TURN


    # --------------------------------------------------------
    # МЕНЬШЕ ИЛИ РАВНО
    # --------------------------------------------------------

    def __le__(self, other):
        # Проверяем меньше или равно
        return self < other or self == other


    # --------------------------------------------------------
    # БОЛЬШЕ
    # --------------------------------------------------------

    def __gt__(self, other):
        # Получаем значение второго угла
        other_rad = self._to_radians(other)

        # Проверяем тип
        if other_rad is NotImplemented:
            return NotImplemented

        # Сравниваем нормализованные значения
        return self._normalized() > other_rad % self.FULL_TURN


    # --------------------------------------------------------
    # БОЛЬШЕ ИЛИ РАВНО
    # --------------------------------------------------------

    def __ge__(self, other):
        # Проверяем больше или равно
        return self > other or self == other


    # --------------------------------------------------------
    # НЕ РАВНО
    # --------------------------------------------------------

    def __ne__(self, other):
        # Неравенство является отрицанием равенства
        return not self == other


    # --------------------------------------------------------
    # СЛОЖЕНИЕ
    # --------------------------------------------------------

    def __add__(self, other):
        # Получаем радианы второго операнда
        other_rad = self._to_radians(other)

        # Проверяем тип
        if other_rad is NotImplemented:
            return NotImplemented

        # Возвращаем новый угол
        return Angle.from_radians(self._radians + other_rad)


    # --------------------------------------------------------
    # ВЫЧИТАНИЕ
    # --------------------------------------------------------

    def __sub__(self, other):
        # Получаем радианы второго операнда
        other_rad = self._to_radians(other)

        # Проверяем тип
        if other_rad is NotImplemented:
            return NotImplemented

        # Возвращаем новый угол
        return Angle.from_radians(self._radians - other_rad)


    # --------------------------------------------------------
    # УМНОЖЕНИЕ
    # --------------------------------------------------------

    def __mul__(self, number):
        # Умножать можно только на int или float
        if not isinstance(number, (int, float)):
            return NotImplemented

        # Возвращаем новый угол
        return Angle.from_radians(self._radians * number)


    # --------------------------------------------------------
    # ДЕЛЕНИЕ
    # --------------------------------------------------------

    def __truediv__(self, number):
        # Проверяем, что делим на число
        if not isinstance(number, (int, float)):
            return NotImplemented

        # Проверяем деление на ноль
        if number == 0:
            raise ZeroDivisionError("Деление на ноль невозможно")

        # Возвращаем новый угол
        return Angle.from_radians(self._radians / number)


# ============================================================
# КЛАСС ANGLERANGE
# ============================================================

class AngleRange:

    # --------------------------------------------------------
    # КОНСТРУКТОР
    # --------------------------------------------------------

    def __init__(
        self,
        start,
        end,
        start_inclusive=True,
        end_inclusive=True
    ):
        # Преобразуем начальную точку в Angle
        self.start = self._to_angle(start)

        # Преобразуем конечную точку в Angle
        self.end = self._to_angle(end)

        # Сохраняем включение начальной точки
        self.start_inclusive = start_inclusive

        # Сохраняем включение конечной точки
        self.end_inclusive = end_inclusive


    # --------------------------------------------------------
    # ПРЕОБРАЗОВАНИЕ В ANGLE
    # --------------------------------------------------------

    @staticmethod
    def _to_angle(value):
        # Если это уже Angle
        if isinstance(value, Angle):
            return value

        # Если число — считаем его радианами
        if isinstance(value, (int, float)):
            return Angle.from_radians(value)

        # Если тип неправильный
        raise TypeError("Граница должна быть Angle, int или float")


    # --------------------------------------------------------
    # СТРОКОВОЕ ПРЕДСТАВЛЕНИЕ
    # --------------------------------------------------------

    def __str__(self):
        # Выбираем скобку для начальной границы
        left = "[" if self.start_inclusive else "("

        # Выбираем скобку для конечной границы
        right = "]" if self.end_inclusive else ")"

        # Возвращаем красивую строку
        return f"{left}{self.start}; {self.end}{right}"


    # --------------------------------------------------------
    # REPR
    # --------------------------------------------------------

    def __repr__(self):
        # Возвращаем представление объекта
        return (
            f"AngleRange("
            f"{repr(self.start)}, "
            f"{repr(self.end)}, "
            f"{self.start_inclusive}, "
            f"{self.end_inclusive})"
        )


    # --------------------------------------------------------
    # ДЛИНА ПРОМЕЖУТКА
    # --------------------------------------------------------

    def __abs__(self):
        # Получаем начало промежутка
        start = self.start.get_radians()

        # Получаем конец промежутка
        end = self.end.get_radians()

        # Вычисляем длину с учётом перехода через 0
        length = (end - start) % (2 * math.pi)

        # Если точки совпадают, считаем полный круг
        if math.isclose(length, 0, abs_tol=1e-9):
            return 2 * math.pi

        # Возвращаем длину промежутка
        return length


    # --------------------------------------------------------
    # РАВЕНСТВО ПРОМЕЖУТКОВ
    # --------------------------------------------------------

    def __eq__(self, other):
        # Проверяем, что второй объект AngleRange
        if not isinstance(other, AngleRange):
            return False

        # Сравниваем начало
        if self.start != other.start:
            return False

        # Сравниваем конец
        if self.end != other.end:
            return False

        # Сравниваем типы границ
        return (
            self.start_inclusive == other.start_inclusive
            and self.end_inclusive == other.end_inclusive
        )


    # --------------------------------------------------------
    # ПРОВЕРКА ТОГО, ЧТО УГОЛ ПРИНАДЛЕЖИТ ПРОМЕЖУТКУ
    # --------------------------------------------------------

    def _contains_angle(self, angle):
        # Переводим значение в Angle
        angle = self._to_angle(angle)

        # Получаем радианы
        start = self.start.get_radians()
        end = self.end.get_radians()
        value = angle.get_radians()

        # Вычисляем длину промежутка
        length = (end - start) % (2 * math.pi)

        # Вычисляем положение точки относительно начала
        position = (value - start) % (2 * math.pi)

        # Проверяем левую границу
        if position == 0:
            return self.start_inclusive

        # Проверяем правую границу
        if math.isclose(position, length, abs_tol=1e-9):
            return self.end_inclusive

        # Проверяем нахождение внутри промежутка
        return 0 < position < length


    # --------------------------------------------------------
    # ОПЕРАТОР IN
    # --------------------------------------------------------

    def __contains__(self, item):
        # Если проверяется угол
        if isinstance(item, (Angle, int, float)):
            return self._contains_angle(item)

        # Если проверяется другой промежуток
        if isinstance(item, AngleRange):
            return self._range_contains(item)

        # Для неизвестного типа возвращаем False
        return False


    # --------------------------------------------------------
    # ПРОВЕРКА, ВХОДИТ ЛИ ПРОМЕЖУТОК В ДРУГОЙ
    # --------------------------------------------------------

    def _range_contains(self, other):
        # Проверяем начало другого промежутка
        if other.start not in self:
            return False

        # Проверяем конец другого промежутка
        if other.end not in self:
            return False

        # Если оба конца внутри, считаем промежуток вложенным
        return abs(other) <= abs(self)


    # --------------------------------------------------------
    # СРАВНЕНИЕ ПРОМЕЖУТКОВ
    # --------------------------------------------------------

    def __lt__(self, other):
        # Проверяем тип
        if not isinstance(other, AngleRange):
            return NotImplemented

        # Сравниваем длины
        return abs(self) < abs(other)


    def __le__(self, other):
        # Меньше или равно
        return self < other or self == other


    def __gt__(self, other):
        # Больше
        if not isinstance(other, AngleRange):
            return NotImplemented

        # Сравниваем длины
        return abs(self) > abs(other)


    def __ge__(self, other):
        # Больше или равно
        return self > other or self == other


    def __ne__(self, other):
        # Не равно
        return not self == other


    # --------------------------------------------------------
    # СЛОЖЕНИЕ ПРОМЕЖУТКОВ
    # --------------------------------------------------------

    def __add__(self, other):
        # Проверяем, что складываем с AngleRange
        if not isinstance(other, AngleRange):
            return NotImplemented

        # Смещаем обе границы второго промежутка
        start = self.start + other.start
        end = self.end + other.end

        # Возвращаем список промежутков
        return [
            AngleRange(
                start,
                end,
                self.start_inclusive and other.start_inclusive,
                self.end_inclusive and other.end_inclusive
            )
        ]


    # --------------------------------------------------------
    # ВЫЧИТАНИЕ ПРОМЕЖУТКОВ
    # --------------------------------------------------------

    def __sub__(self, other):
        # Проверяем тип
        if not isinstance(other, AngleRange):
            return NotImplemented

        # Вычитаем соответствующие границы
        start = self.start - other.end
        end = self.end - other.start

        # Возвращаем список промежутков
        return [
            AngleRange(
                start,
                end,
                self.start_inclusive and other.end_inclusive,
                self.end_inclusive and other.start_inclusive
            )
        ]


# ============================================================
# ПРОВЕРКА РАБОТЫ ПРОГРАММЫ
# ============================================================

# Создаём угол из радианов
a1 = Angle.from_radians(math.pi / 2)

# Создаём угол из градусов
a2 = Angle.from_degrees(90)

# Выводим углы
print("a1 =", a1)
print("a2 =", a2)

# Проверяем repr
print("repr(a1) =", repr(a1))

# Проверяем получение радианов
print("Радианы:", a1.get_radians())

# Проверяем получение градусов
print("Градусы:", a1.get_degrees())

# Изменяем угол через setter
a1.set_degrees(180)

# Проверяем результат
print("После set_degrees:", a1)

# Проверяем сравнение
print("a1 == a2:", a1 == a2)

# Создаём новые углы
a3 = Angle.from_degrees(30)
a4 = Angle.from_degrees(60)

# Проверяем сложение
print("30° + 60° =", a3 + a4)

# Проверяем вычитание
print("60° - 30° =", a4 - a3)

# Проверяем сложение с числом
print("30° + π =", a3 + math.pi)

# Проверяем умножение
print("30° * 2 =", a3 * 2)

# Проверяем деление
print("60° / 2 =", a4 / 2)

# Проверяем float
print("float(a3) =", float(a3))

# Проверяем int
print("int(a3) =", int(a3))


# ============================================================
# ПРОВЕРКА ANGLERANGE
# ============================================================

# Создаём промежуток от 30° до 120°
r1 = AngleRange(
    Angle.from_degrees(30),
    Angle.from_degrees(120)
)

# Создаём промежуток от 60° до 90°
r2 = AngleRange(
    Angle.from_degrees(60),
    Angle.from_degrees(90)
)

# Выводим промежутки
print("r1 =", r1)
print("r2 =", r2)

# Выводим repr
print("repr(r1) =", repr(r1))

# Получаем длину промежутка
print("Длина r1 в радианах =", abs(r1))

# Проверяем принадлежность угла
print("60° входит в r1:", Angle.from_degrees(60) in r1)

# Проверяем принадлежность другого промежутка
print("r2 входит в r1:", r2 in r1)

# Проверяем сравнение промежутков
print("r1 > r2:", r1 > r2)

# Складываем промежутки
print("r1 + r2 =", r1 + r2)

# Вычитаем промежутки
print("r1 - r2 =", r1 - r2)