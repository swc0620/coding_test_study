def solution(arr):
    answer = []
    for i, num in enumerate(arr):
        if answer and answer[-1] == num:
            pass
        else:
            answer.append(num)
    return answer