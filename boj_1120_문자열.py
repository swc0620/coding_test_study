a, b = input().split()
val = float('inf')
for i in range(len(b)):
    if i + len(a) > len(b):
        break
    cut =b[i:i+len(a)]
    cnt = 0
    for k in range(len(a)):
        if cut[k] != a[k]:
            cnt += 1
    val = min(val, cnt)

print(val)