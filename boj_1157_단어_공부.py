from collections import Counter

string = input().lower()
counter = Counter(string)
res = counter.most_common()
if len(res) == 1:
    print(res[0][0].upper())
else:
    if res[0][1] == res[1][1]:
        print('?')
    else:
        print(res[0][0].upper())