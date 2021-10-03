word = input()
strings = []
for i in range(len(word)):
    strings.append(word[i:])

strings.sort()
for string in strings:
    print(string)