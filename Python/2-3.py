import os

 def Min(ls):
     Min = float("inf")
     for c in ls:
         if c < Min:
             Min = c
     return Min

 def Max(ls):
     Max = float("-inf")
     for c in ls:
         if c > Max:
             Max = c
     return Max

 def Mean(ls):
     su = 0
     for c in ls:
         su += c
     return su / len(ls)

 def Median(ls):
     sorted_ls = sorted(ls)
     middle = len(sorted_ls) // 2
     if len(sorted_ls) % 2 != 0:
         return sorted_ls[middle]
     else:
         return (sorted_ls[middle - 1] + sorted_ls[middle]) / 2


 Dir = '/Users/nkt/Desktop/python/data'
 frames = []
 for file in os.listdir(Dir):
     frames.append(Dir + '/' + file)

 with open("frames_out", "w") as file_out:
     for i in range(len(frames)):
         with open(frames[i], "r") as f:
             data = f.readlines()
             data_float = list(map(float, data))
             dic = {"Min":Min(data_float), "Max":Max(data_float), "Mean":Mean(data_float), "Median":Median(data_float)}
             file_out.write(frames[i] + str(dic.items()))
             file_out.write("\n")

 # Task #2 (Validal password)

 def validate_password(n):
     alf = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
     cif = '0123456789'
     simb = '!@#$%^&*()_+-=[]{}|;:,.<>?`'
     st = 0
     za = 0
     v1 = len(n) >= 8
     v2 = False
     v3 = False
     v4 = False
     v5 = False
     for c1 in alf:
         if c1 in n.upper():
             v2 = True
             break
     for c2 in n:
         if c2.isdigit():
             v3 = True
             break
     for c3 in simb:
         if c3 in n:
             v4 = True
             break
     for c4 in n:
         if c4 in alf:
             za += 1
         elif c4 in alf.lower():
             st += 1
     if za != 0 and st != 0:
         v5 = True
     return (v1 and v2 and v3 and v4 and v5, [v1, v2, v3, v4, v5])


 password = validate_password(input())

 while password[0] == False:
     print(password)
     password = validate_password(input("Не валидный пароль! Повтори попытку: "))
 print("Done!")


##Task #3 (random password)


 from random import choice
 from time import sleep

 def choice_password(lenght, char):
     password = ''
     for _ in range(lenght):
         password += choice(char)
     return password

 upper = "ABCDEFGHJKLMNPQRSTUVWXYZ"
 lower = "abcdefghijkmnopqrstuvwxyz"
 digits = "23456789"
 special = "!@#$%^&*()_+-=[]{}|;:,.<>?"
 char = ''


 choose = input("Do you want the password to be set automatically? y/n ")
 if choose == 'y':
     char = upper + lower + digits + special
     length_password = 12
 else:
     reset_try = True
     while reset_try:
         try:
             length_password = int(input("How long is your password? Minimal length is 8: "))
             if length_password < 8:
                 print("Password length must be at least 8 characters!")
                 continue
             reset_try = False
         except ValueError:
             print("Error 404 :(\nWe need digits!")
             reset_try = True
            
     ch_upper = input("Do you want to use UPPER letters? y/n ")
     ch_lower = input("Do you want to use LOWER letters? y/n ")
     ch_digits = input("Do you want to use DIGITS? y/n ")
     ch_special = input("Do you want to use SPECIAL symbols? y/n ")
     if ch_upper == 'y':
         char += upper
     if ch_lower == 'y':
         char += lower
     if ch_special == 'y':
         char += special
     if ch_digits == 'y':
         char += digits
 if char == "":
     print("Oups! Bad Bad! I need more information! Okey I'll take my variants :)")
     char = upper + lower + digits + special
     sleep(1.5)
 print(choice_password(length_password ,char))

 <--------------Lesson_2----------------->

 import os


 def is_float(value):
         try:
             float(value)
             return True
         except ValueError:
             return False

 def values(data):
         data = data.strip()
         if data == '':
             return '', 'str'
         elif data.isdigit() or (data[0] == '-' and data[1:].isdigit()):
             return int(data), 'int'
         elif is_float(data):
             return float(data), 'float'
         else:
             return data, 'str'


 def delimiter(line):
     delimiters = [',', '\t', '|', ';']
     for delim in delimiters:
         if delim in line:
             return delim
     return ','

 def has_header(n):
     if len(n) == 6:
         return True
     else:
         return False



 Dir = '/Users/nkt/Desktop/3/data'
 frames = []
 for file in os.listdir(Dir):
     frames.append(Dir + '/' + file)


 with open("frames_out", "w") as file_out:
     for i in range(len(frames)):
         with open(frames[i], "r") as f:
             data = f.readlines()
             first_st = has_header(data)
        
         dell = delimiter(data[0])
        
         for line in data[1:]:
             parts = line.split(dell)
             values_list = []
             types_list = []
             for part in parts:
                 val, typ = values(part)
                 values_list.append(val)
                 types_list.append(typ)
            
             print({
                 'header': first_st,
                 'data': values_list,
                 'types': types_list
             })
         print()
