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