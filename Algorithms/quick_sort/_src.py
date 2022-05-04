
def qsort(lst: list) -> list:
    if len(lst) < 2:
        return lst
    else:
        pivot = lst[0];
        less = [i for i in lst[1:] if i <= pivot];
        greater = [i for i in lst[1:] if i > pivot];
        return qsort(less) + [pivot] + qsort(greater);
    
print(qsort([3, 13, 90, 34, 123, 1, 1, 3, 2, 1]))