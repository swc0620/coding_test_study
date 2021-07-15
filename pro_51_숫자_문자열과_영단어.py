import re

def solution(s):
    s = re.sub(r'zero', r'0', s)
    s = re.sub(r'one', r'1', s)
    s = re.sub(r'two', r'2', s)
    s = re.sub(r'three', r'3', s)
    s = re.sub(r'four', r'4', s)
    s = re.sub(r'five', r'5', s)
    s = re.sub(r'six', r'6', s)
    s = re.sub(r'seven', r'7', s)
    s = re.sub(r'eight', r'8', s)
    s = re.sub(r'nine', r'9', s)
    return int(s)

# print(solution(input()))