def solution(lottos, win_nums):
    answer = []
    count = 0
    rank = {6:1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6}
    for i in range(len(lottos)):            
        if lottos[i] in win_nums:
            count += 1
    
    num_pos = lottos.count(0)
    
    answer.append(rank[count + num_pos])
    answer.append(rank[count])
    return answer
