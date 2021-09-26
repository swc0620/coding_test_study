n = int(input())
memo = [0, 1]
if n == 0:
    print(0)
elif n == 1:
    print(1)
else:
    for _ in range(1, n):
        memo.append(memo[-2] + memo[-1])
    print(memo[-1])