def solution(n, words):
    answer = []

    for idx, word in enumerate(words):
        q, r = divmod(idx, n)
        if idx >= 1:
            if words[idx-1][-1] != words[idx][0]:
                answer.append(r+1)
                answer.append(q+1)
                break
            if word in words[:idx]:
                answer.append(r+1)
                answer.append(q+1)
                break
    else:
        answer.append(0)
        answer.append(0)

    return answer