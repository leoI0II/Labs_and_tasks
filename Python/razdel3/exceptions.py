#       task1 DONE

# def addition(a , b):
#     try:
#         return a + b
#     except TypeError:
#         return 'Type error!'


#       task2 DONE

# def get_item(lst, index):
#     try:
#         lst[index]
#     except IndexError:
#         print('This index is not in the list!')
#     else:
#         print(lst[index])
#         print('No error!')
#     finally:
#         return 'The finally statement has executed!'

# lst = 'assvsddf'
# index = 3
# print(get_item(lst, index))




#       task3 DONE

# import math

# class MyException(Exception):
#     pass


# def find_leg(input_list):
#     # type your code with raise here
#     hyp = input_list[1]
#     rad = math.radians(input_list[0])

#     if input_list[0] <= 0:
#         raise MyException('Such angle cannot exist in a right triangle!')
#     if input_list[0] >= 90:
#         raise MyException('Such angle cannot exist in a right triangle!')
#     if hyp <= 0:
#         raise MyException('Such hypotenuse cannot exist in a right triangle!')

#     return round(math.cos(rad)*hyp, 5)

# print(find_leg([90, 3]))




#       task4

