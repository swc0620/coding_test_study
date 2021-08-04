class Solution {
    public int[] countBits(int n) {
        int [] result=new int[n+1];
        if(n==0){
            result[0]=0;
            return result;
        }
        result[0]=0;
        result[1]=1;
        for(int i=2;i<=n;i++){//bottom-up 방식으로 구현.
            if(i%2==0){
                result[i]=result[i/2];
            }
            else{
                result[i]=result[i/2]+1;
            }
        }
        return result;
    }
}