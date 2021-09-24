T = int(input())

for _ in range(T):
    n = bin(int(input()))[2:]
    res = []
    for i in range(len(n)-1, -1, -1):
        if n[i] == '1':
            res.append(str(len(n) -1 - i))
    print(" ".join(res))