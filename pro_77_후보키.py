from itertools import combinations

def solution(relation):
    indices = [i for i in range(len(relation[0]))]
    combis = []
    for i in range(1, len(relation[0])+1):
        combis += list(combinations(indices, i))

    candis = []
    for combi in combis:
        temp = []
        for item in relation:
            temp2 = []
            for idx in combi:
                temp2.append(item[idx])
            temp.append(tuple(temp2))
        if len(set(temp)) == len(relation):
            candis.append(combi)
    
    ans = set(candis)
    for i in range(len(candis)):
        for j in range(i+1, len(candis)):
            if len(candis[i]) == len(set(candis[i]) & set(candis[j])):
                ans.discard(candis[j])
    
    return len(ans)


# relation = []
# for _ in range(6):
#     relation.append(input().split())

# print(solution(relation))