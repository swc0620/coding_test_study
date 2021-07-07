import datetime

def solution(a, b):
    answer = ''
    day = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
    
    answer = day[datetime.datetime(2016, a , b).weekday()] # weekday는 월요일(0)부터 일요일(6)까지 정수 반환 
    return answer
