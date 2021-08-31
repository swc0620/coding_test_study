def split_quad(arr):
    n = len(arr)
    sq1 = []
    for i in range(n // 2):
        sq1.append(arr[i][:n//2])

    sq2 = []
    for i in range(n // 2):
        sq2.append(arr[i][n//2:])

    sq3 = []
    for i in range(n // 2, n):
        sq3.append(arr[i][:n//2])

    sq4 = []
    for i in range(n // 2, n):
        sq4.append(arr[i][n//2:])

    return [sq1, sq2, sq3, sq4]

def solution(arr):
    if len(set(sum(arr, []))) == 1:
        if arr[0][0] == 0:
            return [1, 0]
        else:
            return [0, 1]
    sqs = split_quad(arr)

    res = []
    for sq in sqs:
        res.append(solution(sq))
    
    return [sum([i[0] for i in res]), sum([i[1] for i in res])]

# arr = []
# for _ in range(4):
#     arr.append(list(map(int, input().split())))
# print(solution(arr))