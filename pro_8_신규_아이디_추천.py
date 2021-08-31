import re

def solution(new_id):
    answer = ''

    # 1단계
    new_id = new_id.lower()

    # 2단계
    new_id = re.sub(r'[^a-z\d\-\_\.]', r'', new_id)

    # 3단계
    new_id = re.sub(r'\.+', r'.', new_id)

    # 4단계
    new_id = re.sub(r'^\.|\.$', r'', new_id)

    # 5단계
    if new_id == '':
        new_id = 'a'

    # 6단계
    new_id = re.sub(r'\.$', r'', new_id[:15])

    # 7단계
    while len(new_id) <= 2:
        new_id += new_id[-1]


    answer = new_id
    return answer

new_id = input()
print(solution(new_id))