class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left=0;
        int right=nums.length-1;
        int cen=(left+right)/2;
        int []ans={-1,-1};
        if(nums.length==0) return ans;
        while(left<right){
            if(nums[cen]>target) right=cen-1;
            else if(nums[cen]<target) left=cen+1;
            else left=right=cen;
            cen=(left+right)/2;
        }//binary search
        
        if(nums[cen]!=target) return ans;
        else{
            int temp=cen;
            while(temp>=0&&nums[temp]==target){//temp는 왼쪽으로 계속 이동하며 같은 값인지 체크
                temp--;
            }
            ans[0]=++temp;
            int temp2=cen;
            while(temp2<nums.length&&nums[temp2]==target){//temp2는 cen에서 오른쪽으로 계속 이동하며 같은 값인지 체크
                temp2++;
            }
            ans[1]=--temp2;
            return ans;
        }
        
    }
}