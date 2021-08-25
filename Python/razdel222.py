# stroka = input().split(',')
# lenInt = 0; lenStr = 0

# for st in range(len(stroka)):
#     try:
#         int(stroka[st])
#     except ValueError:
#         lenStr += 1
#         continue
#     lenInt += 1
#     stroka[st] = int(stroka[st])


# print(lenStr, lenInt)
# print(stroka)


# if lenInt >= lenStr:
#     print('Чисел больше строк')
#     for i in range(len(stroka)):
#         print('lya1')
#         try:
#             ord(stroka[i])
#         except TypeError:
#             continue
#         #stroka.insert(st, str(ord(st)))
#         stroka[i] = ord(stroka[i])
#         # if type(stroka[i]) is str:
#         #     print('Checking', stroka[i])
#         #     stroka[i] = ord(stroka[i])
# else:
#     print('Строк больше чисел')
#     for i in range(len(stroka)):
#         print('lya2')
#         try:
#             int(stroka[i])
#         except ValueError:
#             continue
#         # if type(stroka[i]) is int:
#         print('Checking', stroka[i])
#         stroka[i] = chr(int(stroka[i]))

# for i in range(len(stroka)):
#     stroka[i] = str(stroka[i])




# string = input()
# print(ascii(string)[1:-1])


# a = bin(int(input()))[2::]
# on = 0
# for one in str(a):
#     if one == '1':
#         on += 1
# print(on)



#OK
# def solve(a,b):
#     b1 = int.bit_length(a)
#     b2 = int.bit_length(b)
#     if b1 > b2:
#         return a
#     else:
#         return b
# nums = input().split()
# a = int(nums[0])
# b = int(nums[1])
# print(solve(a,b))



#OK
# def solve(x):
#     if x & 1:
#         return False
#     else:
#         return True

# num = int(input())
# print(solve(num))


#OK
# nums = input().split()
# print(int(nums[0]) >> int(nums[1]))









#5
def solve(a, b):
    xor = a ^ b
    per = a & b
    #print('per is', per)
    if per == 0:
        # conc = str('0'+str(xor))
        # conc = end("%01d" % (int(xor)))
        return '%0.2d' % int(xor)
    else:
        return int(str(str(per)+str(xor)))

num = input().split()
print(solve(int(num[0]), int(num[1])))








#Формат представления данных на компьютере
#1 OK DONE
# import math
# def solve(numders, x):
#     _list = []
#     e = 0.00001
#     for num in numders:
#         if math.fabs(num - x) <= e:
#             _list.append(num)
#     if _list:
#         return _list
#     else:
#         return None

# nums = input().split(', ')
# number = float(input())
# nums = [float(num) for num in nums]
# print(solve(nums, number))









#2 OK DONE
# bit, n1, n2 = int(input()), int(input()), int(input())
# bitSum = bin( n1 + n2 )[2:]
# # print(bitSum[len(bitSum)-bit-1::-1])
# if len(bitSum) > bit:
#     bitSum = bitSum[1:]
#     print(int(bitSum,2))
# else:
#     print(int(bitSum,2))

# res = bitSum[len(bitSum)-bit:len(bitSum)]
# print(int(str(res),2))









#3
# num = float(input())

# if num < 0:
#     znak = 1
#     numWOZ = float(str(num)[1::]))
# else:
#     znak = 0

