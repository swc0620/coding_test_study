#include <map>
#include <queue>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    map<int,vector<pair<int,int>>> graph; // adjacency hash table - 마을번호 : 인접한 마을과 사이의 거리
    
    auto compare = [](pair<int,int> a, pair<int,int> b) { return a.second < b.second; };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)> pq(compare); // min heap -> 마을 간 최소 거리 자동으로 찾아줌
    vector<int> dist(N+1,500001); // 최대 거리
    vector<bool> visited(N+1,false); // 방문여부
    
    // graph 만들기
    for (auto info : road) {
        int a,b,c;
        a = info[0];
        b = info[1];
        c = info[2];
        
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    
    // 첫번째 마을에서 출발, 거리는 0에서 시작
    pq.push(make_pair(1,0));
    dist[1] = 0;
    while (!pq.empty()) {
        int curr = pq.top().first;
        pq.pop();
        
        for (auto edge : graph[curr]) {
            int next = edge.first;
            int time = edge.second;
            
            if (!visited[next]) {
                if (dist[next] > dist[curr] + time) {
                    dist[next] = dist[curr] + time;
                    pq.push(make_pair(next,dist[next]));
                }
            }
        }
    }
    
    for (int val : dist) {
        if (val <= K)
            ++answer;
    }


    return answer;
}