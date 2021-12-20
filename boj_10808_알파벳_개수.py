import string
letter_count = dict.fromkeys(string.ascii_lowercase, 0)
string = input()
for char in string:
    letter_count[char] += 1
for char in letter_count.values():
    print(char, end= " ")