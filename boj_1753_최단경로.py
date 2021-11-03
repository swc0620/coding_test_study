import sys, heapq
input = sys.stdin.readline

V, E = map(int, input().split())
graph = {i+1: {} for i in range(V)}
start = int(input())
for _ in range(E):
    u, v, w = map(int, input().split())
    if v in graph[u]:
        graph[u][v] = min(graph[u][v], w)
    else:
        graph[u][v] = w

def dijkstra(graph, start):
    dist = {i+1: float('inf') for i in range(V)}
    dist[start] = 0
    queue = []
    heapq.heappush(queue, [dist[start], start])

    while queue:
        curr_dist, curr_dest = heapq.heappop(queue)

        if dist[curr_dest] < curr_dist:
            continue

        for new_dest, new_dist in graph[curr_dest].items():
            distance = curr_dist + new_dist
            if distance < dist[new_dest]:
                dist[new_dest] = distance
                heapq.heappush(queue, [distance, new_dest])
    
    return dist
dist = dijkstra(graph, start)
for i in dist:
    if dist[i] == float('inf'):
        print('INF')
    else:
        print(dist[i])
