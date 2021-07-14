# 직접 작성한 코드
def solution(n):
    answer = []
    for i in range(len(str(n)) - 1, -1, -1):
        answer.append(int(str(n)[i]))
    return answer

# 모범 코드
def solution(n):
    return [int(i) for i in str(n)][::-1] # 전체를 살펴보되 끝에서부터 본다는 의미
