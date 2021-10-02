def partition(waiting, low, high):
    i = low - 1
    pivot = waiting[high]
    for j in range(low, high):
        if waiting[j] <= pivot:
            i += 1
            waiting[i], waiting[j] = waiting[j], waiting[i]

    waiting[i+1], waiting[high] = waiting[high], waiting[i+1]
    return i+1

def quick_sort(waiting, low, high):
    if len(waiting) == 1:
        return waiting
    if low < high:
        pivot = partition(waiting, low, high)
        quick_sort(waiting, low, pivot-1)
        quick_sort(waiting, pivot+1, high)

N = int(input())
waiting = list(map(int, input().split()))
quick_sort(waiting, 0, N-1)

res = waiting[0]
for i in range(N-1):
    waiting[i+1] += waiting[i]
    res += waiting[i+1]

print(res)