import time
import random

def insert_sort(arr, start, end):
    for i in range(start + 1, end + 1):
        tmp = arr[i]
        j = i - 1
        while j >= start and tmp < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = tmp
    return arr


def merge(arr, start, mid, end):
    if mid == end:
        return arr
    first = arr[start:mid + 1]
    last = arr[mid + 1:end + 1]
    len_first = mid - start + 1
    len_last = end - mid
    index_first = 0
    index_second = 0
    index = start

    while index_first < len_first and index_second < len_last:
        if first[index_first] < last[index_second]:
            arr[index] = first[index_first]
            index_first += 1
        else:
            arr[index] = last[index_second]
            index_second += 1
        index += 1

    while index_first < len_first:
        arr[index] = first[index_first]
        index_first += 1
        index += 1

    while index_second < len_last:
        arr[index] = last[index_second]
        index_second += 1
        index += 1
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
            arr = merge(arr, start, mid, end)
        curr_size *= 2
    return arr

def counting_sort(alist, largest):
    c = [0] * (largest + 1)
    for i in range(len(alist)):
        c[alist[i]] = c[alist[i]] + 1

    # Find the last index for each element
    c[0] = c[0] - 1  # to decrement each element for zero-based indexing
    for i in range(1, largest + 1):
        c[i] = c[i] + c[i - 1]

    result = [None] * len(alist)

    # Though it is not required here,
    # it becomes necessary to reverse the list
    # when this function needs to be a stable sort
    for x in reversed(alist):
        result[c[x]] = x
        c[x] = c[x] - 1

    return result
n = 100
array = []
for i in range(100):
    for j in range(int(n)):
        rand = random.randint(1, 1000)
        array.append(rand)
    arr_1 = array
    arr_2 = array

    start_time1 = time.time()
    time.sleep(1)
    TimSort(arr_1)
    res_time1 = time.time() - start_time1 - 1
    print("TimSort: n={} | time={}".format(n, res_time1))
    start_time2 = time.time()
    time.sleep(1)
    # arr_2.sort()
    counting_sort(arr_2)
    res_time2 = time.time() - start_time2 - 1
    print("CountingSort: n={} | time={}".format(n, res_time2))
    print(">> CountingSort speed relative to TimSort: {}".format(res_time2/res_time1))