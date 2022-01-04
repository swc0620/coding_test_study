import re
string = input()
pattern = re.compile(r'.*U+.*C+.*P+.*C+.*')
if pattern.findall(string):
    print('I love UCPC')
else:
    print('I hate UCPC')