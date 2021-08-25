# #tests

# class person:
#     name = 'Mike'       #Атрибуты класса
#     age = 30            #класса person

# a = person()            #Экземпляры->
# b = person()

# person.x = 100          #Новый атрибут класса
#                         #также добавится в атрибуты экземпляров










# person.name2 = 'John'

# setattr(person, 'name2', 1000)
# setattr(person, 'y', 2000)

# print(person.__dict__)
# print()

# del person.name2
# print(person.__dict__)
# print()

# delattr(person, 'y')

# print(person.__dict__)





# class car:
#     model = 'BMW'
#     engine = 1.6

# a1 = car(); a2 = car()

# a1.seat = 4

# a1.model = "lada"

# setattr(a1, 'new', 'New attr')      #создается локальный атрибут, и при этом не создается в глобальном классе car

# print(a1.__dict__)
# print()
# print(car.__dict__)

# del a1.new

# print(a1.__dict__)





#test Наследование

# class A():
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age
#     def sleep(self):
#         print('Zzzzzzz')
    
# class B(A):
#     age = 50
#     name2 = 'Mike'

# qq = A('Jack', 20)

# print(qq.name, qq.age)




#Sites tests
# class Vehicle(object):
#     """docstring"""
    
#     # def __init__(self, color, doors, tires, vtype):
#     #     """Constructor"""
#     #     self.color = color
#     #     self.doors = doors
#     #     self.tires = tires
#     #     self.vtype = vtype
    
#     def color (self, color):
#         self.color = color

#     def doors(self, doors):
#         self.doors = doors

#     def tires(self, tires):
#         self.tires = tires

#     def vtype (self, vtype):
#         self.vtype = vtype

#     def brake(self):
#         """
#         Stop the car
#         """
#         return "%s braking" % self.vtype
    
#     def drive(self):
#         """
#         Drive the car
#         """
#         return "I'm driving a %s %s!" % (self.color, self.vtype)
 
 
# if __name__ == "__main__":
#     car = Vehicle()

#     car.color('blue')
#     car.vtype('Car')
#     car.tires(4)
#     car.doors(4)

#     print(car.brake())
#     print(car.drive())
 
#     truck = Vehicle("red", 3, 6, "truck")
#     print(truck.drive())
#     print(truck.brake())









#       task2 DONE
# class A():
#     def __init__(self, values):
#         self.values = values
    
# class B(A):
#     def __len__(self):
#         return len(self.values)

# #qq = B(input())

# print( B('123').__len__() )




#       task3 DONE

# class Segment:
#     def __str__(self):
#         return 'This is a line segment'

# a = Segment()
# print( a.__str__() )





#       task4 DONE ANSWER 2, 7
# class Segment:
#     def __str__(self):
#         return 'str called'


# class Line(Segment):
#     def __repr__(self):
#         return 'repr called'

# #a = Line()
# a = Segment()

# print(a)





#       task5

# class Shape:
#     count = 1
#     def __init__(self, ID = 0):
#         self.ID = Shape.count
#         Shape.count += 1

# class Rectangle(Shape):  # наследуется от Shape
    
#     def __str__(self):
#         return str(self.ID) + ':' + str(self.__class__.__name__)

# class Ellipse(Shape):  # наследуется от Shape
    
#     def __str__(self):
#         return str(self.ID)+':'+str(self.__class__.__name__)
#     pass

# class Square(Shape):  # наследуется от Shape
    
#     def __str__(self):
#         return str(self.ID)+':'+str(self.__class__.__name__)

# a = Rectangle()
# b = Ellipse()
# print(a, b)







# task 6

# from math import pi

# class Shape:
#     def area(self):
#         raise NotImplementedError('You should implement area for any Shape')

# class Rectangle(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметрами a и b
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b
#     # 2) переопределите метод area (self, a, b )
#     def area(self):
#         return self.a * self.b
#     # 3) переопределете метод __str__
#     def __str__(self):
#         return f'{self.area()}, {self.__class__.__name__}'

# class Ellipse(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметрами radius и second_radius
#     def __init__(self, radius, second_radius):
#         self.radius = radius
#         self.second_radius = second_radius
#     # 2) переопределите метод area
#     def area(self):
#         return int(pi * self.radius * self.second_radius)
#     # 3) переопределите метод __str__
#     def __str__(self):
#         return f'{self.area()}, {self.__class__.__name__}'

# class Square(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметром a
#     def __init__(self, a):
#         self.a = a
#     # 2) переопределите метод area
#     def area(self):
#         return self.a**2
#     # 3) переопределите метод __str__
#     def __str__(self):
#         return  f'{self.area()}, {self.__class__.__name__}'

# class ShapeList(list):  # наследуется от list
#     # 1) переопределите метод append
#     def append(self, shape):
#         if isinstance(shape, Shape):
#             super().append(shape)
#             #super(list, self).append(shape)
#     # 2) переопределите метод __str__
#     def __str__(self):
#         return '\n'.join(str(shape) for shape in self)


# a = Rectangle(4, 5)
# print(a)
# b = Ellipse(3, 4)
# c = Square(4)

# shapes_list = ShapeList()
# shapes_list.append(a)
# shapes_list.append(b)
# shapes_list.append(c)
# print(shapes_list)







#task 7
# from math import pi
# class Shape:
#     def area(self):
#         pass
#     def __eq__(self, other):
#         return self.area() == other.area()
#     def __lt__(self, other):
#         return self.area() < other.area()
#     def __le__(self, other):
#         return self.area() <= other.area()
#     def __ne__(self, other):
#         return self.area() != other.area()
#     def __gt__(self, other):
#         return self.area() > other.area()
#     def __ge__(self, other):
#         return self.area() >= other.area()


# class Rectangle(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметрами a и b
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b
#     # 2) переопределите метод area (self, a, b )
#     def area(self):
#         return self.a * self.b

# class Ellipse(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметрами radius и second_radius
#     def __init__(self, radius, second_radius):
#         self.radius = radius
#         self.second_radius = second_radius
#     # 2) переопределите метод area
#     def area(self):
#         return int(pi * self.radius * self.second_radius)

# class Square(Shape):  # наследуется от Shape
#     # 1) определите конструктор с параметром a
#     def __init__(self, a):
#         self.a = a
#     # 2) переопределите метод area
#     def area(self):
#         return self.a**2

# a = Rectangle(4, 5)
# b = Square(4)
# print( a.area() > b.area())




# # task 8

# class Window:
#     __height = 100
#     __width = 200
#     __square = 20000

#     def getWidth(self):
#         return Window.__width
#     def setWidth(self, width):
#         Window.__width = width
    
#     def getHeight(self):
#         return self.__height
#     def setHeight(self, height):
#         Window.__height = height
    
#     def getSquare(self):
#         return Window.__height * Window.__width


# class Window:
#     __height = 100
#     __width = 200
#     __square = 20000

#     def getWidth(self):
#         return self._Window__width
#     def setWidth(self, __width):
#         self.__width = __width
    
#     def getHeight(self):
#         return self._Window__height
#     def setHeight(self, __height):
#         self.__height = __height
    
#     def getSquare(self):
#         return self._Window__height * self._Window__width


# a = Window()
# a.setHeight(150)
# print(a.getHeight())

# a.setWidth(20)
# print(a.getWidth())

# print(a.getSquare())







# # task 9

# class IntList(list):
#     def append(self, num):
#         # должна переопределять метод базового класса
#         # добавляет только целочисленные значения
#         # остальные типы должна игнорировать - ничего не делать
#         if isinstance(num, int):
#             super().append(num)

#     def positive_sum(self):
#         # считает сумму положительных элементов списка
#         somma = 0
#         for num in self:
#             if num > 0:
#                 somma += num
#         return somma

#     def negative_sum(self):
#         neg_somma = 0
#         for num in self:
#             if num < 0:
#                 neg_somma += num
#         return neg_somma

#     def insert(self,index, num):
#         # должна переопределять метод базового класса
#         # добавляет только целочисленные значения
#         # остальные типы должна игнорировать - ничего не делать        
#         if isinstance(num, int):
#             super().insert(index, num)

#     def extend(self, object):
#         # должна переопределять метод базового класса
#         # добавляет только целочисленные значения из списка
#         # остальные типы должна игнорировать - ничего не делать
#         if isinstance(object, list):
#             for elem in object:
#                 if isinstance(elem, int):
#                     self.append(elem)
#         #super().extend(object)

# myl = IntList()
# a = [1,2,'23']
# myl.extend(a)
# print(myl)





# lab

# class HouseScheme:
#     def __init__(self, rooms, area, bathroom):
#         if area < 0 or type(bathroom)!=bool:
#             raise ValueError("Invalid value")
#         self.rooms = rooms
#         self.area = area
#         self.bathroom = bathroom

# class CountryHouse(HouseScheme):
#     def __init__(self, rooms, area, bathroom, numFloors, land_area):
#         super().__init__(rooms, area, bathroom)
#         self.numFloors = numFloors
#         self.land_area = land_area
    
#     def __str__(self):
#         return f"Country House: Количество жилых комнат {self.rooms}, Жилая площадь {self.area}, Совмещенный санузел {self.bathroom}, Количество этажей {self.numFloors}, Площадь участка {self.land_area}."
    
#     def __eq__(self, another):
#         return self.area==another.area and self.land_area == another.land_area and abs(self.numFloors-another.numFloors)<=1

# class Apartment(HouseScheme):
#     def __init__(self, rooms, area, bathroom, floor, side):
#         super().__init__(rooms, area, bathroom)
#         if 1 <= floor <= 15 and side in ['N', 'S', 'W', 'E']:
#             self.floor = floor
#             self.side = side
#         else:
#             raise ValueError('Invalid value')
    
#     def __str__(self):
#         return f"Apartment: Количество жилых комнат {self.rooms}, Жилая площадь {self.area}, Совмещенный санузел {self.bathroom}, Этаж {self.floor}, Окна выходят на {self.side}."

# class CountryHouseList(list):
#     def __init__(self, name):
#         super().__init__()
#         self.name = name
    
#     def append(self, p_object):
#         if CountryHouse != type(p_object):
#             raise TypeError(f"Invalid type {type(p_object)}")
#         super().append(p_object)
    
#     def total_square(self):
#         res = 0
#         for house in self: res += house.area
#         return res

# class ApartmentList(list):
#     def __init__(self, name):
#         super().__init__()
#         self.name = name
    
#     def extend(self, iterable):
#         super().extend(list(filter(lambda item: type(item) == Apartment, iterable)))
    
#     def floor_view(self, floors, directions):
#         for side_floor in list(filter(lambda apart: floors[0] <= apart.floor <= floors[1] and apart.side in directions, self)):
#             print(f'{side_floor.side}: {side_floor.floor}')




# class earth:
#     def __init__(self, mass):
#         self.massa = mass

#     def __eq__(self, other):
#         if self.massa == other.massa:
#             return f'Yes, is equal!'
#         else:
#             return f'Nope, they arent equal'
    
#     def __str__(self):
#         return "kek"

#     def setRadio(self, radius):
#         self.radius = radius
#     def getRadius(self):
#         return self.radius


# class Moon:
#     def __init__(self, mass):
#         self.massa = mass


# myearth = earth(3500)
# myoon = Moon(3501)

# myearth.setRadio(21000)
# print(myearth.getRadius())



# # task 10
# class MyStr(str):
#     def join(self, obj):
#         for elem in obj:
#             if isinstance(elem, int) or isinstance(elem, float):
#                 elem = str(elem)
#             elif isinstance(elem, list):
#                 elem = list(map(str, elem))
#                 elem = super().join(elem)
#             elif isinstance(elem, str):
#                 elem = super().join(elem)
#             else:
#                 obj.remove(elem)
#         return super().join(obj)




class MyList(list):
    def extend(self,iterable):
        if isinstance(iterable, str):
            if iterable[0].isdigit() and  iterable[1].isdigit() and iterable[2].isdigit():
                for i in iterable:
                    super().append(i)
    def remove(self, value):
        




a = MyList()
a = ['1j23', '123seh', 5, 8, 0, 5]
print(a.index(5))
a.remove(5)

print(a)