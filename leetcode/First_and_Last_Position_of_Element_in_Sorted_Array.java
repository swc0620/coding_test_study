class Solution {
  int[] range;
  
  public int[] searchRange(int[] nums, int target) {
      range = new int[]{ nums.length, -1 };
      
      findRange(nums, target, 0, nums.length - 1);
      
      if (range[0] > range[1])
          range[0] = -1;
      
      return range;
  }
  
  private void findRange(int[] nums, int target, int low, int high) {
      if (low > high)
          return;
      
      int mid = low + (high - low) / 2;
      
      if (nums[mid] < target) {
          findRange(nums, target, mid + 1, high);
      } else if (target < nums[mid]) {
          findRange(nums, target, low, mid - 1);
      } else {
          if (mid < range[0]) { // has more before lowest bound
              range[0] = mid;
              findRange(nums, target, low, mid - 1);
          }
          if (range[1] < mid) { // has more after highest bound
              range[1] = mid;
              findRange(nums, target, mid + 1, high);
          }
      }
  }
}