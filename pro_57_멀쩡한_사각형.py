import math

def solution(w,h):
    total = w * h
    if w == 1 or h == 1:
        return 0
    if w == h:
        return total - w
    y_prev = 0
    y_curr = 0
    for x in range(0, w+1):
        y = h * x / w
        y_curr = math.ceil(y)
        total -= (y_curr - y_prev)
        y_prev = math.floor(y)
    return total

# print(solution(int(input()), int(input())))