def is_n_bigger_than_20(N):
    def hanoi_tower(n, start, end, mid, res):
        if n == 1:
            res.append((start, end))
        else:
            hanoi_tower(n-1, start, mid, end, res)
            res.append((start, end))
            hanoi_tower(n-1, mid, end, start, res)
    res = []
    if N <= 20:
        hanoi_tower(N, 1, 3, 2, res)
        print(len(res))
        for r in res:
            print(r[0], r[1])
    else:
        print(2**N-1)
    

N = int(input())
res = []
is_n_bigger_than_20(N)

