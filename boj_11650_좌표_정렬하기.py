N = int(input())

points = []

for _ in range(N):
    point = tuple(map(int, input().split()))
    points.append(point)

points.sort(key=lambda point: (point[0], point[1]))

for point in points:
    print(point[0], point[1])