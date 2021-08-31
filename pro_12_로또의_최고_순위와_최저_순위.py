def check_ranking(num):
    if num >= 2:
        num_ranking = 7-num
    else:
        num_ranking = 6
    return num_ranking        

def solution(lottos, win_nums):
    answer = []
    correct = 0
    high = 0
    for num in lottos:
        if num in win_nums:
            correct += 1
        if num == 0:
            high += 1
    answer.append(check_ranking(correct+high))
    answer.append(check_ranking(correct))
    return answer

# lottos = list(map(int, input().split(",")))
# win_nums = list(map(int, input().split(",")))
# print(solution(lottos, win_nums))