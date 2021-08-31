import heapq

def dijkstra(graph, start):
    dist = {vertex:float('inf') for vertex in graph}
    dist[start] = 0
    heap = []
    heapq.heappush(heap, [dist[start], start])
    while heap:
        curr_dist, curr_dest = heapq.heappop(heap)
        
        if dist[curr_dest] < curr_dist:
            continue
        
        for new_dest, new_dist in graph[curr_dest].items():
            distance = curr_dist + new_dist
            if distance < dist[new_dest]:
                dist[new_dest] = distance
                heapq.heappush(heap, [distance, new_dest])

    return dist

def solution(N, road, K):
    answer = 0
    graph = {vertex:{} for vertex in range(1, N+1)}

    for r in road:
        a, b, c = r
        if b in graph[a].keys():
            graph[a][b] = min(c, graph[a][b])
            if a in graph[b].keys():
                graph[b][a] = min(c, graph[b][a])
            else:
                graph[b][a] = c
        else:
            graph[a][b] = c
            if a in graph[b].keys():
                graph[b][a] = min(c, graph[b][a])
            else:
                graph[b][a] = c

    distance = dijkstra(graph, 1)

    for dist in distance.values():
        if dist <= K:
            answer += 1
    return answer
