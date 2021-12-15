import sys, re
input = sys.stdin.readline

S = input().rstrip()
P = input().rstrip()

pattern = re.compile(fr'{P}')
if pattern.findall(S):
    print(1)
else:
    print(0)