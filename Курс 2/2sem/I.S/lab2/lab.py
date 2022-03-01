#1
# line = input()
# print(line[2]) # третий символ
# print(line[-2]) # препоследний символ
# print(line[:5]) # первые 5 символов
# print(line[:-2]) # всё кроме последних двух симоволов
# print(line[::2]) # четные индексы
# print(line[1::2]) # нечетные индексы
# print(line[::-1]) # в обратном порядке
# print(line[::-2]) # с последнего через один
# print(len(line))
#2
# line = input()
# part1 = line[(len(line) + 1) // 2:]
# part2 = line[:(len(line) + 1) // 2]
# print(part1 + part2)
#3
# list = input()
# first_part = list[:list.find('h')] 
# second_part = list[list.find('h'):list.rfind('h') + 1]
# third_part = list[list.rfind('h') + 1:]
# s = first_part + second_part[::-1] + third_part
# print(s)
#4
# list = input()
# if list.count('f') == 1:
#     print(list.find('f'))
# elif list.count('f') >= 2:
#     print(list.find('f'), list.rfind('f'))
#5
# list = [int(i) for i in input().split()]
# for i in range(1, len(list)):
#     if list[i] > list[i - 1]:
#         print(list[i])
#6
# list = [int(i) for i in input().split()]
# for i in range(1, len(list)):
#     if list[i-1] * list[i] > 0:
#         print(list[i-1], list[i])
#7
# list = [int(i) for i in input().split()]
# for i in range(1, len(list), 2):
#     list[i - 1], list[i] = list[i], list[i - 1]
# print(' '.join([str(i) for i in list]))
#8
a = [int(s) for s in input().split()]
for i in range(len(a)):
    for j in range(len(a)):
        if i != j and a[i] == a[j]:
            break
    else:
        print(a[i], end=' ')

