N = int(input())

ans = 0
while N >= 0:
    q, r = divmod(N, 5)
    if r == 0:
        ans += q
        print(ans)
        break
    else:
        N -= 3
        ans += 1
else:
    print(-1)