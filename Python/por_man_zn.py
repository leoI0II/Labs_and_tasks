from math import fabs, floor, modf
def znak(num):
    if num >= 0:
        return '0'
    else:
        return '1'

number = input()
if number == '0':
    sign = '0'; por1 = ''; por2 = ''
    for i in range(8):
        por1 += '0'
    for i in range(11):
        por2 += '0'
    man1 = ''; man2 = ''
    for i in range(23):
        man1 += '0'
    for i in range(52):
        man2 += '0'
    print(sign, por1, man1, sep = '|'); print(sign, por2, man2, sep = '|')
elif number == '-0':
    sign = '1'; por1 = ''; por2 = ''
    for i in range(8):
        por1 += '0'
    for i in range(11):
        por2 += '0'
    man1 = ''; man2 = ''
    for i in range(23):
        man1 += '0'
    for i in range(52):
        man2 += '0'
    print(sign, por1, man1, sep = '|'); print(sign, por2, man2, sep = '|')
else:
    num_sign = znak(float(number))
    number = fabs(float(number))

    bin_c_ch = bin(floor(number))[2:]
    dr_ch = modf(number)[0]
    bin_dr_ch = ''
    n = 0
    while True:
        n = dr_ch * 2
        if str(n)[0] == '1':
            bin_dr_ch += '1'
            dr_ch = modf(n)[0]
        else:
            bin_dr_ch += '0'
            dr_ch = modf(n)[0]
        if n == 1.0:
            break

    k = int(len(bin_c_ch)) - 1
    por1 = bin(127 + k)[2:]
    por2 = bin(1023 + k)[2:]

    if bin_c_ch[0] == '1':
        bin_num_all = '1' + '.' + bin_c_ch[1:] + bin_dr_ch
    else:
        bin_num_all = '0' + '.' + bin_c_ch[1:] + bin_dr_ch

    man1 = bin_num_all[2:]; man2 = bin_num_all[2:]

    while len(man1) != 23 or len(man2) != 52:
        if len(man1) != 23:
            man1 += '0'
        if len(man2) != 52:
            man2 += '0'

    print(num_sign, por1, man1, sep='|'); print(num_sign, por2, man2, sep='|')



#1
import math
def solve(numders, x):
    _list = []
    e = 0.00001
    for num in numders:
        if math.fabs(num - x) <= e:
            _list.append(num)
    if _list:
        return _list
    else:
        return None


#2
bit, n1, n2 = int(input()), int(input()), int(input())
bitSum = bin( n1 + n2 )[2:]
# print(bitSum[len(bitSum)-bit-1::-1])
if len(bitSum) > bit:
    bitSum = bitSum[1:]
    print(int(bitSum,2))
else:
    print(int(bitSum,2))


#4
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
    if num >= 0:
        return '0'
    else:
        return '1'

impossible = 'impossible'

if abs_num < 2**(bit - 1):
    if num[0] != '-':
        forward = znak(int(num)) + _perevod_(abs_num, bit)
        negative = forward; add = forward
    else:
        forward = znak(int(num)) + _perevod_(abs_num, bit)
        
        negative = znak(int(num))
        for i in range(1, bit):
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


#5
