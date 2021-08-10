def solution(record):
    answer = []
    usrname = {}
    results = []
    for rec in record:
        command = rec.split()
        if command[0] == 'Enter':
            usrname[command[1]] = command[2]
            results.append(('Enter', command[1]))
        elif command[0] == 'Leave':
            results.append(('Leave', command[1]))
        else:
            usrname[command[1]] = command[2]
    
    print(usrname)
    print(results)

    for result in results:
        if result[0] == 'Enter':
            answer.append(f'{usrname[result[1]]}님이 들어왔습니다.')
        else:
            answer.append(f'{usrname[result[1]]}님이 나갔습니다.')
    return answer
    
# record = input().split(",")
# print(record)
# for idx, rec in enumerate(record):
#     record[idx] = rec.strip("\"")
# print(record)
# print(solution(record))