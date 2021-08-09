def solution(n):
    answer = []
    pyramid = [[0] * i for i in range(1, n+1)]
    row = -1
    col = 0
    num = 1

    for i in range(n):
        for _ in range(i, n):

            if i % 3 == 0:
                row += 1
            elif i % 3 == 1:
                col += 1
            elif i % 3 == 2:
                row -= 1
                col -= 1
            
            pyramid[row][col] = num
            num += 1
    
    for i in pyramid:
        for j in i:
            if j != 0:
                answer.append(j)

    return answer

# print(solution(int(input())))