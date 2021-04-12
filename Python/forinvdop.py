import math
num_bit, dig = int(input()), input()

dig1 = int(math.fabs(int(dig)))

if dig != '-0':
    if int(math.fabs(int(dig))) < 2**(num_bit - 1):
        s = []
        for i in range(num_bit-1):
            s.append(str(dig1 % 2))
            dig1 //= 2

        bitpad = s               #прямой код
        if int(dig) < 0:
            bitpad.append('1')
        else:
            bitpad.append('0')
        bitpad = bitpad[::-1]

        _bitpad_ = ''.join(bitpad)

        negbit = []                               #обратный код
        if bitpad[0] == '0':
            for bit in bitpad:
                negbit.append(bit) 
        else:
            negbit.append('1')
            for i in range (1, len(bitpad)):
                if bitpad[i] == '0':
                    negbit.append('1')
                else:
                    negbit.append('0')

        _negbit_ = ''.join(negbit)


        addbit = []                              #дополнительный код
        if bitpad[0] == '0':
            for bit in bitpad:
                addbit.append(bit)
            _addbit_ = ''.join(addbit)
        else:
            for bit in negbit:
                addbit.append(bit)

            n = int(''.join(addbit), 2) + 1
            new_n = []
            for i in range(num_bit-1):
                new_n.append(str(n % 2))
                n //= 2
            _addbit_ = ''.join(new_n)
    else:
        _bitpad_ = 'impossible'
        _negbit_ = 'impossible'

else:
    _bitpad_ = []
    _bitpad_.append('1')
    for i in range(num_bit - 1):
        _bitpad_.append('0')
    _bitpad_ = ''.join(_bitpad_)
    
    _negbit_ = []
    _negbit_.append('0')
    for i in range(num_bit - 1):
        _negbit_.append('1')
    _negbit_ = ''.join(_negbit_)

    _addbit_ = 'impossible'



print(_bitpad_, _negbit_, _addbit_)