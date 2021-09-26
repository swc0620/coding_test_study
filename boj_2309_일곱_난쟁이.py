from itertools import combinations

dwarfs = []
for _ in range(9):
    dwarfs.append(int(input()))

combis = list(combinations(dwarfs, 7))
for i, combi in enumerate(combis):
    if sum(combi) == 100:
        res = sorted(list(combi))
        print(*res, sep='\n')
        break
