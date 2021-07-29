from itertools import combinations

def checkMinimality(candidate, target):
    for i in range(len(candidate)):
        cnt = 0
        for j in range(len(candidate[i])):
            if candidate[i][j] in target:
                cnt += 1
        if cnt == len(candidate[i]):
            return False

    return True

def checkUniqueness(relation, combi):
    arr = []
    for i in range(len(relation)):
        temp = []
        for j in range(len(combi)):
            temp.append(relation[i][combi[j]])

        if temp in arr:
            return False

        arr.append(temp)

    return True

def solution(relation):
    answer = 0
    combiList = [i for i in range(len(relation[0]))]
    combination = []
    candidate = []

    for i in range(1, len(relation[0])+1):
        combination.append(list(combinations(combiList, i)))
        
    for i in range(len(combination)):
        for j in range(len(combination[i])):
            if checkUniqueness(relation, combination[i][j]) and checkMinimality(candidate, combination[i][j]):
                answer += 1
                candidate.append(list(combination[i][j]))

    return answer
