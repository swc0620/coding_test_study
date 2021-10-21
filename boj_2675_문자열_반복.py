T = int(input())
for _ in range(T):
    R, string = input().split()
    for s in string:
        print(s * int(R), end="")
    print()