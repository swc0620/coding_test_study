#include <string>
#include <vector>

using namespace std;

vector<int> result{ 0,0 };

void zip(int m, int n, int size, const vector<vector<int>> &arr) {
    int val = arr[m][n];
    if (size == 1) { // 더이상 쪼갤 수 X
        ++result[val];
        return;
    }
    
    bool doZip = true;
    
    for (int i=m; i<m+size; ++i) { // 영역 S 내에서 다른 숫자가 있는가
        for (int j=n; j<n+size; ++j) {
            if (arr[i][j] != val) {
                doZip = false;
                break;
            }
        }
        if (!doZip)
            break;
    }
    
    // 종료조건
    if (doZip) {
        ++result[val];
        return; // 더 잘게 쪼개지 X
    }
    
    // 재귀반복
    int newSize = size / 2;
    zip(m, n, newSize, arr);
    zip(m, n+newSize, newSize, arr);
    zip(m+newSize, n, newSize, arr);
    zip(m+newSize, n+newSize, newSize, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    zip(0, 0, arr.size(), arr);
    answer = result;
    return answer;
}