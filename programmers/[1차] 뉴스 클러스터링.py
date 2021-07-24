def solution(str1, str2):
    str1_set = []
    str2_set = []
    
    # 2 글자씩 끊기
    for i in range(len(str1) - 1):
        if str1[i:i+2].isalpha(): # 알파벳인지 확인
            str1_set.append(str1[i:i+2].lower()) # 소문자화
    for i in range(len(str2) - 1):
        if str2[i:i+2].isalpha():
            str2_set.append(str2[i:i+2].lower())
            
    union_set = set(str1_set).union(set(str2_set))
    inter_set = set(str1_set).intersection(set(str2_set))

    intersection = sum([min(str1_set.count(x), str2_set.count(x)) for x in inter_set])
    union = sum([max(str1_set.count(x), str2_set.count(x)) for x in union_set])
    
    if union == 0:
        return 65536

    answer = int((intersection / union) * 65536)
    
    return answer
