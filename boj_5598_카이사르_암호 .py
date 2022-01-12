res = ""
string = input()
for c in string:
    candidate =  ord(c) - 3
    if candidate < 65:
        candidate += 26
    res += chr(candidate)
print(res)