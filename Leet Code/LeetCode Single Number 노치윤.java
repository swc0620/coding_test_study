import java.util.Arrays;

class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int idx=0;
        while(idx<nums.length-1){
            System.out.println("HI");
            if(nums[idx]==nums[idx+1]) idx+=2;
            else break;
        }
        return nums[idx];
    }
}