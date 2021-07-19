
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {//인덱스가 0일때 0,01,012,~~ 1일때 1,12,123,~~~다 비교 해서 max 리턴
            int sum = nums[i];
            if (sum > max) max = sum;
            for (int j = i + 1; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }
};