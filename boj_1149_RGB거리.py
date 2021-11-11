N = int(input())
red = [0]
green = [0]
blue = [0]
for i in range(1, N+1):
    R, G, B = map(int, input().split())
    red.append(min(green[i-1], blue[i-1])+R)
    green.append(min(red[i-1], blue[i-1])+G)
    blue.append(min(red[i-1], green[i-1])+B)

print(min(red[N], green[N], blue[N]))