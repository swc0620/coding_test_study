class Solution {
  public int search(int[] nums, int target) {
      if (nums == null || nums.length == 0)
          return -1;
      
      int low = 0, high = nums.length - 1;
      
      while (low <= high) {
          int mid = (low + high) / 2;
          if (nums[mid] == target)
              return mid;
          
          if (nums[low] <= nums[mid]) { // pivot is in the right sub-array
              if (target >= nums[low] && target < nums[mid])
                  high = mid - 1;
              else
                  low = mid + 1;
          } else { // pivot is in the left sub-array
              if (target > nums[mid] && target <= nums[high])
                  low = mid + 1;
              else
                  high = mid - 1;
          }
      }
      
      return -1;                                   
  }
}