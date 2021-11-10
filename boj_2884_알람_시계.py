H, M = map(int, input().split())

time = H * 60 + M - 45
if time < 0:
    time += 24 * 60
q, r = divmod(time, 60)
print(q, r)