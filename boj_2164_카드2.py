import sys

N = int(sys.stdin.readline())

queue = [i+1 for i in range(N)]

while len(queue) > 1:
    if len(queue) % 2 == 0:
        queue = queue[1::2]
    else:
        element = [queue[-1]]
        element.extend(queue[1::2])
        queue = element

print(queue[0])