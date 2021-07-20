import math
def solution(w,h):
    gcd = math.gcd(w, h) # 최대공약수
    # 한 블록 크기: w//g x h//g <- 이런 블록이 gcd만큼 존재
    answer = w * h - (w + h - gcd)
    return answer
