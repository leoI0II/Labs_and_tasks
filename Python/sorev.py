#task1
# root = int(input())
# print((5**root)%100)


#task2
# n = int(input())
# somma = 0
# for i in range(1, n+1):
#     if i % 2:
#         somma += -1*i
#     else:
#         somma += i

# print(somma)


#task3
# instr = input().split(' ')
# a = int(instr[0]) #ishodn
# b = int(instr[1]) # mniy den'
# amount_days = a + (a//b)
# if amount_days%b == 0:
#     amount_days = a + ((a + (a//b))//b)
# print(amount_days)


#task3
# n, m = map(int, input().split())
# day = 0
# i = 1
# while n > 0:
#     n = n - 1
#     day += 1
#     if day == m * i:
#         n += 1
#         i += 1
# print(day)

#task4

# n = len(input())
# print(n*25 + 25 + 1)



#task5 
# a, b, c = map(int, input().split())
# if a%2 + b%2 + c%2 == 1:
#     if a > ( b + c ):
#         print("Impossible")
#     else:
#         print(str(int((a+b-c)/2)), str(int((-a+b+c)/2)), str(int((a-b+c)/2)))
# elif b > a and b > c:
#     if b > ( a + c ):
#         print("Impossible")
#     else:
#         print(str(int((a+b-c)/2)), str(int((-a+b+c)/2)), str(int((a-b+c)/2)))
# elif c > a and c > b:
#     if c > ( a + b ):
#         print("Impossible")
#     else:
#         print(str(int((a+b-c)/2)), str(int((-a+b+c)/2)), str(int((a-b+c)/2)))
# elif a == b == c and a % 2 == 0 and a != 0:
#     print(str(int((a+b-c)/2)), str(int((-a+b+c)/2)), str(int((a-b+c)/2)))
# else:
#     print("Impossible")


#task7
import math
def isPrime(num):
    f = True
    if num == 1 or num == 0:
        f = False

    for i in range(2, math.sqrt(num)+1):
        if num % i == 0:
            f = False
    if f:
        return True
    else:
        return False

#import numpy as np

num = input().split()
n = int(num[0]); m = int(num[1])
a = []
for i in range(0, n):
   a.append([])
print(a)

if n <= 500 and m <= 500 and n >= 1 and m >= 1:
    f1 = False; f2 = False
    for i in range(0, n):
        k = 0
        for j in range(0, m):
            a[i][j].append(int(input()))
            if isPrime(a[i][j]):
                k += 1
        if k == m:
            f1 = True
    for j in range(0, m):
        h = 0
        for i in range(0, n):
            if isPrime(a[i][j]):
                h += 1
        if h == n:
            f2 = True
            break
    if f1 == True or f2 == True:
        print("0")
    else:
        now = 0; mi = 10**5
        f3 = False; f4 = False
        for i in range(0, n):
            for j in range(0, m):
                b = a[i][j]
                while isPrime(b) != 1:
                    now += 1
                    b += 1
            if now <= mi:
                mi = now
            now = 0
            break
        if ~f3:
            for j in range(0, m):
                for i in range(0, n):
                    c = a[i][j]
                    while isPrime(c) != True:
                        now += 1
                        c += 1
                if now <= mi:
                    mi = now
                now = 0
                break
        print(mi)