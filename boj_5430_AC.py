import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    p = input().strip()
    n = int(input())
    string = input().strip()[1:-1].split(',')
    string = deque(string)

    R_cnt = 0
    flag = 0
    if n == 0:
        string = deque()

    for cmd in p:
        if cmd == 'R':
            R_cnt += 1
        elif cmd == 'D':
            if len(string) < 1:
                flag = 1
                print("error")
                break
            else:
                if R_cnt % 2 == 0:
                    string.popleft()
                else:
                    string.pop()
    if flag == 0:
        if R_cnt % 2 == 0:
            print('['+",".join(string)+']')
        else:
            string.reverse()
            print('['+",".join(string)+']')