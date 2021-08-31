def solution(n):
    answer = 0
    n = bin(n)[2:]
    flag = False
    for i in range(len(n)-1, -1, -1):
        if n[i] == '1':
            flag = True
        else:
            if flag == True:
                break
    if i != 0:
        num_0 = n[i+1:].count('0') + 1
        num_1 = n[i+1:].count('1') - 1
        new_n = n[:i] + '1' + '0' * num_0 + '1' * num_1
    else:
        if n.count('1') == len(n):
            new_n = '1' + '0' + '1' * (len(n) - 1)
        else:
            num_0 = n[i+1:].count('0')
            num_1 = n[i+1:].count('1')
            new_n = '1' + '0' + '0' * num_0 + '1' * num_1
    return int(new_n, 2)

print(solution(int(input())))