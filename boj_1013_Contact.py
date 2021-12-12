import sys, re
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    string = input().rstrip()
    pattern = re.compile(r'(100+1+|01)+')
    if pattern.fullmatch(string):
        print('YES')
    else:
        print('NO')