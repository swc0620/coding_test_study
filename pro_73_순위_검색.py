from itertools import combinations

def solution(info, query):
    db = {}
    answer = []

    for i in info:
        inf = i.split(" ")
        data = inf[:-1]
        db_val = int(inf[-1])
        for j in range(len(data)+1):
            combis = combinations(data, j)
            for combi in combis:
                db_key = ''.join(combi)
                if db_key in db.keys():
                    db[db_key].append(db_val)
                else:
                    db[db_key] = [db_val]

    for db_key in db.keys():
        db[db_key].sort()
    
    for qu in query:
        q = qu.split(" and ")
        temp = q[-1].split(" ")
        q.pop()
        q.extend(temp[0])
        while '-' in q:
            q.remove('-')
        q_key = ''.join(q)
        q_val = int(temp[1])

        if q_key in db.keys():
            scores = db[q_key]
            if scores:
                start, end = 0, len(scores)
                while start < end:
                    mid = (start + end) // 2
                    if scores[mid] >= q_val:
                        end = mid
                    else:
                        start = mid + 1
                answer.append(len(scores) - start)
        else:
            answer.append(0)
    return answer

# infos = input().split(",")
# info = []
# for i in infos:
#     i = i[1:-1]
#     info.append(i)

# queries = input().split(",")
# query = []
# for i in queries:
#     i = i[1:-1]
#     query.append(i)

# print(solution(info, query))