from collections import Counter

N = int(input())
books = []
for _ in range(N):
    books.append(input())

counter = Counter(books)
books = counter.most_common()
most_common = books[0][1]
res = books[0][0]
for i in range(1, len(books)):
    if books[i][1] < most_common:
        break
    if books[i][0] < res:
        res = books[i][0]
print(res)