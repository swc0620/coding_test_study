res = ""
mbti = input()

if mbti[0] == 'E':
    res += 'I'
else:
    res += 'E'

if mbti[1] == 'S':
    res += 'N'
else:
    res += 'S'

if mbti[2] == 'T':
    res += 'F'
else:
    res += 'T'

if mbti[3] == 'J':
    res += 'P'
else:
    res += 'J'
print(res)