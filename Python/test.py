#2
# try:
#     lis = list(map(int, input().split(',')))
#     for num in lis:
#         if num < 0:
#             lis.remove(num)
#     print(list(map(str, lis)))
# except ValueError:
#     print(['0'])
#OK
#print([s for s in input().split(',') if s.isdigit()])
#print(list(filter(str.isdigit, input().split(','))))

# z = 0
# for i in lis:
#     z = int(lis[i])
#     lis.remove(lis[i])
#     lis[i] = z

# lis = [i for i in input().split(',')]

# for i in lis:
#     if int(i) < 0:
#         lis.remove(i)
# print(lis)









#3 OK
# _list = input().split(':')
# newList = []

# for word in _list:
#     if word[len(word)-1] == 'a':
#         newList.append(word)
#         _list.remove(word)

# print(_list, newList)









#4 OK
# _list = input().split(';')
# find = input()
# f = 0

# for word in _list:
#     if find == word:
#         print(True)
#         break
#     else:
#         f += 1
# if f == len(_list):
#     print(False)


# _list = input().split(';')
# find = input()
# i = 0
# while(i <= len(_list)-1):
#     if _list[i].find(find):
#         print(True)
# for word in _list:
#     if word.find(find):
#         print(True)









#5 OK
# l1 = input().split(';')
# #ln = [ln.append(x.split(':')) for x in l1]

# ln = []
# for x in l1:
#     ln.append(x.split(':'))

# for x in ln:
#     p = x[1][len(x[1])-1]
#     if p == '1' or p == '3' or p == '9':
#         print("Bad suffix")
#         continue
#     if x[1][0] == '0':
#         print("Bad prefix")
#         break
#     if int(x[1][0]) % 2 == 0 or int(x[1][0]) == 5 or int(x[1][0]) == 7:
#         print(x[0])







#6 OK
# list(i for i in range(-2, 20, 3))
#print(x for x in '-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19'[::3])










#7 OK
# text = input().split('\t'); print(text)
# checking = text[0]; checkT = 0; checkF = 0
# for pre in range(1, len(text)):
#     print(text[pre], ' ')
#     if text[pre] == checking:
#         checkT += 1
#     else:
#         checkF += 1
#         print(checkF, '\n')
# if checkT > 1:
#     print(True)
# elif checkF > 0:
#     print(False)

# check = text[0]
# pre = 1; checkF = 0; checkT = False
# for pre in text:
#     if pre == check:
#         checkT = True
#         break
#     else:
#         checkF += 1
# if checkT:
#     print(True)
# elif checkF > 0:
#     print(False)
#jnejdnejnjwndjn.njewndwnjdwnjedwnj     ejndwiendun3udnndc.dejndnenfcnjjsdnc    jnejdnejnjwndjn.njewndwnjdwnjedwnj










#8  OK
# text = input()
# splitText = text.split('\t')
# res = 0

# for pre in splitText:
#     if text.count(pre) > res:
#         res = text.count(pre)

# print(res)









#9
# listElements = input().split()
# #print(listElements)

# for i in range(0, len(listElements)):
#     print(i, listElements[i])

# i = 0
# a = input()
# while a:
#     print(i,' ', a)
#     i += 1
#     a = input()

# li = []
# a = input()
# while a:
#     li.append(a)
#     a = input()

# for i in range(0, len(li)):
#     print(i, li[i])

# text = input()
# i = 0

# while text:
#     if text:
#         print(i,' ', text)
#     text = input()
#     i += 1









#10 OK
# text = input()
# i = 0
# li = []

# while text:
#     if text == '.':
#         li.append(text)
#         break
#     li.append(text)
#     text = input()

# for i in li:
#     print(i, end='')










#11 OK
# text = input().split(',')
# print(text)
# for i in range(0, len(text)):
#     text[i] = text[i].rstrip(' ')

# print(text)










#12 OK
# nums = input().split()
# res = 0
# for i in nums:
#     res += int(i)
# print(res)










#13 OK
# nums = input().split()
# resLi = []

# for i in nums:
#     resLi.append(str(int(i)*int(i)))

# print(' '.join(resLi))










# SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY___SLOVARY

#1 OK
# l1 = (x for x in input().split('\n') if input() !='\n')

#d = {key: value for key, l1.count(key) in l1}
#print(d)

# d1 = set(l1)
# for x in d1:
#     print(x)

#print(dict(x=l1.count(x) for x in l1))

#(1)
# d = {}
# for i in range(10):
#     word = input()
#     d[word] = d.get(word, 0) + 1
# print(d)

#(2)
# l1 = []

# for i in range(10):
#     l1.append(input())

# d = {}

# for x in l1:
#     d[x] = l1.count(x)
# print(d)









#2 OK 
# l1 = []

# for i in range(10):
#     l1.append(input().lower())

# d = {}

# for x in l1:
#     d[x] = l1.count(x)
# print(d)









#3 OK +- RECHECK 
# import math

# func = dict.fromkeys(['factorial', 'sqr', 'sqrt'])
# nums = input().split()

# factorial = list(math.factorial(int(num)) for num in nums)
# sqr = list(int(num)**2 for num in nums)
# sqrt = list(math.sqrt(int(num)) for num in nums)

# func['factorial'] = factorial
# func['sqr'] = sqr
# func['sqrt'] = sqrt

# print(func)









#4 OK SUPER
# wordDict = {}

# words = input().split()
# while words[0] != 'ugabuga':
#     wordDict.update({words[0]: words[1]})
#     words = input().split()

# stringUnknownLang = input().lower().split(' ')

# for word in stringUnknownLang:
#     if word in wordDict:
#         print(wordDict.get(word), end=' ')
#     else:
#         print('<unknown>', end=' ')









#FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS-----FUNCTIONS

#1 OK
# import math

# def Space(radiuses):
#     space = []
#     for rad in radiuses:
#         if float(rad) > 0:
#             space.append(round(math.pi * (float(rad)**2), 10))
#     return space

# radiuses = input().split()

# l = Space(radiuses)

# for num in l:
#     print(num, end=' ')









#2 OK
# import math, cmath

# nums = input().split(' ')

# def korniKvadratnogo(nums):
#     diskr = float(nums[1])**2 -4*float(nums[0])*float(nums[2])
#     if diskr >= 0:
#         x1 = (-float(nums[1]) - math.sqrt(diskr)) / (2* float(nums[0]))
#         x2 = (-float(nums[1]) + math.sqrt(diskr)) / (2* float(nums[0]))
#         #return print(x1), print(x2)
#         print(x1, x2)
#     else:
#         x1 = (-float(nums[1]) - cmath.sqrt(diskr)) / (2* float(nums[0]))
#         x2 = (-float(nums[1]) + cmath.sqrt(diskr)) / (2* float(nums[0]))
#         #return print(x1), print(x2)
#         print(x1, x2)

# korniKvadratnogo(nums)









#3 OK
# from copy import deepcopy

# source = [1, 2, ['a', 'b', ['c', 'd', 21]], 3]

# first_copy = source.copy()
# second_copy = deepcopy(source)
# print(first_copy, second_copy)

# first_copy[2][2] = 0
# second_copy[2][2] = 'qwerty'

# print(first_copy, second_copy)


# print(source == first_copy, source == second_copy)









#5 DONE
# def solve(str_obj):
#     #return print("{0}, {1}, {2}!".format(str_obj[2], str_obj[1], str_obj[0]))
#     #print(str_obj[2], str_obj[1], str_obj[0], sep=', ', end='!\n')
#     #str_obj.reverse()
#     #return print(', '.join(str_obj), end='!\n')
#     #print(str_obj[0], str_obj[1], str_obj[2], sep=', ', end='!\n')
#     #print(', '.join(str_obj[::-1]), end='!')
#     s = ', '.join(str_obj[::-1])
#     print(s+'!')

# solve(input().split())


#6 DONE
# def solve(str_obj, i = 2):
#     str = ''
#     if int(i) <= 0:
#         return(str_obj)
#     else:
#         str_obj = str_obj * i
#         str = str_obj[::-int(i)]
#     return(str)









#WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA_______WIKIPEDIA
#1 OK
# import wikipedia
# # try:
# #     print(wikipedia.page('New York: film'))
# # except wikipedia.exceptions.DisambiguationError as e:
# #     print (e.options)


# langs = input().split(',')
# #last = langs[len(langs)-1]
# new = []

# for lang in langs:
#     if (lang not in wikipedia.languages()):
#         new.append(lang)

# print(','.join(new))









#2 OK
# import wikipedia

# titles = input().split(',')

# links1 = wikipedia.page(titles[0]).links
# #links2 = wikipedia.page(titles[1]).links
# # print(wikipedia.page(titles[0]))
# # print(links1)
# #tit2 = wikipedia.page(titles[1])

# mergeList = []
# for link in links1:
# 	if titles[1] in link:
# 		mergeList.append(link)
# #print(mergeList if len(mergeList) > 0 else 'no results')

# if len(mergeList) > 0:
# 	print(','.join(mergeList))
# else:
# 	print('no results')









#3 OK DONE

# import wikipedia

# p = input()
# page = wikipedia.page(p)
# pageTitle = page.title
# lenPageSummary = len(page.summary)
# lenLinks = len(page.links)

# dic = {}
# li = []
# li.append(pageTitle)
# li.append(lenPageSummary)
# li.append(lenLinks)

# dic[pageTitle] = li
# # li.append(wikipedia.page(p).title)
# # li.append(len(wikipedia.page(p).summary.split()))
# # li.append(len(wikipedia.page(p).links))

# #print({p.title:[p.title,len(p.summary.split()), len(p.links)]})

# #dic = dict.fromkeys([wikipedia.page(p).title], li)

# print(dic)
# #print({ wikipedia.page(p).title : [ wikipedia.page(p).title, len(wikipedia.page(p).summary), len(wikipedia.page(p).links) ]})








#--------_________--------________--------___----____-----_____-------_____________-------____________----------
#-----------------------------_________________________________----------____________---------________-
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
#LAB1 DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# Для вашего удобства мы создали функцию is_page_valid(page_name), которая возвращает True,
# если wiki-страница с таким названием существует и False в ином случае.

# #sys.exit(0)
# import wikipedia
# import sys

# def is_page_valid(page):
#     try:
#         wikipedia.page(page)
#     except Exception:
#         return False
#     return True


# def checkLang(list):
#     if list[len(list)-1] not in wikipedia.languages():
#         print('no results')
#         sys.exit(0)
#     else:
#         wikipedia.set_lang(list[len(list)-1])

# def maxWord(list):
#     Max = 0
#     _word = ''
#     for word in list:
#         lenLink = len(wikipedia.page(word).summary.split())
#         if lenLink >= Max:
#             Max = lenLink
#             _word = wikipedia.page(word).title
#     print(Max, _word)

# def Prom(list):
#     result = []
#     result.append(list[0])
#     if len(list) > 1:
#         for i in range(0, len(list)-1):
#             _links = wikipedia.page(list[i]).links
#             #print('Begin list[', i, '] ==', list[i])
#             if list[i+1] in _links:
#                 result.append(list[i+1])
#                 #print(list[i+1],'was appended successfully\n')
#             else:
#                 #print('LINK HAVENT ', list[i+1], '\n')
#                 for link in _links:
#                     if is_page_valid(link):
#                         #print(link, 'is VALID\n')
#                         _link2 = wikipedia.page(link).links
#                         if list[i+1] in _link2:
#                             result.append(link)
#                             result.append(list[i+1])
#                             #print(list[i+1], 'WAS successfully APPENDED IN SECOND CICLE')
#                             break
#     #result.append(list[len(list)-1])
#     print(result)


# #-----------------------------------------------------------------------------
# pages_and_lang = input().split(', ')
# checkLang(pages_and_lang)
# #-----------------------------------------------------------------------------
# pages = []
# lang = [pages_and_lang[len(pages_and_lang)-1]]

# for i in range(len(pages_and_lang)-1):
#     pages.append(pages_and_lang[i])

# pages_and_lang.clear()

# #------------------------------------------------------------------------------
# maxWord(pages)
# #------------------------------------------------------------------------------

# Prom(pages)
#---------------------------------------------------------------------------------
#----------------------------------------------------------------------------------
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
#1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

# def Prom(list):
#     res = []
#     for i in range(0, len(list)-1):
#         res.append(list[i])
#         #print("nach", list[i])
#         for link in wikipedia.page(list[i]).links:
#             if is_page_valid(link):
#                 #print(link, 'is Valid')
#                 if list[i+1] in wikipedia.page(link).links:
#                     res.append(link)
#                     #print(link, 'was appended successfully')
#                     break
#         # for _link in wikipedia.page(link).links:
#         #     if is_page_valid(_link):
#         #         print(_link, 'is page valid')
#         #         if _link == list[1]:
#         #             res.append(_link)
#         #             break
#     res.append(list[len(list)-1])
#     print(res)






#TESTS
# a = [0, 23, 2, 12, 8, 43, 23, 2, 43, 32]
# new = []

# for i in range(0, len(a)):
#     # try:
#     #     a.remove(a[i])
#     #     print(a[i], 'was removed!')
#     # except ValueError:
#     #     print("Failed to remove item")
#     #     continue
#     #print(a.pop(i), 'was removed!')
#     if a[i] % 2 == 0:
#         new.append(a[i])
#         a.remove(a[i]) #not work

# print(new)
# print(a)
# print(a.extend(new))