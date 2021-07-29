class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxHere = 0;
        int maxSoFar = nums[0];
        
        if(nums.size() == 1)
            return nums[0];
        
        for(int i=0; i<nums.size(); i++){
            maxHere += nums[i];
            maxSoFar = max(maxSoFar, maxHere);
            maxHere = max(maxHere, 0);
        }
        return maxSoFar;
    }
};

/*
class Solution {
    public int maxSubArray(int[] nums) {
        int maxAnswer = 0;
        int answer = 0;
        int maxNumber = -2147483648;
        
        if(nums.length == 1){
            return nums[0];
        }
        
        
        for(int i = 0 ; i < nums.length ; i++){
            int num = nums[i];
            if(maxNumber < num) maxNumber = num;

            if(answer + num < 0){
                answer = 0;
            }
            else{
                answer = answer + num;
                if(maxAnswer < answer){
                    maxAnswer = answer;
                }
            }
        }
        
        if(maxAnswer == 0){
            return maxNumber;
        }
        
        return maxAnswer;   
    }
}
*/