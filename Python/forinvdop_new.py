# import math
# num_bit, dig = int(input()), input()

# dig1 = int(math.fabs(int(dig)))

# if int(math.fabs(int(dig))) < 2**(num_bit - 1):
#     if dig != '-0':
#         s = []
#         for i in range(num_bit-1):
#             s.append(str(dig1 % 2))
#             dig1 //= 2

#         bitpad = s               #прямой код
#         if int(dig) < 0:
#             bitpad.append('1')
#         else:
#             bitpad.append('0')
#         bitpad = bitpad[::-1]

#         _bitpad_ = ''.join(bitpad)

#         negbit = []                               #обратный код
#         if bitpad[0] == '0':
#             for bit in bitpad:
#                 negbit.append(bit) 
#         else:
#             negbit.append('1')
#             for i in range (1, len(bitpad)):
#                 if bitpad[i] == '0':
#                     negbit.append('1')
#                 else:
#                     negbit.append('0')

#         _negbit_ = ''.join(negbit)


#         addbit = []                              #дополнительный код
#         if bitpad[0] == '0':
#             for bit in bitpad:
#                 addbit.append(bit)
#             _addbit_ = ''.join(addbit)
#         else:
#             num = int(_negbit_[1:], 2) + 1
#             new_n = []
#             for i in range(num_bit-1):
#                 new_n.append(str(num % 2))
#                 num //= 2
#             new_n.append('1')
#             _addbit_ = ''.join(new_n[::-1])
#     else:
#         _bitpad_ = '10000000'
#         _negbit_ = '11111111'
#         _addbit_ = 'impossible'
# else:
#     _bitpad_ = 'impossible'
#     _negbit_ = 'impossible'
#     num = int(dig)
#     if num > 0:
#         num_dop = []
#         for i in range(num_bit-1):
#             num_dop.append(str(num % 2))
#             num //= 2
#         num_dop.append('0')
#         num_dop = num_dop[::-1]
#         _addbit_ = ''.join(num_dop)
#     else:
#         num += 1
#         num_dop = []
#         for i in range(num_bit-1):
#             num_dop.append(str(num % 2))
#             num //= 2
#         num_dop.append('1')
#         num_dop = num_dop[::-1]
#         _addbit_ = ''.join(num_dop)

# print(_bitpad_, _negbit_, _addbit_)






import math

bit, num = int(input()), input()

abs_num = int(math.fabs(int(num)))

def _perevod_(num, bits):
    razr = []
    for i in range(0, bits-1):
        razr.append(str(num % 2))
        num //= 2
    return ''.join(razr)[::-1]

def znak(num):
    if num > 0:
        return '0'
    else:
        return '1'

impossible = 'impossible'

if abs_num < 2**(bit - 1):
    #forward = []; negative = []; add = []
    if num[0] != '-':
        forward = znak(int(num)) + _perevod_(abs_num, bit)
        negative = forward; add = forward
    else:
        forward = znak(int(num)) + _perevod_(abs_num, bit)
        
        negative = znak(int(num))
        for i in range(1, bit-1):
            if forward[i] == '1':
                negative += '0'
            else:
                negative += '1'
        
        add = znak(int(num))
        add_neg = negative[1:]
        add += _perevod_(int(add_neg, 2) + 1, bit)
    
    print(forward, negative, add)
else:
    if num[0] != '-':
        print(impossible, impossible, impossible)
    else:
        add = znak(int(num)) + _perevod_(abs_num, bit)
        print(impossible, impossible, add)