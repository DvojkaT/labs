# 1 задание
# FilmName = input()
# CinemaName = input()
# Time = input()
# print("Билет на ", '" ',FilmName,' "',' в "', CinemaName, '" на ', Time, ' забронирован.')
# # 2 задание
# a = input()
# b = input()
# if ((a == "да" or a == "нет") and ((b == "да") or (b == "нет"))):
#     print("Верно")
# else:
#     print("Неверно")
# # 3 задание
# Login = input()
# LoginCheck = "@" in Login
# if LoginCheck:
#     print("Login error")
# Mail = input()
# MailCheck = "@" not in Mail
# if MailCheck:
#     print("Mail error")
# # 4 задание
# print (input())
# # 5 задание
# a = input()
# if a == "":
#     print("YES")
# else:
#     print("NO")
# # 6 задание, оно ужасно, я знаю
a = int(input())
max = -5
min = 10
third = 0;
num1 = a // 100
num2 = (a // 10) % 10
num3 = a % 10
for i in range(3):
    if a % 10 > max:
        max = a % 10
    if a % 10 < min:
        min = a % 10
    a //= 10
if num1 != max and num1 != min:
    third = num1
elif num2 != max and num2 != min:
    third = num2
else:
    third = num3

if (max+min)/2==third:
    print("Красивое число :3")
else:
    print("Обычное число :c")
# # 7 задание