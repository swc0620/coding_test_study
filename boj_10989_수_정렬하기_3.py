import sys

N = int(sys.stdin.readline())

num_book = [0] * 10001

for _ in range(N):
    num = int(sys.stdin.readline())
    num_book[num] += 1

for i in range(10001):
    if num_book[i] != 0:
        for _ in range(num_book[i]):
            print(i)