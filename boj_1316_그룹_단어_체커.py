N = int(input())
cnt = 0

for _ in range(N):
    count = {
        'a': 0,
        'b': 0,
        'c': 0,
        'd': 0,
        'e': 0,
        'f': 0,
        'g': 0,
        'h': 0,
        'i': 0,
        'j': 0,
        'k': 0,
        'l': 0,
        'm': 0,
        'n': 0,
        'o': 0,
        'p': 0,
        'q': 0,
        'r': 0,
        's': 0,
        't': 0,
        'u': 0,
        'v': 0,
        'w': 0,
        'x': 0,
        'y': 0,
        'z': 0,
    }
    new_input = input()
    if len(new_input) == 1:
        cnt += 1
    else:
        count[new_input[0]] += 1
        for i in range(1, len(new_input)):
            if new_input[i] != new_input[i-1] and count[new_input[i]] != 0:
                break
            count[new_input[i]] += 1
        else:
            cnt += 1
print(cnt)