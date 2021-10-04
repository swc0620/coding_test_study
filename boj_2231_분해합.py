N = input()

candidates = []

len_N = len(N)
for i in range(1, int('9'*len_N)):
    candidate = int(N) - i
    if candidate >= 0:
        if sum(list(map(int, list(str(candidate))))) == i:
            candidates.append(candidate)
    else:
        break
if candidates:
    print(min(candidates))
else:
    print(0)
