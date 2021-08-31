from itertools import combinations
from collections import Counter

def sort_string(string):
    return ''.join(sorted(string))

def solution(orders, course):
    answer = []
    for c in course:
        temp = []
        for order in orders:
            temp += list(combinations(sort_string(order), c))
        temp = [''.join(t) for t in temp]
        counter = Counter(temp)
        course_sets = [k for k, v in counter.items() if v == max(counter.values()) and v != 1]
        answer += ["".join(course_set) for course_set in course_sets]
    answer.sort()
    return answer

orders = input().split()
course = list(map(int, input().split()))
print(solution(orders, course))