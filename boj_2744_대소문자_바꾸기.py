string = input()

res = ''
for c in string:
    if 'A' <= c <= 'Z':
        res += c.lower()
    else:
        res += c.upper()
print(res)