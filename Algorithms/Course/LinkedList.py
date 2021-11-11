class Node:
    def __init__(self, data, prev = None, next = None):
        self.__data = data
        self.__prev__ = prev
        self.__next__ = next

    def get_data(self):
        if self:
            return self.__data
        else:
            return None

    def __str__(self):
        return "data: {}, prev: {}, next: {}".format(self.get_data() if self else None, self.__prev__.get_data() if self.__prev__ else None, self.__next__.get_data() if self.__next__ else None)

    # def __str__(self):
    #     if self.__next__ == None and self.__prev__ == None:
    #         return 'data: {}, prev: {}, next: {}'.format(self.__data, None, None)
    #     elif self.__prev__ == None:
    #         return 'data: {}, prev: {}, next: {}'.format(self.__data, None, self.__next__.__data)
    #     elif self.__next__ == None:
    #         return 'data: {}, prev: {}, next: {}'.format(self.__data, self.__prev__.__data, None)
    #     else:
    #         return 'data: {}, prev: {}, next: {}'.format(self.__data, self.__prev__.__data, self.__next__.__data)

class LinkedList:
    def __init__(self, first = None, last = None):
        if first == None and last == None:
            self.__length = 0
            self.__first__ = None
            self.__last__ = None
        elif first == None and last != None:
            raise ValueError("invalid value for last")
        elif first != None and last == None:
            curr = first
            while(curr.__prev__ != None):
                # print("ejje")
                curr = curr.__prev__
            self.__first__ = curr
            l = 0
            while(curr.__next__ != None):
                l += 1
                curr = curr.__next__
            self.__last__ = curr
            self.__length = l+1
        else:
            # self.__first__ = first
            # self.__last__ = last
            # curr = self.__first__
            # while(curr):
            #     self.__length += 1
            #     curr = curr.__next__
            curr = first
            while(curr.__prev__ != None):
                curr = curr.__prev__
            self.__first__ = curr
            l = 0
            while(curr.__next__ != None):
                l += 1
                curr = curr.__next__
            self.__last__ = curr
            self.__length = l+1


    def __len__(self):
        return self.__length

    def __str__(self):
        if self.__length == 0:
            return 'LinkedList[]'
        else:
            curr = self.__first__
            while(curr.__prev__ != None):
                curr = curr.__prev__
            string = "LinkedList[length = " + str(len(self)) + ", ["
            while curr.__next__ != None:
                string += str(curr) + "; "
                curr = curr.__next__
            string += str(curr) + "]]"
            return string
    # def __str__(self):
    #     if len(self) == 0:
    #         return "LinkedList[]"
    #     elif len(self) == 1:
    #         return "LinkedList[legth = 1, [{}]]".format(self.__first__)
    #     else:
    #         return "LinkedList[length = {}, [{}; {}]]".format(self.__length, self.__first__, self.__last__)

    # def clear(self):
    #     curr = self.__first__
    #     while(curr):
    #         self.__first__.__prev__ = None
    #         self.__first__ = self.__first__.__next__
    #         curr = None
    #         curr = self.__first__
    #     self.__length = 0

    # def clear(self):
    #     curr = self.__last__
    #     while self.__last__ != None:
    #         self.__last__ = self.__last__.__prev__
    #         if self.__last__:
    #             self.__last__.__next__ = None
    #         curr = None
    #         curr = self.__last__
    #     self.__first__ = None
    #     self.__length = 0
    def clear(self):
        if len(self) == 0:
            return False
        while self.__first__ != None:
            temp = self.__first__
            self.__first__ = self.__first__.__next__
            temp = None
        self.__length = 0

    # def append(self, element):
    #     if self.__length == 0:
    #         self.__first__ = Node(element)
    #         self.__length += 1
    #         self.__last__ = self.__first__
    #     else:
    #         # curr = self.__first__
    #         # while(curr.__next__ != None):
    #         #     curr = curr.__next__
    #         # self.__last__ = Node(element, curr)
    #         # curr.__next__ = self.__last__
    #         # self.__length += 1
    #         curr = self.__last__.__next__
    #         curr = Node(element, self.__last__)
    #         self.__last__.__next__ = curr
    #         self.__last__ = curr
    #         self.__length += 1
    #         # self.__last.__next__ = Node(element, self.__last__)
    #         # self.__last__.__next__.__prev__ = self.__last__
    #         # self.__length += 1
    def append(self, element):
        if (len(self) == 0):
            self.__first__ = Node(element)
            self.__last__ = self.__first__
            self.__length = 1
        else:
            self.__last__.__next__ = Node(element, self.__last__)
            self.__last__ = self.__last__.__next__
            self.__length += 1

    def pop(self):
        if len(self) == 0:
            raise IndexError("LinkedList is empty!")
        elif (len(self) == 1):
            self.__last__ = None
            self.__first__ = None
            # del self.__last__
            # del self.__first__
            self.__length = 0
            return True
        self.__last__.__prev__.__next__ = None
        curr = self.__last__.__prev__
        self.__last__ = None
        self.__last__ = curr
        self.__length -= 1

    def popitem(self, element):
        curr = self.__first__
        if curr.get_data() and len(self) == 1:
            self.__first__ = None
            self.__length = 0
            return True
        elif curr.get_data() == element:
            curr = self.__first__.__next__
            self.__first__.__next__.__prev__ = None
            self.__first__ = None
            self.__first__ = curr
            self.__length -= 1
            return True
        curr = curr.__next__
        while(curr):
            if curr.get_data() == element:
                curr.__prev__.__next__ = curr.__next__
                curr.__next__.__prev__ = curr.__prev__
                curr = None
                self.__length -= 1
                return True
            curr = curr.__next__
        raise KeyError("<{}> doesn't exist!".format(element))


la = Node(10)
la.__next__ = Node(20, la)
la.__next__.__next__ = Node(30, la.__next__)
print(la)
print(la.__next__)
print(la.__next__.__next__)


a = LinkedList(la, la.__next__.__next__)
print(a)


a.pop()
print(a)
a.pop()
print(a)
a.pop()
print(a)
# a.append(la)
# print(a)

a.clear()
print(a)
a.append(1000)
print(a)

# print(la, la.__next__, la.__next__.__next__)


# na = Node(30)
# ns = Node(40, na)
# na.__next__ = ns

# nd = Node(50, ns)
# ns.__next__ = nd

# nf = Node(60, nd)
# nd.__next__ = nf

# q = LinkedList(ns, nd)

# print(q)
# q.append(70)
# print(q)

# q.pop()
# print(q)

# q.popitem(30)
# print(q)

# q.popitem(40)
# print(q)
# q.popitem(50)
# print(q)
# q.popitem(60)
# print(q)


class Node:
    def __init__(self, data, prev = None, next = None):
        self.__data = data
        self.__prev__ = prev
        self.__next__ = next

    def get_data(self):
        if self:
            return self.__data
        else:
            return None

    # def __str__(self):
    #     return "data: {}, prev: {}, next: {}".format(self.get_data(), self.__prev__.get_data() if self.__prev__ else None, self.__next__.get_data() if self.__next__ else None)
    def __str__(self):
        if self.__next__ == None and self.__prev__ == None:
            return 'data: {}, prev: {}, next: {}'.format(self.__data, None, None)
        elif self.__prev__ == None:
            return 'data: {}, prev: {}, next: {}'.format(self.__data, None, self.__next__.__data)
        elif self.__next__ == None:
            return 'data: {}, prev: {}, next: {}'.format(self.__data, self.__prev__.__data, None)
        else:
            return 'data: {}, prev: {}, next: {}'.format(self.__data, self.__prev__.__data, self.__next__.__data)


class LinkedList:
    def __init__(self, first = None, last = None):
        if first == None and last:
            raise ValueError("invalid value for last")
        elif first and last == None:
            self.__first__ = first
            self.__first__.__prev__ = None
            self.__first__.__next__ = None
            self.__first__.__data = first.get_data()
            self.__last__ = self.__first__
            self.__length = 1
        elif first and last:
            self.__first__ = first
            self.__last__ = last
            #-----------------
            self.__first__.__data = first.get_data()
            self.__last__.__data = last.get_data()
            self.__first__.__next__ = self.__last__
            self.__first__.__prev__ = None
            self.__last__.__next__ = None
            self.__last__.__prev__ = self.__first__
            #-----------------
            self.__length = 2
        else:
            self.__first__ = None
            self.__last__ = None
            self.__length = 0

    def __len__(self):
        return self.__length

    def append(self, element):
        if len(self) == 0:
            self.__first__ = Node(element)
            self.__last__ = self.__first__
            self.__length += 1
        else:
            new = Node(element, self.__last__)
            self.__last__.__next__ = new
            self.__last__ = new
            self.__length += 1

    # def __str__(self):
    #     if len(self) == 0:
    #         return "LinkedList[]"
    #     elif len(self) == 1:
    #         return "LinkedList[legth = 1, [{}]]".format(self.__first__)
    #     else:
    #         return "LinkedList[length = {}, [{}; {}]]".format(self.__length, self.__first__, self.__last__)

    def __str__(self):
        if self.__length == 0:
            return 'LinkedList[]'
        else:
            curr = self.__first__
            while(curr.__prev__ != None):
                curr = curr.__prev__
            string = "LinkedList[length = " + str(len(self)) + " ["
            while curr.__next__ != None:
                string += str(curr) + "; "
                curr = curr.__next__
            string += str(curr) + "]]"
            return string

    # def pop(self):
    #     if len(self) == 0:
    #         raise IndexError("LinkedList is empty!")
    #     elif len(self) == 1:
    #         self.__first__ = None
    #         self.__last__ = None
    #         self.__length = 0
    #     else:

    def pop(self):
        if len(self) == 0:
            raise IndexError("LinkedList is empty!")
        elif (len(self) == 1):
            self.__last__ = None
            self.__first__ = None
            # del self.__last__
            # del self.__first__
            self.__length -= 1
            return True
        self.__last__.__prev__.__next__ = None
        curr = self.__last__.__prev__
        self.__last__ = None
        self.__last__ = curr
        self.__length -= 1


    def popitem(self, element):
        curr = self.__first__
        if self.__first__.get_data() == element:
            self.__first__.__next__.__prev__ = None
            self.__first__ = self.__first__.__next__
            self.__length -= 1
            return True
        curr = curr.__next__
        while curr:
            if curr.get_data() == element:
                curr.__prev__.__next__ = curr.__next__
                curr.__next__.__prev__ = curr.__prev__
                curr = None
                self.__length -= 1
                return True
            curr = curr.__next__
        raise KeyError("<{}> doesn't exist!".format(element))

    # def clear(self):
    #     curr = self.__first__
    #     while(curr):
    #         self.__first__ = self.__first__.__next__
    #         curr = None
    #         curr = self.__first__
    #     self.__length = 0
    def clear(self):
        while self.__first__ != None:
            temp = self.__first__
            self.__first__ = self.__first__.__next__
            temp = None

    def append(self, element):
        if len(self) == 0:
            self.root = Node(element)
            self.tail = self.root
        else:
            self.tail.next_element = Node(element)
            self.tail = self.tail.next_element

    def append(self, after, elem):
        if len(self) == 0:
            self.root = Node(elem)
            self.tail = self.root
        else:
            curr = self.root
            while curr:
                if curr.data == after:
                    tmp = curr.next_element
                    curr.next_element = Node(elem)
                    curr.next_element.next_element = tmp
                    return True
                curr = curr.next_element
            self.tail.next_element = Node(elem)
            self.tail = self.tail.next_element
