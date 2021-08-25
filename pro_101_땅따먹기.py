def solution(land):
    for i in range(1, len(land)):
        for j in range(len(land[i])):
            temp = land[i-1][:]
            temp.pop(j)
            land[i][j] += max(temp)
    return max(land[-1])

# lands = []
# for _ in range(3):
#     lands.append(list(map(int, input().split())))
# print(solution(lands))