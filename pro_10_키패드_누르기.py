def solution(numbers, hand):
    answer = ''
    left = '*'
    right = '#'
    for index, num in enumerate(numbers):
        if num in [1, 4, 7]:
            answer += 'L'
            left = num
        elif num in [3, 6, 9]:
            answer += 'R'
            right = num
        else:
            if num == 2:
                if left == 2:
                    answer += 'L'
                    left = num
                elif left == 1 or left == 5:
                    if right == 2:
                        answer += 'R'
                        right = num
                    elif right == 3 or right == 5:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 4 or left == 8:
                    if right == 2 or right == 3 or right == 5:
                        answer += 'R'
                        right = num
                    elif right == 6 or right == 8:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 7 or left == 0:
                    if right == 2 or right == 3 or right == 5 or right == 6 or right == 8:
                        answer += 'R'
                        right = num
                    elif right == 9 or right == 0:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                else:
                    if right == '#':
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'R'
                        right = num
            elif num == 0:
                if left == 0:
                    answer += 'L'
                    left = num
                elif left == '*' or left == 8:
                    if right == 0:
                        answer += 'R'
                        right = num
                    elif right == '#' or right == 8:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 7 or left == 5:
                    if right == 0 or right == '#' or right == 8:
                        answer += 'R'
                        right = num
                    elif right == 5 or right == 9:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 2 or left == 4:
                    if right == 0 or right == '#' or right == 8 or right == 5 or right == 9:
                        answer += 'R'
                        right = num
                    elif right == 2 or right == 6:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                else:
                    if right == 3:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'R'
                        right = num
            elif num == 5:
                if left == 5:
                    answer += 'L'
                    left = num
                elif left == 2 or left == 4 or left == 8:
                    if right == 5:
                        answer += 'R'
                        right = num
                    elif right == 2 or right == 6 or right == 8:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 1 or left == 7 or left == 0:
                    if right == 5 or right == 2 or right == 6 or right == 8:
                        answer += 'R'
                        right = num
                    elif right == 3 or right == 9 or right == 0:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                else:
                    if right == '#':
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'R'
                        right = num
            elif num == 8:
                if left == 8:
                    answer += 'L'
                    left = num
                elif left == 5 or left == 7 or left == 0:
                    if right == 8:
                        answer += 'R'
                        right = num
                    elif right == 5 or right == 9 or right == 0:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                elif left == 2 or left == 4 or left == '*':
                    if right == 8 or right == 5 or right == 9 or right == 0:
                        answer += 'R'
                        right = num
                    elif right == 2 or right == 6 or right == '#':
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'L'
                        left = num
                else:
                    if right == 3:
                        if hand == 'left':
                            answer += 'L'
                            left = num
                        else:
                            answer += 'R'
                            right = num
                    else:
                        answer += 'R'
                        right = num            
    return answer

# numbers = list(map(int, input().split(",")))
# hand = input()
# print(solution(numbers, hand))