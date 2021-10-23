import re

while True:
    try:
        line = input()
        line = line.lower()
        if re.search(r'problem', line):
            print("yes")
        else:
            print("no")
    except:
        break