import sys
casenum = int(input())

while casenum > 0:
    N, M = list(map(int, sys.stdin.readline()[:-1].split()))
    queue = list(map(int, sys.stdin.readline()[:-1].split()))
    
    count = 0
    while M > -1:
        if queue[0] < max(queue):
            queue.append(queue[0])
            queue = queue[1:]
            if M > 0:
                M -= 1
            else:
                M += len(queue) - 1
        else:
            count += 1
            queue = queue[1:]
            M -= 1
        
    print(count)
    casenum -=1