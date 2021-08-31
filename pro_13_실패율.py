from collections import Counter

def solution(N, stages):
    answer = []
    counter = Counter(stages)
    reached = 0
    failure_rate = {}
    for i in range(N+1, 0, -1):
        trying = 0
        
        if i == N+1:
            if i in counter.keys():
                reached += counter[i]
            continue
        else:
            if i in counter.keys():
                reached += counter[i]
                trying += counter[i]
        
        if reached != 0:
            rate = trying / reached
        else:
            rate = 0

        if rate in failure_rate.keys():
            failure_rate[rate].append(i)
            failure_rate[rate].sort()
        else:
            failure_rate[rate] = [i]
        # print(i, trying, reached)

    # print(failure_rate)

    failure_rate = Counter(failure_rate)
    failure_rate = sorted(failure_rate.items(), reverse=True)

    for i, key in enumerate(failure_rate):
        answer += key[1]

    return answer

# N = int(input())
# stages = list(map(int, input().split(",")))
# print(solution(N, stages))