from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []
    for num in course:
        menu = []
        for food in orders:
            for sample in combinations(food, num): # 음식 메뉴 몇 개 선정할 것인지 조합으로 생성
                tmp = ''.join(sorted(sample))
                menu.append(tmp)
                
        sorted_menu = Counter(menu).most_common() # value가 높은 순으로 정렬
        answer += [menu for menu, cnt in sorted_menu if cnt > 1 and cnt == sorted_menu[0][1]] # 가장 많이 주문한 것만 + 주문 횟수가 동일한 메뉴도 포함
        
    return sorted(answer)
