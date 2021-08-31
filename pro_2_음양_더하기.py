def solution(absolutes, signs):
    answer = 0
    for i, num in enumerate(absolutes):
        if signs[i] == 'true':
            answer += num
        else:
            answer -= num
    return answer

# absolutes = list(map(int, input().split(',')))
# signs = input().split(',')

# print(solution(absolutes, signs))