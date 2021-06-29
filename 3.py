import sys
n = int(sys.stdin.readline().rstrip())
queue = []
for _ in range(n):
  method = sys.stdin.readline().split()

  if method[0] == 'push':
    queue.append(method[1])

  elif method[0] == 'pop':
    if len(queue) != 0:
      print(queue[0])
      del queue[0]
    else:
      print(-1)

  elif method[0] == 'size':
    print(len(queue))
  
  elif method[0] == 'empty':
    if len(queue) == 0:
      print(1)
    else:
      print(0)

  elif method[0] == 'front':
    if queue:
      print(queue[0])
    else:
      print(-1)

  elif method[0] == 'back':
    if queue:
      print(queue[-1])
    else:
      print(-1)