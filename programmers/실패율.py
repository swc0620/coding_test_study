def solution(N, stages):
    answer = {}
    remain = len(stages)
    for i in range(1, N + 1):
        if remain != 0:
            count = stages.count(i)
            answer[i] = count / remain
            remain -= count
        else:
            answer[i] = 0
    return sorted(answer, key=lambda x: answer[x], reverse=True)
