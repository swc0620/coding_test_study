def solution(arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        temp1 = []
        for j in range(len(arr2[0])):
            temp2 = 0
            for k in range(len(arr1[0])):
                temp2 += arr1[i][k] * arr2[k][j]
            temp1.append(temp2)
        answer.append(temp1)
    return answer

# arr1 = [[1, 4], [3, 2], [4, 1]]
# arr2 = 	[[3, 3], [3, 3]]
# print(solution(arr1, arr2))