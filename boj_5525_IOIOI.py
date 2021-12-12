import re

N = int(input())
M = int(input())
S = input()

pattern = re.compile(r'I(?:OI)+')

res = 0
for match in pattern.finditer(S):
    match = match.group()
    c = len(match) // 2 - N + 1
    if c > 0:
	    res += c
print(res)