#1

d = {1:'abs', 2:'dwefabsrefger', 3:'abscefrfcsd', 4:'lol', 5:'ewjnabsedjen'}

def solve(D, s='abs'):
    l1 = []
    l2 = []
    lValues = []

    for key in D:
        lValues.append(D[key])

    for val in lValues:
        if type(val) == str and val.count(s) > 0 and not val.startswith(s) and not val.endswith(s):
            l1.append(val)

    for val in lValues:
        if len(str(val)) == len(s):
            l2.append(val)
    return l1, l2

print(solve(d))












#2
# def solve(D):
