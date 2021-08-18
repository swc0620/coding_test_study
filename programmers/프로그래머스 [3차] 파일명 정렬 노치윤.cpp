#include <string>
#include <vector>
#include <list>
#include <cctype>
using namespace std;

bool comp(string a, string b) {
    string head_a = "";
    string number_a = "";
    string tail_a = "";
    string head_b = "";
    string number_b = "";
    string tail_b = "";
    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
        if (tail_a == "" && a[i] >= '0' && a[i] <= '9') {//tail_a==""을 해준 이유: ABC100AA1 인경우 number_a에는 100 이 저장 되야 하는데 1001 이 저장 되어 버림.
            number_a += a[i];
            continue;
        }
        if (number_a != "") tail_a += a[i];
        else head_a += a[i];
    }
    for (int i = 0; i < b.length(); i++) {
        b[i] = tolower(b[i]);
        if (tail_b == "" && b[i] >= '0' && b[i] <= '9') {
            number_b += b[i];
            continue;
        }
        if (number_b != "") tail_b += b[i];
        else head_b += b[i];
    }
    int numA = stoi(number_a);
    int numB = stoi(number_b);
    if (head_a > head_b) return true;
    else if (head_a < head_b) return false;
    else {
        if (numA > numB) return true;
        else if (numA < numB) return false;
        else {
            return false;//a 보다 b가 늦게 들어옴. 즉 stable sort를 위해서는 a<b라고 해야함.
        }
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    list<string> ans;
    ans.push_back(files[0]);
    for (int i = 1; i < files.size(); i++) {
        list<string>::iterator iter = ans.begin();
        while (iter != ans.end()) {
            if (comp(*iter, files[i])) {//만일 *iter가 files[i]보다 크게 되면 그자리에 insert
                ans.insert(iter, files[i]);
                break;
            }
            else iter++;
            if (iter == ans.end()) ans.push_back(files[i]);//모두 files[i]보다 작은 경우는 마지막 위치에 insert
        }
    }
    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
        answer.push_back(*iter);
    }
    return answer;
}