#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int size = relation.size();
    vector<string> tuple;
    for (int a = 1; a <= relation[0].size(); a++) {
        vector<int> vec(relation[0].size(), 0);
        int cnt = 0;
        while (cnt < a) {
            vec[cnt] = 1;
            cnt++;
        }
        sort(vec.begin(), vec.end());
        do {
            string idx = "";
            for (int i = 0; i < vec.size(); i++) {
                if (vec[i] == 1) idx += to_string(i);
            }
            bool isMinimal = true;
            if (!tuple.empty()) {
                for (int i = 0; i < tuple.size(); i++) {
                    int cnt = 0;
                    for (int j = 0; j < tuple[i].length(); j++) {
                        if (idx.find(tuple[i][j]) != string::npos) cnt++;
                    }
                    if (cnt == tuple[i].length()) isMinimal = false;//cnt는 최소화 만족 x
                }
            }
            if (isMinimal == false) continue;
            //유일성 판단
            bool isUnique = true;
            for (int i = 0; i < relation.size() - 1; i++) {
                for (int j = i + 1; j < relation.size(); j++) {
                    if (relation[i][idx[0] - '0'] == relation[j][idx[0] - '0']) {//오직 1개의 원소를 가질 때는 한개만 겹치면 유일성 만족 x, 여러개는 1개겹쳐도 다른게 안겹치면 만족
                        if (idx.length() == 1) {
                            isUnique = false;
                            break;
                        }
                        bool canDisc = false;
                        for (int k = 1; k < idx.length(); k++) {
                            if (relation[i][idx[k] - '0'] != relation[j][idx[k] - '0']) {
                                canDisc = true;
                            }
                        }
                        if (canDisc == false) isUnique = false;
                    }
                }
            }
            if (isUnique == false) continue;

            tuple.push_back(idx);

        } while (next_permutation(vec.begin(), vec.end()));


    }

    answer = tuple.size();

    return answer;
}