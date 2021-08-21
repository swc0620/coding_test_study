hexa = "0123456789ABCDEF"

def convert_base(n, base):
    q, r = divmod(n, base)
    if q == 0:
        return hexa[r]
    else:
        return convert_base(q, base) + hexa[r]


def solution(n, t, m, p):
    answer = ''
    candidates = []

    for i in range(t * m):
        candidates += list(convert_base(i, n))

    for i in range(p-1, t*m, m):
        answer += candidates[i]

    return answer

# print(solution(int(input()), int(input()), int(input()), int(input())))