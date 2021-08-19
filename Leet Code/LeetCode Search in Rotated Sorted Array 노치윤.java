class Solution {
    public int search(int[] nums, int target) {
        int a=nums[0];
        int b=nums[nums.length-1];
        int len=nums.length;
        int left=0, right=len-1;
        int cen=(left+right)/2;
        while(left<right&&right-left!=1){//right-left==1 이면 무한 반복하기에 조건 추가해줌.
            cen=(left+right)/2;
            if(target>=nums[left]&&target<=nums[cen]) right=cen;
            else if(target>=nums[left]&&target>=nums[cen]&&nums[left]>nums[cen]) right=cen;//ex) target=7 left--67012--cen 인 경우
            else if(target<=nums[left]&&target<=nums[cen]&&nums[left]>nums[cen]) right=cen;//ex) target=1 left--67012--cen 인 경우
            else if(target>=nums[cen]&&target<=nums[right]) left=cen;
            else if(target>=nums[cen]&&target>=nums[right]&&nums[cen]>nums[right]) left=cen;//ex) target=7 cen--67012--right 인 경우
            else if(target<=nums[cen]&&target<=nums[right]&&nums[cen]>nums[right]) left=cen;//ex) target=1 cen--67012--right 인 경우
            else return -1;
        }
        if(left>right) return -1;
        if(nums[left]==target) return left;
        else if(nums[right]==target) return right;
        else return -1; 
    }
}