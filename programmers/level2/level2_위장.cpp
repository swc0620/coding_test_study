#include <string>
#include <vector>
#include <map>
using namespace std;

map< string, vector<string> > clothesMap;

int solution(vector< vector<string> > clothes) {
    int answer=1;
    for(auto a : clothes){
        clothesMap[a[1]].push_back(a[0]);
    }
    for( auto a : clothesMap){
        answer *= a.second.size()+1;
    }

    return answer-1;
}

/*
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for(vector<string> c : clothes){
        m[c[1]]++;
    }
    int answer = 1;
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        answer *= it->second + 1;
    }
    return answer-1;
}
*/