class List:
    def __init__(self, value = None):
        self.value = value
        self.next_node = None
    def push_back(self, value):
        current = self
        while current.next_node != None:
            current = current.next_node
        current.next_node = List(value)
    def push_front(self, value):
        current = List(value)
        current.next_node = self
        self = current
    def __str__(self):
        str_to_ret = ""
        current = self
        while current.next_node != None:
            str_to_ret += f"{current.value} -> "
            current = current.next_node
        str_to_ret += f"{current.value}"
        return str_to_ret
    def pop_back(self):
        current = self
        while current.next_node.next_node != None:
            current = current.next_node
        current.next_node = None
    def pop_front(self):
        self = self.next_node
    
    
a = List(10)
a.push_back(20)
a.push_back(21)
a.push_back(321)
print(a)
a.pop_back()
print(a)
a.pop_front()
print(a)
