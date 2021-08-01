from collections import deque
def solution(prices):
    answer = [0] * len(prices)
    price_stack = []
    
    for i, price in enumerate(prices):
        while price_stack and price < prices[price_stack[-1]]:
            j = price_stack.pop()
            answer[j] = i - j
        price_stack.append(i)
    
    while price_stack:
        j = price_stack.pop()
        answer[j] = len(prices) - 1 - j
    return answer
