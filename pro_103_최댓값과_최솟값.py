def solution(s):
    answer = ''
    nums = list(map(int, s.split()))
    small = str(min(nums))
    big = str(max(nums))
    answer = [small, big]
    return " ".join(answer)