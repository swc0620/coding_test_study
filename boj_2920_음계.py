scale = list(map(int, input().split()))

asc = False
desc = False

for i in range(len(scale) - 1):
    if scale[i] < scale[i+1]:
        asc = True
    elif scale[i] > scale[i+1]:
        desc = True

if asc and desc:
    print("mixed")
elif asc:
    print("ascending")
else:
    print("descending")