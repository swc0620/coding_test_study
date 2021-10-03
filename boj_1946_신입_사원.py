T = int(input())

for _ in range(T):
    N = int(input())
    ranks = []
    for _ in range(N):
        resume, interview = list(map(int, input().split()))
        ranks.append((resume, interview))
    ranks.sort(key=lambda rank: rank[0])

    now = ranks[0][1]
    count = N
    for rank in ranks:
        if rank[1] <= now:
            now = rank[1]
        else:
            count -= 1
    print(count)