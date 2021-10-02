N = int(input())

times = []

for _ in range(N):
    times.append(tuple(map(int, input().split())))

times.sort(key=lambda time: (time[1], time[0]))

count = 1
now = times[0][1]

for i in range(1, len(times)):
    if times[i][0] >= now:
        now = times[i][1]
        count += 1

print(count)