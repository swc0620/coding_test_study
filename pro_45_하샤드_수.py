def solution(x):
    sum_num = sum(map(int, list(str(x))))
    if x % sum_num == 0:
        return True
    else:
        return False

# print(solution(int(input())))