#include <string>
#include <vector>
#include <algorithm> // std::reverse

using namespace std;

string decipher(int n, int binary) {
    string result{ "" };
    while (binary > 0) { // 
        result.append(to_string(binary % 2));
        binary /= 2; 
    }
    while (result.length() < n) {
        result.push_back('0'); // 길이 n이 될 때까지 앞에 0 붙임
    }
    reverse(result.begin(), result.end()); // 나머지가 뒤에서부터 저장됨
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer; // #와 공백
    vector<string> map1, map2;

    for (int i=0; i<n; ++i) {
        map1.push_back(decipher(n, arr1[i]));
        map2.push_back(decipher(n, arr2[i]));
    }

    for (int i=0; i<n; ++i) {
        string row{ "" };
        for (int j=0; j<n; ++j) {
            if (map1[i][j] == '0' && map2[i][j] == '0') {
                row.push_back(' ');
            } else {
                row.push_back('#');
            }
        }
        answer.push_back(row);
    }

    return answer;
}