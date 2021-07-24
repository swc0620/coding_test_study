def solution(numbers):
    convert_str = []
    for number in numbers:
        convert_str.append(str(number))
    
    answer = sorted(convert_str, key=lambda x: x*4, reverse=True)
    return str(int(''.join(answer)))
