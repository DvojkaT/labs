# 1
# def triangle(a, b, c):
#     if(a + b > c) and (b + c > a) and (a + c > b):
#         print("Это треугольник")
#     else:
#         print("Это не треуголньик")

# a = int(input("Введите 1-ую сторону: "))
# b = int(input("Введите 2-ую сторону: "))
# c = int(input("Введите 3-ую сторону: "))
# triangle(a, b, c)
# 2
# import math


# def distance(x1, y1, x2, y2):
#     dis = math.sqrt((x2-x1) ** 2 + (y2-y1) ** 2)
#     return dis


# x1 = int(input("Введие x1: "))
# y1 = int(input("Введие y1: "))
# x2 = int(input("Введие x2: "))
# y2 = int(input("Введие y2: "))
# print(distance(x1, y1, x2, y2))
# 3
def number_to_words(n):
    d = {
        1: 'один',
        2: 'два',
        3: 'три',
        4: 'четыре',
        5: 'пять',
        6: 'шесть',
        7: 'семь',
        8: 'восемь',
        9: 'девять',
        10: 'десять',
        11: 'одиннадцать',
        12: 'двенадцать',
        13: 'тринадцать',
        14: 'четырнадцать',
        15: 'пятнадцать',
        16: 'шестнадцать',
        17: 'семнадцать',
        18: 'восемнадцать',
        19: 'девятнадцать',
        20: 'двадцать',
        30: 'тридцать',
        40: 'сорок',
        50: 'пятьдесят',
        60: 'шестьдесят',
        70: 'семьдесят',
        80: 'восемьдесят',
        90: 'девяносто',
    }
    
    if n < 20:
        return d[n]

    one  = n % 10
    tens = n // 10
    
    return d[tens * 10] + " " + d[one]

print(number_to_words(4))
print(number_to_words(13))
# 4
# def power(a, n):
#     a1 = a
#     for i in range(1, n):
#         a1 *= a
#     return a1


# a = int(input("Введите число: "))
# b = int(input("Введите степень: "))
# print(power(a, b))
# 5
# def palindrome(s):
#     s = s.replace(' ', '')
#     s = s.lower()
#     if s == s[::-1]:
#         print("Палиндром")
#     else:
#         print("Не палиндром")


# print(palindrome("А роза упала на лапу Азора"))
# 6
# messages = []


# def print_without_duplicates(message):
#     if message not in messages:
#         print(message)
#     messages.append(message)


# print_without_duplicates("aboba")
# print_without_duplicates("aboba")
# print_without_duplicates("aboba")
# print_without_duplicates("abo")
# 8
# def mirror(arr):
#     return arr + arr[::-1]
 
# print(mirror([1,2]))
# 9
# def from_string_to_list(string, container):
#     container += string.split()

# a = [1, 2, 3]
# from_string_to_list("4 5 6", a)
# print(*a)
# 10
# def transpose(matrix):
#     m = list(zip(*matrix))
#     matrix.clear()
#     matrix += m


# matrix = [[1, 2], [3, 4]]

# transpose(matrix)
# for line in matrix:
#     print(*line)
# 11
# def matrix(n=1, m=None, a=0):
#     if m is None:
#         m = n
#     return [[a for j in range(m)] for i in range(n)]

# args = map(int, input().split())

# m = matrix(*args)

# for row in m:
#     print(*row)
# 12
# def partial(*args):
#     result = [0]
#     for i, a in enumerate(args):
#         result.append(a + result[i])
    
#     return result

# print(partial(1, 0.5, 0.25, 0.125))
# 13
# def power(a, n):
#     if n == 0:
#         return 1
#     return a * power(a, n-1)

# print(power(2, 3))
# 14
# def recursive_len(some_list):
#     if some_list:
#         return 1 + recursive_len(some_list[1:])
#     return 0

# print(recursive_len([1, 2, 3, 4]))