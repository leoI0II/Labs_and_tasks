stroka = input().split(',')
# intov = []

# for st in stroka:
    # try:
    #     int(st)
    # except ValueError:
    #     continue
#     intov.append(int(st))
#     stroka.remove(st)


# if len(intov) >= len(stroka):
#     for st in stroka:
#         intov.append(ord(st))
# else:
#     for i in intov:
#         stroka.append(chr(i))


lenInt = 0; lenStr = 0

for st in stroka:
    try:
        int(st)
    except ValueError:
        lenStr += 1
        continue
    lenInt += 1
print(lenStr, lenInt)
print(stroka)

# if lenInt >= lenStr:
#     print('Чисел больше строк')
#     for i in range(len(stroka)):
#     #     try:
#     #         ord(st)
#     #     except TypeError:
#     #         continue
#     #     #stroka.insert(st, str(ord(st)))
#     #     st = ord(st)
#         if type(stroka[i]) is str:
#             print('Checking', stroka[i])
#             stroka[i] = ord(stroka[i])
# else:
#     print('Строк больше чисел')
#     for i in range(len(stroka)):
#         # try:
#         #     int(stroka[i])
#         # except ValueError:
#         #     continue
#         if type(stroka[i]) is int:
#             print('Checking', stroka[i])
#             stroka[i] = chr(int(stroka[i]))

for i in range(len(stroka)):
    print('kekekek')
    if lenInt >= lenStr:
        print('lalalal')
        if type(stroka[i]) is str:
            print('Checking', stroka[i])
            stroka[i] = ord(stroka[i])
    else:
        print('yalyalya')
        if type(stroka[i]) == '<class int>':
            print('Checking', stroka[i])
            stroka[i] = chr(int(stroka[i]))

print(''.join(stroka))