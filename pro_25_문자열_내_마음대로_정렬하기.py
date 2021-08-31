def solution(strings, n):
    vocab = {}
    answer = []
    for word in strings:
        if word[n] in vocab.keys():
            vocab[word[n]].append(word)
        else:
            vocab[word[n]] = [word]
    vocab = sorted(vocab.items())
    for i in vocab:
        answer.extend(sorted(i[1]))
    return answer

# strings = input().split(",")
# n = int(input())
# print(solution(strings, n))