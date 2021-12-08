import sys
input = sys.stdin.readline

N = input().strip()
counter = [0]*10
for char in N:
    counter[int(char)] += 1

six_or_nine = counter[6] + counter[9]
if six_or_nine % 2 == 0:
    counter[6] = six_or_nine // 2
    counter[9] = six_or_nine // 2
else:
    counter[6] = six_or_nine // 2 + 1
    counter[9] = six_or_nine // 2 + 1

print(max(counter))