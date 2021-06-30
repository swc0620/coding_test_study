import sys
n = int(sys.stdin.readline())

temp = True
stack = []
answer = []
count = 1

for i in range(n):
    num = int(input())
    while count <= num: # 입력된 수열보다 작은 경우 같아질 때까지 반복
        stack.append(count)
        answer.append('+')
        count += 1
    if stack[-1] == num: # 입력된 수열과 동일한 경우
        stack.pop()
        answer.append('-')
    else: # 특정 수열을 만들 수 없을 경우
        temp = False
        
if not temp:
    print('NO')
else:
    for i in answer:
        print(i)