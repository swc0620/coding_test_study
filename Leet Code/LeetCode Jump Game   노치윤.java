class Solution {
    public boolean canJump(int[] nums) {
        int max=nums[0];
        int idx=1;
        while(idx<=max&&idx<nums.length){//max보다 idx 가 커졌다 ? -> 도달 불가.
            if(idx+nums[idx]>max) max=idx+nums[idx];
            idx++;
        }
        if(max>=nums.length-1) return true;
        else return false;
    }

}