class Solution {
    public void nextPermutation(int[] nums) {
        int idx=-1;//처음으로 자기 자신이 바로 다음 인덱스의 숫자보다 작아지는 인덱스
        for(int i=nums.length-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1){//-1이라면 내림차순으로 정렬된것.
            nums=reverse(nums, 0);
        }
        else{
            for(int i=nums.length-1;i>=idx+1;i--){
                if(nums[i]>nums[idx]){//nums[idx]바로 다음으로 큰 숫자와 swap
                    int temp=nums[i];
                    nums[i]=nums[idx];
                    nums[idx]=temp;
                    break;
                }
            }
            nums=reverse(nums, idx+1);//idx 뒷부분 리버스
 
        }        
    }
    public int[] reverse(int[] nums, int idx){//idx부터 끝까지 reverse시키는 함수
        int left=idx;
        int right=nums.length-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++; right--;
        }
        return nums;
    }
}