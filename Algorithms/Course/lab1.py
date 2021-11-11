class tree_elem:
    def __init__(self, data = None, parent = None, left = None, right = None):
        self.data = data
        self.parent = parent
        self.left = left
        self.right = right


class tree:
    def __init__(self, n, seq):
        for i in range(len(seq)):
            if seq[i] == -1:
                self.root = tree_elem(i)
                # self.root_index = i
                break
        for i in range(len(seq)):
            if seq[i] != -1:
                self.elem = tree_elem(i)
                self.elem.parent = tree_elem(seq[i])
                
    

n = int(input())
seq = input().split(' ')
seq = [int(elem) for elem in seq]

