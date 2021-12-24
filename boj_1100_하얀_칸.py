cnt = 0
for idx in range(8):
    row = input()
    if idx % 2 == 0:
        if row[0] == 'F':
           cnt += 1
        if row[2] == 'F':
            cnt += 1
        if row[4] == 'F':
            cnt += 1
        if row[6] == 'F':
            cnt += 1 
    else:
        if row[1] == 'F':
           cnt += 1
        if row[3] == 'F':
            cnt += 1
        if row[5] == 'F':
            cnt += 1
        if row[7] == 'F':
            cnt += 1 
print(cnt)