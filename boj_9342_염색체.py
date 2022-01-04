import re

pattern = re.compile(r'^[ABCDEF]?A+F+C+[ABCDEF]?$')
T = int(input())
for _ in range(T):
    chromosome = input()
    if pattern.match(chromosome):
        print("Infected!")
    else:
        print("Good")