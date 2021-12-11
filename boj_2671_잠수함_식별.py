import re

string = input()
regex = re.compile(r'(100+1+|01)+')
if regex.fullmatch(string):
    print('SUBMARINE')
else:
    print('NOISE')