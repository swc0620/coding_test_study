def solution(skill, skill_trees):
    answer = 0
    for tree in skill_trees:
        temp = list(skill)
        for i in tree:
            if i in temp and i == temp[0]:
                temp.pop(0)
                continue
            elif i in temp and i != temp[0]:
                break
        else:
            answer += 1
    return answer


# skill = input()
# skill_trees = input().split()
# print(solution(skill, skill_trees))