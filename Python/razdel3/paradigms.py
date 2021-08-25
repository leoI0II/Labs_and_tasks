# # task4 DONE
# def powodd(num):
#     if num % 2:
#         return num ** 2
#     else:
#         return num

# def subt(num):
#     if num > 10:
#         return num - num % 3
#     else:
#         return num

# def solve():
#     powodd_ = list(map(powodd, num_list))
#     subt_ = list(map(subt, powodd_))
#     return subt_

# num_list = list(map(int, input().split(' ')))
# #print(solve())




# task5 DONE

# def solve():
#     #nums = list(map(int, input().split(' ')))
    
#     sum_ = lambda x, y : x + y
#     diff = lambda x, y : x - y
#     pro = lambda x, y : x * y
    
#     answers = []
#     answers.append( sum_(nums[0], nums[1] ) )
#     answers.append( diff(nums[0], nums[1]) )
#     answers.append( pro(nums[0], nums[1]) )
#     return answers

# nums = list(map(int, input().split(' ')))
# print(solve())


# task6 DONE

# def solve():
#     res_list = list(map(lambda x: x **2, nums))
#     return res_list

# nums = list(map(int, input().split(' ')))
# print(solve())



#               task7 DONE

# def solve(passwords):
#     passList = passwords.split(';')
    
#     answer = []

#     for password in passList:
#         if len(password) >= 6:
#             digits = list(filter(str.isdigit, password))
#             if len(digits) and ''.join(digits)!= password:
#                 lower = list(filter(str.lower, password))
#                 if len(lower):
#                     upper = list(filter(str.upper, password))
#                     if len(upper):
#                         answer.append(password)
#     if len(answer):
#         return ','.join(answer)
#     else:
#         return 'empty result'

# print(solve(input()))


#               task8 DONE

# def solve(passwords):
#     passList = passwords.split(';')
    
#     answer = []

#     for password in passList:
#         lenP = lambda x: len(x) >= 6
#         if lenP(password):
#             dg = lambda x: x.isdigit()
#             digits = list(filter(dg, password))
#             if len(digits) and ''.join(digits) != password:
#                 lw = lambda x: x.islower()
#                 lower = list(filter(lw, password))
#                 if len(lower):
#                     up = lambda x: x.isupper()
#                     upper = list(filter(up, password))
#                     if len(upper):
#                         answer.append(password)
#     if len(answer):
#         return ','.join(answer)
#     else:
#         return 'empty result'

# print(solve(input()))




#           task9

# def solve(codes):
#     spl = codes.split(';')
    
#     city = spl[0].split(',')
#     adress = spl[1].split(',')
#     track = spl[2].split(',')

#     lst = list(zip(city, adress, track))

#     strSolve = ''

#     for tup in lst:
#         strSolve += ','.join(tup)
#         strSolve += ';'
#     return strSolve[:-1]


# print(solve(input()))



# def digittrue(x):
#     if x.isdigit():
#         return str(int(x)*2)

# def jn(x):
#     if x.isdigit():
#         if int(x) % 2 == 0:
#             return x
#     return x*2

# a = ['Ab', 'abc', '1', '2', 'klm*']

# str1 = ','.join(list(filter( lambda x: len(x) > 2, a)))
# str2 = ','.join(list(filter( digittrue, a )))
# str3 = ','.join(list(map( lambda x: x if x.isdigit() and int(x)%2 == 0 else x*2 , a )))

# print(str1, str2, str3)


# def s(x):
#     return int(x)%2 == 0 or x*2





# def solve(obj):
#     a = ','.join(list(filter(lambda x: len(x) > 2, obj)))
#     b = list(filter(lambda x: x.isdigit() , obj))
#     b = ','.join(list(map(lambda x: str(int(x)*2), b)))
#     c = list(filter( la, obj ))
#     c = ','.join(list(map( check, c )))
#     return (a, b, c)

# def la(elem):
#     return (str(elem).isdigit and int(str(elem).isdigit) % 2 == 0) or (str(elem).isdigit != True)


# def check(elem):
#     if elem.isdigit():
#         return elem
#     else:
#         return elem*3

# a = input().split(',')
# print(solve(a))