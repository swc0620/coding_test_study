one = int(input())
days = list(map(int, input().split()))
cnt = 0
for day in days:
    if one == day:
        cnt += 1
print(cnt)