def solution(s):
    answer = ''
    s_list = s.split(' ')
    idx = 0
    
    for word in s_list:
        for char in word:
            if idx % 2 == 0:
                char = char.upper()
            else:
                char = char.lower()
            answer += char
            idx += 1
        answer += ' '
        idx = 0
    return answer[:-1]
