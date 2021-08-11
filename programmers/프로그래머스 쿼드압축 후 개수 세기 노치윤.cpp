#include <string>
#include <vector>

using namespace std;

vector<int> find_num(int x, int y, int width, vector<vector<int>>& arr) {
    vector<int> ans(2, 0);
    if (width == 1) { //원소가 1개인 경우
        if (arr[x][y] == 1) ans[1]++;
        else ans[0]++;
        return ans;
    }
    int comp = arr[x][y];
    bool check = true;
    for (int i = x; i < x + width; i++) { //영역 내 모든 원소가 같은지 확인하는 루프
        for (int j = y; j < y + width; j++) {
            if (arr[i][j] != comp) {
                check = false;
                break;
            }
        }
        if (!check) break;
    }
    if (check) { //만일 모든 원소가 같다면 그 원소가 0이라면 ans[0]++, 1이라면 ans[1]++
        ans[comp]++;
        return ans;
    }
    //한개의 영역은 총 4개의 영역으로 나뉨
    vector<int> temp1 = find_num(x, y, width / 2, arr);
    vector<int> temp2 = find_num(x + width / 2, y, width / 2, arr);
    vector<int> temp3 = find_num(x, y + width / 2, width / 2, arr);
    vector<int> temp4 = find_num(x + width / 2, y + width / 2, width / 2, arr);
    ans[0] = ans[0] + temp1[0] + temp2[0] + temp3[0] + temp4[0];
    ans[1] = ans[1] + temp1[1] + temp2[1] + temp3[1] + temp4[1];
    return ans;
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer = find_num(0, 0, arr.size(), arr);
    return answer;
}