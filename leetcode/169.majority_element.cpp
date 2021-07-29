class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        int temp=0;
        for(auto n:nums){
            if(!temp)
                ans=n;
            if(n==ans)
                temp++;
            else
                temp--;
        }
        return ans;
    }
};