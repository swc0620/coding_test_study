def solution(arr):
    answer = []
    last = None
    for i in arr:
        if i != last:
            answer.append(i)
        last = i
    return answer
