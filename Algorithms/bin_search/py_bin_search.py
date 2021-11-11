
# def solve(L, x):
    
#     low = 0; high = len(L) - 1

#     while low <= high:
#         mid = int((low+high)/2)
#         guess = L[mid]

#         if abs(guess - x) < 0.00001:
#             return mid
#         elif guess > x:
#             high = mid+1
#         else:
#             low = mid+1
#     return -1


# arr = [1.2, 2.2, 3.1, 4.2]
# print(solve(arr, 1.2))

# # def solve(L, x):
# #     for i in range(len(L)):
# #         if abs(L[i] - x) < 0.00001:
# #             return i
# #     return -1
import random
import time
import matplotlib.pyplot as plt
from matplotlib import transforms

"""
Просто запустить - ничего вводить не надо - генерится 100 тестов
(в строке 108 можно поменять кол-во тестов - например 50)
Графичек надеюсь понравится :)
"""


def insert_sort(arr, start, end):
    for i in range(start + 1, end + 1):
        elem = arr[i]
        j = i - 1
        while j >= start and elem < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = elem
    return arr


def mergeTim(arr, start, mid, end):
    if mid == end:
        return arr
    first = arr[start:mid + 1]
    last = arr[mid + 1:end + 1]
    len1 = mid - start + 1
    len2 = end - mid
    ind1 = 0
    ind2 = 0
    ind = start

    while ind1 < len1 and ind2 < len2:
        if first[ind1] < last[ind2]:
            arr[ind] = first[ind1]
            ind1 += 1
        else:
            arr[ind] = last[ind2]
            ind2 += 1
        ind += 1

    while ind1 < len1:
        arr[ind] = first[ind1]
        ind1 += 1
        ind += 1

    while ind2 < len2:
        arr[ind] = last[ind2]
        ind2 += 1
        ind += 1
    return arr


def merge(arr):
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    left, right = arr[:mid], arr[mid:]
    merge(left)
    merge(right)
    index_left = index_right = index = 0
    result = [0] * (len(left) + len(right))
    while index_left < len(left) and index_right < len(right):
        if left[index_left] <= right[index_right]:
            result[index] = left[index_left]
            index_left += 1
        else:
            result[index] = right[index_right]
            index_right += 1
        index += 1
    while index_left < len(left):
        result[index] = left[index_left]
        index_left += 1
        index += 1
    while index_right < len(right):
        result[index] = right[index_right]
        index_right += 1
        index += 1
    for i in range(len(arr)):
        arr[i] = result[i]

    return arr


def TimSort(arr):
    n = len(arr)
    minrun = 32
    for start in range(0, n, minrun):
        end = min(start + minrun - 1, n - 1)
        arr = insert_sort(arr, start, end)

    curr_size = minrun
    while curr_size < n:
        for start in range(0, n, curr_size * 2):
            mid = min(n - 1, start + curr_size - 1)
            end = min(n - 1, mid + curr_size)
            arr = mergeTim(arr, start, mid, end)
        curr_size *= 2
    return arr


def main():
    n = 100
    tests = []
    array = []
    timeMerge = []
    timeTim = []
    for i in range(100):
        for j in range(int(n)):
            rand = random.randint(1, 1000)
            array.append(rand)
        tests.append(n)
        arr_1 = array
        arr_2 = array

        start_time = time.time()
        arr_1 = merge(arr_1)
        res_time = time.time() - start_time
        timeMerge.append(res_time)
        print("\033[37m --- work time ---\033[0m {} - {}".format(res_time, n))

        start_time = time.time()
        arr_2 = TimSort(arr_2)
        res_time = time.time() - start_time
        timeTim.append(res_time)
        print("--- work time --- {} - {}".format(res_time, n))
        n += 5

    fig, ax = plt.subplots(dpi=150)
    ax.set_facecolor('#800080')
    fig.set_facecolor('#800080')
    csfont = {'fontname': 'Segoe UI'}
    plt.plot(tests, timeMerge, color='#00BFFF')
    plt.plot(tests, timeTim, color='#32CD32')
    ax.set_xlabel('Кол-во элементов сортируемого массива', **csfont, color='#FFD700', fontsize=9)
    ax.set_ylabel('Время работы алгоритма (с)', **csfont, color='#FFD700', fontsize=9)
    ax.spines['bottom'].set_color('#FFD700')
    ax.spines['top'].set_color('#FFD700')
    ax.spines['left'].set_color('#FFD700')
    ax.spines['right'].set_color('#FFD700')
    ax.tick_params(axis='x', colors='#FFD700')
    ax.tick_params(axis='y', colors='#FFD700')
    # remove spines
    ax.spines['right'].set_visible(False)
    ax.spines['top'].set_visible(False)
    # grid
    ax.set_axisbelow(True)
    ax.yaxis.grid(color='#F0E68C', linestyle='dashed', alpha=0.3)
    ax.xaxis.grid(color='#F0E68C', linestyle='dashed', alpha=0.3)

    t = plt.gca().transData
    fig = plt.gcf()
    ls = ['Сравнение скоростей', 'сортировки слиянием', 'и', 'тимсорта']
    lc = ['#FFD700', '#00BFFF', '#FFD700', '#32CD32']
    x = 100
    y = round(max(timeMerge), 3) * 1.15
    for s, c in zip(ls, lc):
        text = plt.text(x, y, s + " ", color=c, transform=t, size=13, **csfont)
        text.draw(fig.canvas.get_renderer())
        ex = text.get_window_extent()
        t = transforms.offset_copy(text._transform, x=ex.width, units='dots')

    sps = 'TimSort by Nikita Efimov'
    plt.text(30 * (530 / n), -0.185 * round(max(timeMerge), 2), sps, ha='left', fontsize=8, alpha=0.9, **csfont,
             color='#C0C0C0', fontstyle='italic')

    plt.show()


if __name__ == "__main__":
    main()