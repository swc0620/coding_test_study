from itertools import permutations
import re

def calculate(num1, num2, operator):
    if operator == '+':
        return str(int(num1) + int(num2))
    if operator == '-':
        return str(int(num1) - int(num2))
    if operator == '*':
        return str(int(num1) * int(num2))

def operation(exp, oper):
    result = re.split('(\D)', exp)
    
    for op in oper:
        stack = []
        while len(result) != 0:
            tmp = result.pop(0)
            if tmp == op:
                stack.append(calculate(stack.pop(), result.pop(0), op))
            else:
                stack.append(tmp)
        result = stack
        
    return abs(int(result[0]))
            
def solution(expression):
    answer = []
    operator = ['+', '-', '*']
    operation_case = list(permutations(operator, 3))
    for op in operation_case:
        answer.append(operation(expression, op))
    return max(answer)
