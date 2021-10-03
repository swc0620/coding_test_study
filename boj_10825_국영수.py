N = int(input())
scores = []
for _ in range(N):
    name, kor, eng, math = input().split()
    scores.append((name, int(kor), int(eng), int(math)))

scores.sort(key=lambda score: (-score[1], score[2], -score[3], score[0]))

for s in scores:
    print(s[0])