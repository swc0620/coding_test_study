class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> answer;
        int size = nums.size(); // 처음 길이 값 저장
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int temp = 1; // 비교할 숫자
        
        for (int i=0; i<nums.size(); i++){
            if (temp == nums[i]){
                temp += 1;
            }
            else{
                answer.push_back(temp);
                temp += 1;
                i -= 1; // nums[i] 다음 숫자 넘어가지 못하게 조정
            }
        }
        
        // ex) [1,1]일 때, [2] 같은 상황
        // size = 2, nums.size() = 1 (중복 숫자 제거됨)
        if (size != nums[nums.size()-1]){
            for (int i=size; i>size-nums.size(); i--){
                if (i == nums[nums.size()-1]){
                    break;
                }
                answer.push_back(i);
            }
        }
        return answer;
    }
};