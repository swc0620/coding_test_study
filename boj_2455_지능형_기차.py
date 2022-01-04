people = 0
res = float('-inf')
for _ in range(4):
    off, on = map(int, input().split())
    people += on
    people -= off
    res = max(res, people)
print(res)