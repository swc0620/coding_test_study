class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
    
        for (int i=0; i<nums.size()-1; i++){
            for (int j=1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target && i != j){
                    answer.push_back(i);
                    answer.push_back(j);
                    if (answer.size() == 2){
                        return answer;
                    }
                }
            }
        }
        return answer;
    }
};