class Solution {
    public int[] searchRange(int[] nums, int target) {
        int lo=0;
        int hi=nums.length-1;
        int mid=0;
        int[]arr={-1,-1};
        if(nums.length==0) return arr;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]<target){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if(lo>hi){
            return arr;
        }
        int start=0;
        int end=0;
        int m=mid;
        while(m+1<=nums.length-1 && nums[m+1]==target){
                m+=1;
        }
        while(mid-1>=0 && nums[mid-1]==target){
                mid-=1;
        }
        end=m;
        start=mid;
        arr[0]=start;
        arr[1]=end;
        return arr;
    }
}
