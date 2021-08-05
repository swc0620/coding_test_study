class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans=new ArrayList<>();
        int idx=0;
        while(idx!=nums.length){
            /* 순서대로 자신의 인덱스에 그 값이 들어가도록 sorting을 시킬거임.
             [4,3,2,7,8,2,3,1] 인경우
             1. 4는 원래 nums[3]에 위치해야 하므로 7과 교환.
             [7,3,2,4,8,2,3,1]
             
             2. 7은 원래 nums[6]에 위치해야 하므로 3과 교환.
             [3,3,2,4,8,2,7,1]
             
             3. 3은 원래 nums[2]에 위치해야 하므로 2와 교환.
             [2,3,3,4,8,2,7,1]
             
             4. 2는 원래 nums[1]에 위치해야 하므로 3과 교환.
             [3,2,3,4,8,2,7,1]
             
             5. 3은 원래 nums[2]에 위치해야 하는데 그 자리에 이미 3이 있으므로 idx+=1
             6. idx=1 -> 2가 제대로 들어가 있으므로 idx++
             7. idx=2 -> 3이 제대로 들어가 있으모르 idx++
             8. idx=3 -> 4가 제대로 들어가 있으므로 idx++
             
             9. idx=4 -> 8는 원래 nums[7]에 위치해야 하므로 1과 교환.
             [3,2,3,4,1,2,7,8]
             
             10. 1은 원래 nums[0]에 위치해야 하므로 3과 교환.
             [1,2,3,4,3,2,7,8]
             
             11. 3은 원래 nums[2]에 위치해야 하는데 그 자리에 이미 3이 있으므로 idx+=1
             12. idx=5 -> 2은 원래 nums[1]에 위치해야 하는데 그 자리에 이미 2가 있으므로 idx+=1
             13. idx=6, 7 모두 7, 8 이 제대로 위치해 있으므로 끝.
             
             14. [1,2,3,4,3,2,7,8] 에서 자신의 인덱스에 제대로 위치하지 않은 건 3,2 이고 원래 들어가야 할 값은
             5와 6이므로 5,6 이 빠진것.
             */
            if(nums[idx]!=idx+1){
                int temp=nums[nums[idx]-1];
                if(temp==nums[idx]){
                    idx++;
                    continue;
                }
                nums[nums[idx]-1]=nums[idx];
                nums[idx]=temp;            
            }
            else{
                idx++;
            }
        }
        
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=i+1){
                ans.add(i+1);
            }
        }
        return ans;
    }
}