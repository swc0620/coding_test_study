def solution(nums):
    N = len(nums)
    phonekemon = {}
    for index, mon in enumerate(nums):
        if mon in phonekemon.keys():
            phonekemon[mon] += 1
        else:
            phonekemon[mon] = 1
    
    answer = 0
    if len(phonekemon) >= N//2:
        answer = N//2
    else:
        answer = len(phonekemon)

    return answer

# nums = list(map(int, input().split(",")))
# print(solution(nums))