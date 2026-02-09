def validate_password(n):
    x = 'ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm'
    xx = '0123456789'
    xxx = '!@#$%^&*()_+-=[]{}|;:,.<>?`'
    st = 0
    za = 0
    v1 = len(n) >= 8
    v2 = False
    v3 = False
    v4 = False
    v5 = False
    for i in x:
        if i in n.upper():
            v2 = True
            break
    for j in n:
        if j.isdigit():
            v3 = True
            break
    for k in xxx:
        if k in n:
            v4 = True
            break
    for l in n:
        if l in x:
            za += 1
        elif l in x.lower():
            st += 1
    if za != 0 and st != 0:
        v5 = True
    return (v1 and v2 and v3 and v4 and v5, [v1, v2, v3, v4, v5])
password = validate_password(input())
while password[0] == False:
    print(password)
    password = validate_password(input("В пароле используются недопустимые символы, попробуйте ввести пароль корректно."))
print("Выполнено!")




import os
def minim(n):
    minim = float("inf")
    for i in n:
        if i < minim:
            minim = i
    return minim
def maxim(n):
    maxim = float("-inf")
    for i in n:
        if i > maxim:
            maxim = i
    return maxim
def sred(n):
    summ = 0
    for i in n:
        summ += i
    return summ / len(n)
def Median(n):
    sort = sorted(n)
    sredin = len(sort) // 2
    if len(sort) % 2 != 0:
        return sort[sredin]
    else:
        return (sort[sredin - 1] + sort[sredin]) / 2
Dir = 'C:\\Users\\student24\\Desktop\\python\\data'
frames = []
for file in os.listdir(Dir):
    frames.append(Dir + '/' + file)
with open("frames_out", "w") as file_out:
    for k in range(len(frames)):
        with open(frames[k], "r") as f:
            data = f.readlines()
            data_float = list(map(float, data))
            dic = {"Минимум":Min(data_float), "Максимум":Max(data_float), "Среднее":sered
            file_out.write("\n")



from random import choice
from time import sleep

def choice_password(len_, char):
    password = ''
    for _ in range(len_):
        password += choice(char)
    return password


capit = "ABCDEFGHJKLMNPQRSTUVWXYZ"
small = "abcdefghijkmnopqrstuvwxyz"
numbers = "123456789"
simv = "!@#$%^&*()_+-=[]{}|;:,.<>?"
char = ''


choose = input("Установить пароль автоматически, без ваших усилий? Введите: Да или Нет.")
if choose == 'Да':
    char = upper + lower + digits + special
    lenpassword = 12
else:
    reset_try = True
    while reset_try:
        try:
            lenpassword = int(input("Минимальная длинна пароля 8символов, постарайтесь соблюсти это условие. "))
            if lenpassword < 8:
                print("Минимальная длинна пароля 8символов, наверное вы где-то ошиблись, попробуйте заного.")
                continue
            reset_try = False
        except ValueError:
            print("Oшибка")
            reset_try = True
            
    ch_capit = input("Использовать заглавные буквы? Введите: Да или Нет.")
    ch_small = input("Использовать буквы с маленьким регистром? Введите: Да или Нет.")
    ch_numbers = input("Использовать ли цифры в вашем пароле? Введите: Да или Нет.")
    ch_simv = input("Использовать специальные символы? Введите: Да или Нет.")
    if ch_capit == 'Да':
        char += capit
    if ch_small == 'Да':
        char += small
    if ch_simv == 'Да':
        char += simv
    if ch_numbers == 'Да':
        char += numbers
if char == "":
    print("Простите, но мне нужно больше данных.")
    char = upper + lower + digits + special
    sleep(1.5)
print(choice_password(lenpassword ,char))
