def solution(n, arr1, arr2):
    map1 = [bin(i)[2:].rjust(n, "0") for i in arr1]
    map2 = [bin(i)[2:].rjust(n, "0") for i in arr2]
    answer = []
    for i in range(n):
        row = ''
        for j in range(n):
            if map1[i][j] == '0' and map2[i][j] == '0':
                row += ' '
            else:
                row += '#'
        answer.append(row)
    return answer

# n = int(input())
# arr1 = list(map(int, input().split(",")))
# arr2 = list(map(int, input().split(",")))
# print(solution(n, arr1, arr2))