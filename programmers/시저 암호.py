def solution(s, n):
    answer = ''
    for char in s:
        if char == ' ':
            answer += ' '
        else:
            if char.isupper():
                answer += chr((ord(char) - ord('A') + n) % 26 + ord('A'))
            else:
                answer += chr((ord(char) - ord('a') + n) % 26 + ord('a'))
    return answer
