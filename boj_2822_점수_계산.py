scores = []
for i in range(8):
    scores.append((int(input()), i+1))
scores.sort(key=lambda score: (-score[0]))
total = 0
res = []
for i in range(5):
    total += scores[i][0]
    res.append(scores[i][1])
print(total)
res.sort()
res = list(map(str, res))
print(" ".join(res))