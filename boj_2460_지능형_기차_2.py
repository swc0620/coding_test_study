people = 0
max_people = float('-inf')
for _ in range(10):
    _out, _in = map(int, input().split())
    people += _in - _out
    max_people = max(people, max_people)

print(max_people)