#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    set<string> answer;
    for (int i = 0; i < course.size(); i++) {
        map<string, int> a;
        for (int j = 0; j < orders.size(); j++) {
            set<string> temp;
            sort(orders[j].begin(), orders[j].end());
            if (orders[j].length() >= course[i]) {
                do {//orders[j] 에서 가능한 메뉴조합들을 temp에 넣는다.
                    string t = orders[j].substr(0, course[i]);
                    sort(t.begin(), t.end());
                    temp.insert(t);

                } while (next_permutation(orders[j].begin(), orders[j].end()));
            }
            for (set<string>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
                if (a.find(*iter) != a.end()) a[*iter] += 1;//다른 사람도 시킨 경우 +1
                else a[*iter] = 1;
            }


        }
        int max = 0;
        if (a.size() != 0) {
            for (map<string, int>::iterator iter = a.begin(); iter != a.end(); iter++) {
                if ((*iter).second > max) {
                    max = (*iter).second;

                }
            }
            if (max != 0 && max != 1) {
                for (map<string, int>::iterator iter = a.begin(); iter != a.end(); iter++) {
                    if ((*iter).second == max) {
                        answer.insert((*iter).first);
                    }
                }
            }

        }

    }

    vector<string> vec;
    for (set<string>::iterator iter = answer.begin(); iter != answer.end(); iter++) {
        vec.push_back(*iter);
    }
    return vec;
}