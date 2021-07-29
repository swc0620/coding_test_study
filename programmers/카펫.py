def solution(brown, yellow):
    total = brown + yellow
    for i in range(1, int(total**0.5) + 1):
        if total % i == 0:
            if (i - 2) * (total // i - 2) >= yellow:
                return [total // i, i]
