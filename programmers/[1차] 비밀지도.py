def solution(n, arr1, arr2):
    answer = []
    map1 = []
    map2 = []
    
    map1 = convert(n, arr1, map1)
    map2 = convert(n, arr2, map2)
    
    for i in range(n):
        result = ''
        for j in range(n):
            if map1[i][j] == '1' or map2[i][j] == '1':
                result += '#'
            else:
                result += ' '
        answer += [result]
    return answer

# 이진수로 변환하는 함수
def convert(n, arr, map):
    temp = []
    for i in arr:
        result = ''
        while i > 0:
            k = i % 2 # 나머지
            i = i // 2
            result = str(k) + result
        if len(result) != n: # n자리수 맞춰주기
            result = ('0' * (n - len(result))) + result
        temp.append(result)
    return temp
