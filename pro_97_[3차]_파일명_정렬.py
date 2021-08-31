def solution(files):
    answer = []
    file_names = []
    for f in files:
        num_idx = 0
        tail_idx = len(f)
        for i, s in enumerate(f):
            if '0' <= s <= '9':
                num_idx = i
                break
        for j in range(i, len(f)):
            if f[j] < '0' or f[j] > '9':
                tail_idx = j
                break
        head = f[:num_idx]
        number = f[num_idx:tail_idx]
        tail = f[tail_idx:]
        file_names.append((head.lower(), int(number), head, number, tail))

    file_names = sorted(file_names, key=lambda element: (element[0], element[1]))
    
    for f in file_names:
        answer.append(f[2] + f[3] + f[4])
    return answer

# print(solution(input().split()))
# print(solution(["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"]))
