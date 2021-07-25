#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool isAlphabet(const char &c) {
    return c >= 'a' && c <= 'z';
}

multiset<string> split(const string &s) {
    multiset<string> result;
    
    for (int i=0; i<s.length()-1; ++i) {
        if (!isAlphabet(s[i]) || !isAlphabet(s[i+1]))
            continue;
        string token{ "" };
        token += s[i] + s[i+1];
        result.insert(token);
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    multiset<string> set1 = split(str1);
    multiset<string> set2 = split(str2);
    
    multiset<string> union_set;
    multiset<string> intersect_set;
    set_union(set1.begin(), set1.end(),
                set2.begin(), set2.end(),
                inserter(union_set, union_set.begin()));
    set_intersection(set1.begin(), set1.end(),
                set2.begin(), set2.end(),
                inserter(intersect_set, intersect_set.begin()));
    
    double jaccard = (double) intersect_set.size() / union_set.size() * 65536;
    
    answer = (int) jaccard;
    return answer;
}