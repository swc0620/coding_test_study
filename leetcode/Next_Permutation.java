class Solution {
  public void nextPermutation(int[] nums) {
      if (nums.length == 1)
          return;
      int i = nums.length - 2; // start examining from the end
      while (i >= 0 && nums[i] >= nums[i+1]) i--; // find first index that breaks descending order ex) i == 1 in [1, 2, 3]
      
      if (i >= 0) { // if i == 0, it is in complete descending order
          int j = nums.length - 1;
          while (nums[i] >= nums[j]) j--; // find first index that has larger number
          swap(nums, i, j);
      }
      reverse(nums, i + 1, nums.length - 1); // reverse the descending sequence       
      
  }
  
  private void swap(int[] A, int i, int j) {
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
  }
  
  private void reverse(int[] A, int begin, int end) {
      while (begin < end)
          swap(A, begin++, end--);
  }
}