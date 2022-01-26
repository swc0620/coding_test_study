import re

string = input()
results = re.finditer(r'(?=(JOI))', string)
print(sum(1 for _ in results))
results = re.finditer(r'(?=(IOI))', string)
print(sum(1 for _ in results))