# l = []
# for i in range(3):
#     l.append(str(input()))

# for j in range(len(l)):
#     li = list(l[j])
#     count = 0
#     for k in range(len(li)):
#         if li[k] == '-':
#             continue
#         if li[k] == '1': count += 1
#     if (int(l[j]) % 3 == 0 and int(l[j]) < 0) or (count > 0):
#         print(l[j])
# sum = 0
# max = -10000
# for i in range(-9563, -3101):
#     print(i)
#     if (i%7 == 0) and (i%11!=0) and (i%23!=0) and ((i*(-1))%10!=8):
#         sum += 1
#         print(sum, ' \n')
#         if i > max:
#             max = i
#             print(max, '\n')

# print(sum, max)
# a = []
# numA = int(input())

# for i in input().split():
#     a.append(int(i))

# Num = 0; Sum = a[0] + a[1]

# for i in range(1, len(a)):
#     if a[i] + a[i+1] > Sum:
#         Num = i
#         Sum = a[i] + a[i+1]

# print(Num, Sum)
a = input()
m = 9
s = 0
for i in a:
    if int(i) <= m:
        m = int(i)
        if m
print(s)