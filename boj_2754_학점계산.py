grade = input()
if grade == 'F':
    print(0.0)
else:
    char = grade[0]
    op = grade[1]
    if char == 'A':
        grade = 4.0
    elif char == 'B':
        grade = 3.0
    elif char == 'C':
        grade = 2.0
    elif char == 'D':
        grade = 1.0
    
    if op == '+':
        grade += 0.3
    elif op == '-':
        grade -= 0.3
    
    print(grade)