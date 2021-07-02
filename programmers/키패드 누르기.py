def solution(numbers, hand):
    answer = ''
    left = [1, 4, 7]
    right = [3, 6, 9]
    middle = [2, 5, 8, 11]
    r_hand = 10
    l_hand = 12
    for num in numbers:
        if num == 0:
            num = 11
        if num in left: # 왼손 리스트에 속한 경우
            l_hand = num
            answer += 'L'
        elif num in right: # 오른손 리스트에 속한 경우
            r_hand = num
            answer += 'R'
        else:
            # 거리 체크
            dist1 = abs(num - l_hand) // 3 + abs(num - l_hand) % 3
            dist2 = abs(num - r_hand) // 3 + abs(num - r_hand) % 3
            if dist1 > dist2:
                answer += 'R'
                r_hand = num
            elif dist1 < dist2:
                answer += 'L'
                l_hand = num
            else: # 거리가 같을 경우
                if hand == 'right':
                    answer += 'R'
                    r_hand = num
                else:
                    answer += 'L'
                    l_hand = num
    return answer
