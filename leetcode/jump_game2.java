class Solution {
    public int jump(int[] nums) {
        if(nums.length==0) return 0;
        
        int[] dp=new int[nums.length];
        Arrays.fill(dp, Integer.MAX_VALUE); // Math.min을 사용하기 위함
        dp[0]=0;
        for(int i=0;i<nums.length;i++){ // i 위치에서 다 체크
            for(int j=1;j<=nums[i] && i+j<nums.length;j++){ // 1부터 nums[i]까지 뛰어본다, 단 배열 범위 벗어나지 않는 범위내에서
                dp[i+j]=Math.min(dp[i+j], dp[i]+1); // 기존 점프 횟수와 i에서 뛴 것 중 작은 값 선택
            }
        }
        
        return dp[nums.length-1];
    }
}
