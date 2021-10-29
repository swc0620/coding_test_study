T = int(input())
for _ in range(T):
    H, W, N = map(int, input().split())
    q, r = divmod(N, H)
    print(q, r)
    if r == 0:
        r = H
        q -= 1
    if q+1 >= 10:
        print(str(r)+str(q+1))
    else:
        print(str(r)+'0'+str(q+1))