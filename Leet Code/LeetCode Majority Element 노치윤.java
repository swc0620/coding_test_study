import java.util.Arrays;

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        int idx=0;
        for(int i=0;i<nums.length;i++){
            if(i!=0&&nums[i]!=nums[i-1]){
                if(i-idx>nums.length/2) return nums[i-1];
                idx=i;
            }
            
        }
        return nums[nums.length-1];//majority한게 가장 큰 원소인 경우.
    }
}