class Solution {
    public int search(int[] nums, int target){
        int result = 0;
        int start = 0;
        int mid = 0;
        int end = nums.length - 1;       
        int idx = 0;    
        int val = nums[0];

        while(start <= end){
            mid = (start + end) / 2;
            
            if(val <= nums[mid]){
                idx = mid;
                start = mid + 1; 
            }else{
                end = mid - 1;
            }
        }
        if(nums[0] <= target && target <= nums[idx]){
            start = 0;
            end = idx + 1;
            result = -1;
            
            while(start <= end){
                mid = (start + end) / 2;
                
                if(nums[mid] < target){
                    start = mid + 1;
                }else if(nums[mid] > target){
                    end = mid - 1;
                }else{
                    result = mid;
                    break;
                }
            }
            
        }else if(idx < nums.length - 1 && nums[idx + 1] <= target && target <= nums[nums.length - 1]){
            start = idx + 1;
            end = nums.length - 1;
            result = -1;
            
            while(start <= end){
                mid = (start + end) / 2;
                
                if(nums[mid] < target){
                    start = mid + 1;
                }else if(nums[mid] > target){
                    end = mid - 1;
                }else{
                    result = mid;
                    break;
                }    
            }
        }else result = -1;  
        return result;
    }
}
