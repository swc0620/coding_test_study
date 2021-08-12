class Solution {
  public int maxArea(int[] height) {
      int begin = 0;
      int end = height.length - 1;
      
      int water = 0;
      while (begin < end) {
          water = Math.max(water, (end-begin) * Math.min(height[begin], height[end])); // even after moving pointers, the max area will be maintained
          if (height[begin] < height[end]) // moving the pointer with smaller height gives a better chance of reaching a bigger height
              begin++;
          else
              end--;
      }
      
      return water;
  }
}