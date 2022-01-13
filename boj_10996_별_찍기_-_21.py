N = int(input())
for idx in range(N):
    q, r = divmod(N, 2)
    print('* '*q, end="")
    if r % 2 == 1:
        print('*')
    else:
        print()
    print(' *'*q)


