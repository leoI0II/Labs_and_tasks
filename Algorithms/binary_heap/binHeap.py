

# def siftDown(i, arr):
#     while( 2*i +1 < len(arr)):
#         left = 2*i+1
#         right = 2*i+2
#         j = left

#         if right < len(arr) and arr[right] < arr[left]:
#             j = right

#         if arr[i] < arr[j]:
#             break
#         tmp = arr[i]
#         arr[i] = arr[j]
#         arr[j] = tmp

#         i = j


def siftDown(i, arr, ll):
    maxInd = i
    leftCh = 2*i+1

    if leftCh < len(arr) and arr[leftCh] < arr[maxInd]:
        maxInd = leftCh
    
    rightCh = 2*i+2
    if (rightCh < len(arr) and arr[rightCh] < arr[maxInd]):
        maxInd = rightCh
    if i != maxInd:
        ll.append(tuple([i, maxInd]))
        tmp = arr[i]
        arr[i] = arr[maxInd]
        arr[maxInd] = tmp
        siftDown(maxInd, arr, ll)


def buildHeap(arr, list_):
    for i in range(len(arr)//2, -1, -1):
        siftDown(i, arr, list_)


n = int(input())

l = list(map(int, input().split()))
# print(l)
ll = []
buildHeap(l, ll)
# print(l)
print(len(ll))
if len(ll):
    for i in ll:
        print(*i, sep=" ")