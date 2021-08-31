def solution(dartResult):
    points = []
    bonus = []
    option = []
    answer = 0
    i = 0
    j = 0
    for _ in range(3):
        while True:
            if dartResult[i] == 'S' or dartResult[i] == 'D' or dartResult[i] == 'T':
                if i+1 < len(dartResult) and (dartResult[i+1] == '*' or dartResult[i+1] == '#'):
                    points.append(dartResult[j:i])
                    bonus.append(dartResult[i])
                    option.append(dartResult[i+1])
                    i += 1
                else:
                    points.append(dartResult[j:i])
                    bonus.append(dartResult[i])
                    option.append(None)
                i += 1
                j = i
                break
            i += 1

    nums = []
    for i in range(3):
        num = 0
        if bonus[i] == 'S':
            num += int(points[i])
        elif bonus[i] == 'D':
            num += int(points[i]) ** 2
        elif bonus[i] == 'T':
            num += int(points[i]) ** 3

        if option[i] == '*':
            if i == 0:
                num *= 2
            else:
                num *= 2
                nums[i-1] *= 2
        elif option[i] == '#':
            num *= -1
        nums.append(num)
    answer = sum(nums)

    return answer

# dartResult = input()
# print(solution(dartResult))