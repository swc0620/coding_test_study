def solution(board, moves):
    answer = 0
    bag = []
    for n in moves:
        for m in board:
            if m[n-1] != 0:
                bag.append(m[n-1])
                m[n-1] = 0
                break
        if len(bag) > 1:
            if bag[-1] == bag[-2]:
                bag = bag[:-2]
                answer += 2
    return answer
