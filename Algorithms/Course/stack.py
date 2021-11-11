# class Stack:
#     def __init__(data):
#         self.string = data;
#         self.l = []
#
#     def res(self):





def check_sen(s):
    stack = []
    s1 = ['{', '(', '[']
    s2 = ['}', ')', ']']
    t = ['()', '[]', '{}']
    for i in range(len(s)):
        if s[i] in s1:
            stack.append(i)
        elif s[i] in s2:
            if len(stack) > 0:
                top = stack.pop()
                if s[top] + s[i] not in t:
                    return i+1
            else:
                return i+1

    return 'Success' if len(stack) == 0 else stack[0]+1


print(check_sen(input()))








# def task(s):
#     s1 = '([{'
#     s2 = ')}]'
#     al = 'qwertyuiopasdfghjklzxcvbnm'

#     l = []
#     indexes = []
#     k = 0
#     k_i = 0
#     for i in range(len(s)):
#         if s[i] in s1:
#             l.append(s[i])
#             k += 1
#             indexes.append(i)
#             k_i += 1
#         elif s[i] in s2:
#             # if k == 0:
#             #     print('1')
#             #     break
#             if l[k-1] == '{' and s[i] == '}':
#                 l.pop()
#                 indexes.pop()
#                 k_i -= 1
#                 k -= 1
#             elif l[k-1] == '(' and s[i] == ')':
#                 l.pop()
#                 indexes.pop()
#                 k_i -= 1
#                 k -= 1
#             elif l[k-1] == '[' and s[i] == ']':
#                 l.pop()
#                 indexes.pop()
#                 k_i -= 1
#                 k -= 1
#             else:
#                 return i
#         # elif s[i] in al:
#         #     if l[k-1] == s[i]:
#         #         l.pop()
#         #         indexes.pop()
#         #         k_i -= 1
#         #         k -= 1

#     if k == 0:
#         return 'Success'
#     else:
#         return indexes[k_i-1]

# s = input()
# print(task(s))

# s1 = '([{'
# s2 = ')}]'
# al = 'qwertyuiopasdfghjklzxcvbnm'

# l = []
# indexes = []
# k = 0
# k_i = 0
# for i in range(len(s)):
#     if s[i] in s1:
#         l.append(s[i])
#         k += 1
#         indexes.append(i)
#         k_i += 1
#     elif s[i] in s2:
#         # if k == 0:
#         #     print('1')
#         #     break
#         if k == 0 and s[i] == '}' or k == 0 and s[i] == ')' or k == 0 and s[i] == ']':
#             print('1')
#             break
#         if l[k-1] == '{' and s[i] == '}':
#             l.pop()
#             indexes.pop()
#             k_i -= 1
#             k -= 1
#         elif l[k-1] == '(' and s[i] == ')':
#             l.pop()
#             indexes.pop()
#             k_i -= 1
#             k -= 1
#         elif l[k-1] == '[' and s[i] == ']':
#             l.pop()
#             indexes.pop()
#             k_i -= 1
#             k -= 1

# if k == 0:
#     print("Success")
# else:
#     print("HEY " + str(indexes[k_i-1]+1))
