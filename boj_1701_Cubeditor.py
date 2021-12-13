# import sys, re
# string = sys.stdin.readline().rstrip()

# str_len = len(string)
# flag = False
# for i in range(str_len-1, -1, -1):
#     for j in range(0, str_len-i):
#         substring = string[j:j+i+1]
#         first_char = substring[0]
#         rest = substring[1:]
#         pattern = re.compile(fr'{first_char}(?={rest})')
#         res = pattern.findall(string)
#         if len(res) >= 2:
#             flag = True
#             print(len(substring))
#             break
        
#     if flag:
#         break
# else:
#     print(0)

import sys
input = sys.stdin.readline

def failure(patten):
    length = len(patten)
    table = [0] * len(patten)
    j = 0
    for i in range(1, length):
        while j > 0 and patten[i] != patten[j]:
            j = table[j - 1]
        if patten[i] == patten[j]:
            j += 1
            table[i] = j
    return max(table)

s = input().rstrip()
res = 0

for idx in range(len(s)):
    sub_str = s[idx:len(s)]
    res = max(res, failure(sub_str))

print(res)