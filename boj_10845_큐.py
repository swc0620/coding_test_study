import sys
N = int(input())

queue = []
while N > 0:
    command = sys.stdin.readline().split()
    if command[0] == "push":
        X = command[1]
        queue.append(X)
    elif command[0] == "pop":
        if len(queue) > 0:
            print(queue[0])
            queue = queue[1:]
        else:
            print(-1)
    elif command[0] == "size":
        print(len(queue))
    elif command[0] == "empty":
        if len(queue) > 0:
            print(0)
        else:
            print(1)
    elif command[0] == "front":
        if len(queue) > 0:
            print(queue[0])
        else:
            print(-1)
    else:
        if len(queue) > 0:
            print(queue[-1])
        else:
            print(-1)
    N -= 1