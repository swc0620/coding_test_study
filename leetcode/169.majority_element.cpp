class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto n:nums){
            count[n] += 1;
            if (count[n] > nums.size()/2){
                return n;
            }
        }
        return 0;
    }
};