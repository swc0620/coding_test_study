import re

string = input()
new_string = re.sub(r'C|A|M|B|R|I|D|G|E', r'', string)
print(new_string)