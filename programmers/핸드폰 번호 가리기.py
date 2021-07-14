import re

def solution(phone_number):
    answer = '*' * len(phone_number[:-4]) + phone_number[-4:] # slicing
    return answer
    # return re.sub(r'\d(?=\d{4})', '*', phone_number) <- 숫자 4자리가 남을 때까지 계속 *로 대체
