class Solution {
    public int maxArea(int[] height) {
        int max=0;
        int left=0;
        int right=height.length-1;
        while(left<right){
            max=(max>Math.min(height[left], height[right])*(right-left)) ? max :  Math.min(height[left], height[right])*(right-left);
            if(height[left]>height[right]){
                right--;
            }
            else if(height[left]<height[right]){
                left++;
            }
            else{
                if(height[left+1]>height[right-1]){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return max;
    }
}