def solution(strings, n):
    answer = []
    array = [[] for _ in range(len(strings))]
    for idx, word in enumerate(strings):
        array[idx].append(word)

    array = sorted(array, key=lambda x: (x[0][n], x[0]))
    for string in array:
        answer.append(string[0])
    return answer
