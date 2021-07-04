import re

def solution(new_id):
    answer = ''
    answer = new_id.lower()
    answer = re.sub('[^a-z\d\-\_\.]', '', answer)
    answer = re.sub('\.\.+', '.', answer)
    answer = re.sub('^\.|\.$', '', answer)
    if answer == '':
        answer = 'a'
    answer = re.sub('\.$', '', answer[0:15])
    while len(answer) < 3:
        answer += answer[-1:]
    return answer

# new_id = input()
# print(solution(new_id))
