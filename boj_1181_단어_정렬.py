N = int(input())

wordbook = []

for _ in range(N):
    word = input()
    word_len = len(word)
    wordbook.append((word_len, word))

wordbook = list(set(wordbook))

wordbook.sort(key=lambda word:(word[0], word[1]))

for word in wordbook:
    print(word[1])