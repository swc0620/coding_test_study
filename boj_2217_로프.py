N = int(input())

ropes = []
for _ in range(N):
    ropes.append(int(input()))

ropes.sort(reverse=True)
for i in range(N):
    ropes[i] = ropes[i] * (i+1)
print(max(ropes))