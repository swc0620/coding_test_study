answer = 0
# DFS 이용
def dfs(idx, result, numbers, target):
    global answer
    if idx == len(numbers): # numbers 원소를 모두 계산했을 경우
        if result == target:
            answer += 1
        return
    else:
        dfs(idx + 1, result + numbers[idx], numbers, target) # 재귀구조
        dfs(idx + 1, result - numbers[idx], numbers, target)

def solution(numbers, target):
    global answer # 전역 변수 사용
    dfs(0, 0, numbers, target) # result = 0으로 초기화
    
    return answer
