import math
from itertools import permutations

def solution(numbers):
    answer = 0
    nums = []
    for c in range(1, len(numbers)+1):
        comb = list(permutations(numbers, c))
        nums.extend([int(''.join(x)) for x in comb])
    nums = set(nums)
    nums.discard(0)
    nums.discard(1)

    primes = []
    for num in nums:
        prime = True
        for i in range(2, int(num ** 0.5)+1):
            if num % i == 0:
                prime = False
                break
        if prime:
            primes.append(num)
            answer += 1
    return answer

# print(solution(input()))