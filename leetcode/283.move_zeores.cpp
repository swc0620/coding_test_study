class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        vector<int> temp;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != 0){
                temp.push_back(nums[i]);
            }
            else{
                count += 1;
            }
        }
        for (int j=0; j<count; j++){
            temp.push_back(0);
        }
        nums = temp;
    }
};