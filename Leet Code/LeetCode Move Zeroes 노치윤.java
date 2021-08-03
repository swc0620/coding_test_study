class Solution {
    public void moveZeroes(int[] nums) {
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]==0){
                int check=0;
                for(int j=i+1;j<nums.length;j++){
                    if(nums[j]!=0){
                        nums[i]=nums[j];
                        nums[j]=0;
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    break;
                }
            }
        }
    }
}