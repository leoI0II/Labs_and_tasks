l = input().split(':')
ln = []

for i in range(len(l)-1):
    a = l[i]
    if a[len(a)-1:len(a)-2:-1] == 'a':
        ln.append(l[i])
        l.remove(l[i])

print(l, ln)