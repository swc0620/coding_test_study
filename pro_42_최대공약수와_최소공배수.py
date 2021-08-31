def gcd(max_num, min_num):
    if max_num % min_num == 0:
        return min_num
    else:
        return gcd(min_num, max_num % min_num)

def lcm(max_num, min_num, gcd1):
    return (max_num * min_num) // gcd1

def solution(n, m):
    max_num = max(n, m)
    min_num = min(n, m)
    gcd1 = gcd(max_num, min_num)
    return [gcd(max_num, min_num), lcm(max_num, min_num, gcd1)]

# print(solution(int(input()), int(input())))