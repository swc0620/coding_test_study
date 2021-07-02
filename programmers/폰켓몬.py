def solution(nums):
    answer = 0
    pick_num = len(nums) / 2
    unique_num = len(set(nums))
    if unique_num >= pick_num:
        answer = pick_num
    else:
        answer = unique_num
    return answer
