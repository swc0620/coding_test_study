def solution(citations):
    citations.sort()
    length = len(citations)
    for i in range(length):
        if citations[i] >= length-i:
            return length-i
    return 0

# citations = list(map(int, input().split()))
# print(solution(citations))