from collections import defaultdict
from itertools import combinations

def solution(infos, queries):
    answer = []
    info_dict = defaultdict(list)
        
    for i in range(len(infos)):
        tmp = infos[i].split(" ")
        tmp_str, tmp_score = tmp[:-1], tmp[-1]
        
        for k in range(5):
            for combi in combinations(tmp_str, k):
                info_dict[''.join(combi)].append(int(tmp_score))
            
    for keys in info_dict:
        info_dict[keys].sort()

    for query in queries:
        q = query.replace(" and ", "").replace("-", "")
        q_str, q_score = q.split(" ")
        q_score = int(q_score)
        

        if q_str in info_dict:
            scores =info_dict[q_str]
            
            if scores:
                start, end = 0 , len(scores)
                while start < end:
                    mid = (start + end) // 2
                    if scores[mid] >= q_score:
                        end = mid
                    else:
                        start = mid + 1
                
                answer.append(len(scores) - start) 
        
        else:
            answer.append(0)
    
    return answer
