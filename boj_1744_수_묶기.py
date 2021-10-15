# 양수 양수 : 곱셈 <--
# 양수 1 : 덧셈
# 양수 0 : 덧셈
# 양수 음수 : 덧셈
# 1 1 : 덧셈
# 1 0 : 덧셈
# 1 음수 : 덧셈
# 0 0 : 덧셈
# 0 음수 : 곱셈 <--
# 음수 음수 : 곱셈 <--

N = int(input())
res = 0
pos = []
zero = []
neg = []
for _ in range(N):
    new_input = int(input())
    if new_input > 1:
        pos.append(new_input)
    elif new_input == 1:
        res += 1
    elif new_input == 0:
        zero.append(new_input)
    else:
        neg.append(new_input)
    
pos.sort(reverse=True)
neg.sort()
# 양수
if len(pos) % 2 == 0:
    for i in range(0, len(pos), 2):
        res += pos[i] * pos[i+1]
else:
    for i in range(0, len(pos) // 2 * 2, 2):
        res += pos[i] * pos[i+1]
    res += pos[-1]
# 음수
if len(neg) % 2 == 0:
    for i in range(0, len(neg), 2):
        res += neg[i] * neg[i+1]
else:
    for i in range(0, len(neg) // 2 * 2, 2):
        res += neg[i] * neg[i+1]
    if not zero:
        res += neg[-1]

print(res)