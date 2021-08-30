#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) { // 중복되는 원소 X
        arr[0] = -1;
    } else {
        arr.erase(min_element(arr.begin(), arr.end()));
    }
    return arr;   
}