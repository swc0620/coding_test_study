from collections import deque

def solution(cacheSize, cities):
    answer = 0
    if cacheSize == 0:
        return len(cities) * 5

    cache = deque()
    for city in cities:
        city = city.lower()
        if city in cache:
            cache.remove(city)
            cache.appendleft(city)
            answer += 1
        else:
            if len(cache) < cacheSize:
                cache.appendleft(city)
            else:
                cache.pop()
                cache.appendleft(city)
            answer += 5
                
    return answer

# cacheSize = int(input())
# cities = input().split(", ")
# cities = [city[1:-1] for city in cities]
# print(solution(cacheSize, cities))