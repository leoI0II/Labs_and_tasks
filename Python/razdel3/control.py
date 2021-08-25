#task1 DONE
# nums = list(map(float, input().split(',')))
# nums = list(filter(lambda x: x >= 0, nums))

# m = 1
# res = 1
# if len(nums):
#     for num in nums:
#         res *= num
#     print(res)
# else:
#     print("no results")



#task2 DONE
# def func(st_1, st_2 = 'a'):
#     st_2 = st_2.lower()
#     st_1 = st_1.lower()
#     res = st_1.count(st_2)
#     return res

# print(func("Marry christmas", 'ma'))


#task3 DONE
# def check(lVal):
#     for i in range(1, len(lVal)):
#         if abs(lVal[i] - lVal[i-1]) < 0.00002:
#             continue
#         else:
#             return False
#     return True

# def solve(L):
#     res = []
#     keys = list(L.keys())
#     for key in keys:
#         if check(L[key]):
#             res.append(key)
#     return res


# print(solve({1: [2.0, 2.000002], 2:[1.0, 1.0003]}))




#task4 DONE
# class MyStr(str):
#     def split(self, object):
#         res = []
#         if isinstance(object, dict):
#             keys = list(object.keys())
#             newK = ''.join(list(filter(lambda x: x[len(x)-1].isdigit(), keys)))
#             res = super().split(newK)
#         elif isinstance(object, list):
#             res = ''.join(list(filter(lambda x: isinstance(x, str) and x.isalpha(), object)))
#             res = super().split(res)
#         elif isinstance(object, str):
#             res = super().split(object)
#         return res



#task5
# s1 = input().split(';')

# sa = s1[len(s1)-1].split(' ')

# for i in range(1, len(sa)):
#     if issubclass(sa[i], sa[i-1]):
#         print(True, end=' ')






# def check(s):
#     return '%' in s and s[0] != '%' and s[-1]!= '%'


# def solve(obj):
#     a = list(filter(lambda x: check(x), obj))
#     return ','.join(list(map( lambda x: x[0:4], a )))

# s = input().split(',')
# print(solve(s))



def solve(obj):
    s1 = ','.join(list(map(len1, obj)))
    s2 = ','.join(list(filter(d2, obj)))
    s3 = ','.join(list(map(lambda x: x[0:2], obj)))
    return (s1, s2, s3)

def len1(s):
    if s.isdigit():
        return str(len(str(s)))
    return str(len(s))

def d2(s):
    if str(s).isdigit():
        if int(s) > 999:
            return True
    return False



s = input().split(',')
print(solve(s))