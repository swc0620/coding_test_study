n, k = map(int, input().split())
table = [i for i in range(1, n + 1)] # 원으로 앉은 사람들

answer = [] # 제거된 사람들
num = 0 # 제거할 사람의 index

for t in range(n):
    num += k - 1  
    if num >= len(table): # 한 바퀴 돌 때를 대비해 나머지로 선언  
        num = num % len(table)
 
    answer.append(str(table.pop(num)))
print("<", ", ".join(answer)[:], ">", sep='')