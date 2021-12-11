import re

string = input()
keyword = input()

pattern = re.compile(keyword)
cnt = 0
idx = -1
for match in pattern.finditer(string):
    if match.start() >= idx:
        cnt += 1
        idx = match.end()
print(cnt)