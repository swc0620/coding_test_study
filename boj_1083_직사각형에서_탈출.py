x, y, w, h = map(int, input().split())
print(min(abs(x), abs(y), abs(x-w), abs(y-h)))