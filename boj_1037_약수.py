N = int(input())

divisors = list(map(int, input().split()))
divisors.sort()
if len(divisors) % 2 == 1:
    print(divisors[len(divisors) // 2] ** 2)
else:
    print(divisors[-1] * divisors[0])