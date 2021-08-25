#include <string> 
#include <vector> 
#include <sstream> 

using namespace std; 
vector<string> split(string str, char delimiter) { 
    stringstream ss(str); 
    string tmp; 
    vector<string> v; 
    while (getline(ss, tmp, delimiter)) {
        v.push_back(tmp); 
    } 
        return v; 
} 
    
string solution(string s) { 
    vector<string> v = split(s, ' '); 
    int min = stoi(v[0]); 
    int max = stoi(v[0]); 
    for(int i=1; i<v.size(); i++){ 
        int num = stoi(v[i]); 
        if(num < min) min = num; 
        if(num > max) max = num; 
    } 
    return to_string(min) + " " + to_string(max); 
}
