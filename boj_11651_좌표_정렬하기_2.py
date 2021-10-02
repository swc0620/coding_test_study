import sys

N = int(input())

points = []

for _ in range(N):
    point = tuple(map(int, sys.stdin.readline().split()))
    points.append(point)

points.sort(key=lambda point: (point[1], point[0]))

for point in points:
    print(point[0], point[1])