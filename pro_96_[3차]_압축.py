import string

def solution(msg):
    answer = []
    wordbook = list(string.ascii_uppercase)
    i = 0
    while True:
        if i >= len(msg):
            break
        j = i+1
        while True:
            if msg[i:j] not in wordbook:
                break
            else:
                if j > len(msg):
                    break
                j += 1
        answer.append(wordbook.index(msg[i:j-1]) + 1)
        wordbook.append(msg[i:j])
        i = j - 1
    return answer

# print(solution(input()))