# 1 задание
# FilmName = input()
# CinemaName = input()
# Time = input()
# print("Билет на ", '" ', FilmName, ' "', ' в "', CinemaName, '" на', Time, 'забронирован.')
# 2 задание
# a = input()
# b = input()
# if (a == "да" or a == "нет") and ((b == "да") or (b == "нет")):
#     print("Верно")
# else:
#     print("Неверно")
# 3 задание
# Login = input()
# LoginCheck = "@" in Login
# if LoginCheck:
#     print("Login error")
# Mail = input()
# MailCheck = "@" not in Mail
# if MailCheck:
#     print("Mail error")
# 4 задание
# print (input())
# 5 задание
# a = input()
# if a == "":
#     print("YES")
# else:
#     print("NO")
# 6 задание, оно ужасно, я знаю
# a = int(input())
# max = -5
# min = 10
# third = 0
# num1 = a // 100
# num2 = (a // 10) % 10
# num3 = a % 10
# for i in range(3):
#     if a % 10 > max:
#         max = a % 10
#     if a % 10 < min:
#         min = a % 10
#     a //= 10
# if num1 != max and num1 != min:
#     third = num1
# elif num2 != max and num2 != min:
#     third = num2
# else:
#     third = num3

# if (max + min) / 2 == third:
#     print("Красивое число :3")
# else:
#     print("Обычное число :c")
# 7 задание
# number = int(input())
# first_number = number // 1000
# second_number = (number // 100) % 10
# third_number = (number // 10) % 10
# fourth_number = number % 10
# if first_number > second_number:
#     first_number, second_number = second_number, first_number
# if second_number > third_number:
#     second_number, third_number = third_number, second_number
# if third_number > fourth_number:
#     third_number, fourth_number = fourth_number, third_number
# if first_number > second_number:
#     first_number, second_number = second_number, first_number
# if second_number > third_number:
#     second_number, third_number = third_number, second_number
# if first_number > second_number:
#     first_number, second_number = second_number, first_number
# if first_number == 0 and second_number:
#     first_number, second_number = second_number, first_number
# elif first_number == 0 and third_number:
#     second_number, third_number = third_number, second_number
# elif first_number == 0 and fourth_number:
#     first_number, fourth_number = fourth_number, first_number
# final_number = first_number * 1000 + second_number * 100 + third_number * 10 + fourth_number
# print(final_number)
# 8 задание
# count = 0
# max = 0
# min = 999
# while True:
#     num = input()
#     if num == "!":
#         break
#     num = int(num)
#     if (num < 190) and (num > 150):
#         if num > max:
#             max = num
#         if num < min:
#             min = num
#         count += 1
# print(count, "\n", min, max)
# 9 задание
# while True:
#     first = input("Введите пароль: ")
#     second = input("Повторно введите пароль:")
#     if len(first) < 8:
#         print("Короткий!")
#     elif first.find("123") != -1:
#         print("Простой!")
#     elif first != second:
#         print("Различаются!")
#     else:
#         print("OK")
#         break
# 10 задание
# import math
# while True:
#     number = int(input("Введите выражение: "))
#     sign = input()
#     if sign == "x":
#         print(number)
#         break
#     if sign == "+":
#         sec_number = int(input())
#         print(int(number + sec_number))
#         continue
#     if sign == "-":
#         sec_number = int(input())
#         print(number - sec_number)
#         continue
#     if sign == "*":
#         sec_number = int(input())
#         print(number * sec_number)
#         continue
#     if sign == "/":
#         sec_number = int(input())
#         print(int(number / sec_number))
#         continue
#     if sign == "%":
#         sec_number = int(input())
#         print(number % sec_number)
#         continue
#     if sign == "!":
#         if number > 0:
#             print(math.factorial(number))
#         else:
#             continue
# 11 задание
# number = int(input("Введите высоту пирамиды:"))
# for i in range(1, number + 1):
#     number -= 1
#     print(number * " " + (i*2-1) * "*" + number * " ")
# 12 задание
# number = int(input())
# start = 1
# lenght = 1
# currentLenght = 0
# while start <= number:
#     print(start, end=" ")
#     start += 1
#     currentLenght += 1
#     if currentLenght == lenght:
#         print()
#         lenght += 1
#         currentLenght = 0
# 13 задание
hight = int(input())
wight = int(input())
symbol = input()
for i in range(hight):
    if i == 0 or i == hight - 1:
        for j in range(wight):
            print(symbol, end='')
    else:
        print(symbol, end='')
        for j in range(1, wight - 1):
            print(' ', end='')
        print(symbol, end='')
    print()
