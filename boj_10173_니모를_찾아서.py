import re

while True:
    line = input()
    if line == "EOI":
        break
    line = line.lower()
    if re.search(r'(Nemo|nemo)', line):
        print("Found")
    else:
        print("Missing")
    