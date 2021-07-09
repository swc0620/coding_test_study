def solution(s, n):
    answer = ''
    for i in s:
        ascii_s = ord(i)
        new_ascii_s = ascii_s + n
        if 65 <= ascii_s <= 90:
            if new_ascii_s > 90:
                answer += chr(new_ascii_s - 26)
            else:
                answer += chr(new_ascii_s)
        elif ascii_s == 32:
            answer += " "
        else:
            if new_ascii_s > 122:
                answer += chr(new_ascii_s - 26)
            else:
                answer += chr(new_ascii_s)
    return answer

s = input()
n = int(input())
print(solution(s, n))