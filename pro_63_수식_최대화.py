def helper(expression, delimiter, index):
    if expression.isdigit():
        return expression
    splited_expr = expression.split(delimiter[index])
    temp = []
    for exp in splited_expr:
        temp.append(helper(exp, delimiter, index+1))
    return str(eval(delimiter[index].join(temp)))

def solution(expression):
    answer = 0
    delimiters = ['+-*', '+*-', '-+*', '-*+', '*+-', '*-+']
    for delimiter in delimiters:
        answer = max(abs(int(helper(expression, delimiter, 0))), answer)
    return answer

# print(solution(input()))