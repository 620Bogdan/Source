def calculate_delivery_cost(order, customer, address):

    # Guard Clauses

    if not order:
        return {
            "success": False,
            "cost": 0,
            "message": "Заказ отсутствует"
        }

    if not address:
        return {
            "success": False,
            "cost": 0,
            "message": "Адрес доставки не указан"
        }

    if order["weight"] <= 0:
        return {
            "success": False,
            "cost": 0,
            "message": "Вес должен быть больше 0"
        }

    if order["weight"] > 50:
        return {
            "success": False,
            "cost": 0,
            "message": "Максимальный вес — 50 кг"
        }

    if order["total"] < 1000:
        return {
            "success": False,
            "cost": 0,
            "message": "Минимальная сумма заказа — 1000 рублей"
        }

    # самовывоз
    if order["delivery_type"] == "pickup":
        return {
            "success": True,
            "cost": 0,
            "message": "Самовывоз"
        }

    # бесплатная доставка
    if (
        customer["vip"] and order["total"] >= 5000
    ) or (
        order["total"] >= 10000
        and not address["remote"]
    ):
        return {
            "success": True,
            "cost": 0,
            "message": "Бесплатная доставка"
        }

    # расчет стоимости

    if address["city"]:

        if order["weight"] <= 5:
            cost = 300

        elif order["weight"] <= 10:
            cost = 500

        else:
            cost = 500 + (order["weight"] - 10) * 50

    else:
        cost = 1000 + order["weight"] * 100

    # скидка новому клиенту
    if customer["new"]:
        cost *= 0.85

    # удаленный регион
    if address["remote"]:
        cost *= 1.2

    return {
        "success": True,
        "cost": round(cost, 2),
        "message": "Стоимость рассчитана"
    }


# ===== Ввод данных =====

weight = float(input("Введите вес заказа (кг): "))
total = float(input("Введите сумму заказа: "))

delivery_type = input(
    "Тип доставки (pickup/courier): "
).lower()

vip = input(
    "VIP клиент? (да/нет): "
).lower() == "да"

new = input(
    "Новый клиент? (да/нет): "
).lower() == "да"

city = input(
    "Доставка по городу? (да/нет): "
).lower() == "да"

remote = input(
    "Отдаленный регион? (да/нет): "
).lower() == "да"


order = {
    "weight": weight,
    "total": total,
    "delivery_type": delivery_type
}

customer = {
    "vip": vip,
    "new": new
}

address = {
    "city": city,
    "remote": remote
}

result = calculate_delivery_cost(
    order,
    customer,
    address
)

print("\nРезультат:")
print(result)
