import re

n = int(input())
s = input()

ppap = re.findall('pPAp', s)
print(len(ppap))