#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<int> make_binary(int num) {
    deque<int> temp;
    while (true) {
        if (num == 0) {
            break;
        }
        int rest = num % 2;
        temp.push_front(rest);
        num /= 2;
    }
    return temp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++) {
        vector<int> tempo;
        for (int j = 0; j < n; j++) {
            tempo.push_back(0);
        }//모든 원소 0으로 초기화
        int num = arr1[i];
        deque<int> temp = make_binary(num);
        for (int i = 0; i < temp.size(); i++) {
            tempo.pop_back();
        }//이진수를 넣을 자리만큼 pop
        while (temp.size() != 0) {
            tempo.push_back(temp.front());
            temp.pop_front();
        }
        vec.push_back(tempo);
    }
    vector<vector<int>> vec2;
    for (int i = 0; i < n; i++) {
        vector<int> tempo;
        for (int j = 0; j < n; j++) {
            tempo.push_back(0);
        }
        int num = arr2[i];
        deque<int> temp = make_binary(num);
        for (int i = 0; i < temp.size(); i++) {
            tempo.pop_back();
        }
        while (temp.size() != 0) {
            tempo.push_back(temp.front());
            temp.pop_front();
        }
        vec2.push_back(tempo);
    }

    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == 1 || vec2[i][j] == 1) {
                temp += "#";
            }
            else {
                temp += " ";
            }
        }
        answer.push_back(temp);
    }
    return answer;
}