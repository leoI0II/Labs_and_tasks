# import wikipedia
# import sys

# def is_page_valid(page):
#     try:
#         wikipedia.page(page)
#     except Exception:
#         return False
#     return True

# # def yazik(x):
# #     if x in wikipedia.languages():
# #           #wikipedia.set_lang(x)
# #           return (1)
# #     else:
# #         return (0)
# def yazik(x):
#     if x[len(x)-1] not in wikipedia.languages():
#         print('no results')
#         sys.exit(0)
#     else:
#         wikipedia.set_lang(x[len(x)-1])
# # def max_count_of_word(x):
# #     max = 0
# #     title = ''
# #     for i in range(len(x)):
# #         if is_page_valid(x[i]):
# #           c = wikipedia.page(x[i]).summary.split(' ')
# #           word = len(c)
# #           if word >= max:
# #             max = word
# #             title = wikipedia.page(x[i]).title
# #     print (max, title)

# def max(x):
#     m = 0
#     title = ''
#     for i in x:
#         c = len(wikipedia.page(i).summary.split())
#         if c >= m:
#             m = c
#             title = wikipedia.page(i).title
#     print(m, title)

# def ultimative(page):
#     result = []
#     result.append(page[0])
#     for i in range(0, len(page)-1):
#         link = wikipedia.page(page[i]).links
#         if page[i+1] in link:
#             result.append(page[i+1])
#         else:
#             for elem in link:
#                 if is_page_valid(elem):
#                     link1 = wikipedia.page(elem).links
#                     if page[i+1] in link1:
#                         result.append(elem)
#                         result.append(page[i+1])
#                         break
#     print(result)

# # a = input().split(', ')
# # jgd = a[len(a)-1]
# # a.pop(len(a)-1)
# # if yazik(jgd)!=0:
# #     #max_count_of_word(a)
# #     max(a)
# #     ultimative(a)
# # else:
# #     print('no results')


# a = input().split(', ')
# yazik(a)
# lan = a[len(a)-1]
# a.pop(len(a)-1)
# max(a)

# import wikipedia

# def max(str):
#     max = 0
#     n = ''
#     for i in range(len(str) - 1):
#         x = len(wikipedia.page(str[i]).summary.split())
#         if x >= max:
#             max = x
#             n = wikipedia.page(str[i]).title
#     print(max, n)


# def is_page_valid(page):
#     try:
#         wikipedia.page(page)
#     except Exception:
#         return False
#     return True


# def find_sequence(str):
#     sequence = []
#     sequence.append(str[0])
#     for i in range(0, len(str) - 2):
#         link1 = wikipedia.page(str[i]).links
#         if str[i+1] in link1:
#             sequence.append(str[i+1])
#         else:
#             for j in link1:
#                 if is_page_valid(j):
#                     link2 = wikipedia.page(j).links
#                     if str[i+1] in link2:
#                         sequence.append(j)
#                         sequence.append(str[i+1])
#                         break
#     print(sequence)


# s = input().split(', ')
# language = s[-1]
# if not language in wikipedia.languages():
#     print('no results')
# else:
#     wikipedia.set_lang(language)
#     max(s)
#     find_sequence(s)