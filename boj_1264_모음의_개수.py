import re

while True:
    line = input()
    if line == '#':
        break
    line = line.lower()
    res = re.findall(r'[aeiou]', line)
    print(len(res))