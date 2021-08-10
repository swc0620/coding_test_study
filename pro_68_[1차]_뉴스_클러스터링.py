from collections import Counter

def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()
    str1_comb = []
    str2_comb = []
    zerotonine = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    for i in range(len(str1)-1):
        temp = str1[i:i+2]
        if temp[0] < 'a' or temp[0] > 'z' or temp[1] < 'a' or temp[1] > 'z':
            pass
        else:
            str1_comb.append(temp)
    for i in range(len(str2)-1):
        temp = str2[i:i+2]
        if temp[0] < 'a' or temp[0] > 'z' or temp[1] < 'a' or temp[1] > 'z':
            pass
        else:
            str2_comb.append(temp)

    if not str1_comb and not str2_comb:
        return 65536   

    str1_cnt = Counter(str1_comb)
    str2_cnt = Counter(str2_comb)
    intersection = []
    union = str1_comb + str2_comb

    for key in str1_cnt.keys():
        if key in str2_cnt.keys():
            min_cnt = min(str1_cnt[key], str2_cnt[key])
            for _ in range(min_cnt):
                union.remove(key)
            for _ in range(min_cnt):
                intersection.append(key)

    answer = int(len(intersection) / len(union) * 65536)
    return answer

print(solution(input(), input()))