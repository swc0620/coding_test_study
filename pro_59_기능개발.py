import math

def solution(progresses, speeds):
    answer = []
    periods = []
    
    for pair in zip(progresses, speeds):
        periods.append(math.ceil((100-pair[0]) / pair[1]))

    while periods:
        print(periods)
        temp = periods[0]
        for idx in range(len(periods)):
            periods[idx] -= temp
            if periods[idx] < 0:
                periods[idx] = 0
        print(periods)
        count = 0
        while periods and periods[0] == 0:
            periods.pop(0)
            count += 1
        answer.append(count)
    return answer

# progresses = list(map(int, input().split()))
# speeds = list(map(int, input().split()))
# print(solution(progresses, speeds))