a = input().split('.')
b=[0,0,0]
c=[0,0,0]

if a[0][0] == '-':
    b[0] = 1
    c[0] = 1

if b[0] == 0:
    e = int(a[0])
else:
    t = a[0]
    a[0] = t[1:]
    e = int(a[0])

k = int.bit_length(e) - 1

b[1] = str(int(bin( 127 + k )[2::]))
c[1] = str(int(bin( 1023 + k )[2::]))

e = int(bin(e)[2:])
st = str(e)[1:]
st1 =''

g = int(a[1])
g = g * (10**(-len(a[1])))

while (g-int(g)) != 0:
    g *= 2
    if int(g)%2==0:
        st1 = st1+'0'
    else:
        st1 += '1'

b[2] = st + st1
c[2] = st + st1

while len(b[2]) != 23:
    b[2] += '0'

while len(c[2]) != 52:
    c[2] += '0'

print(b[0], b[1], b[2],sep = '|')
print(c[0], c[1], c[2],sep = '|')