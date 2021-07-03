#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    set<int> set1;
    for (int a : nums) {
        set1.insert(a);
    }

    return min(set1.size(), nums.size() / 2);

}