from collections import deque

def solution(progresses, speeds): 
    answer = []
    days = 0
    count = 0
    progresses = deque(progresses)
    speeds = deque(speeds)
    
    while progresses:
        if progresses[0] + (days * speeds[0]) >= 100:
            progresses.popleft()
            speeds.popleft()
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            days += 1
    answer.append(count)
    
    return answer
