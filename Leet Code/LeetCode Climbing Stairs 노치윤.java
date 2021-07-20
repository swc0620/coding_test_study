class Solution {
    int []arr=new int[46];//값을 저장하는 배열
    public int climbStairs(int n) {
        if(n==1){
            arr[1]=1;
            return 1;
        }
        else if(n==2){
            arr[2]=2;
            return 2;
        }
        int answer=0;
        if(arr[n-1]!=0&&arr[n-2]!=0){
            answer=arr[n-1]+arr[n-2];
        }
        else if(arr[n-1]!=0){
            answer=arr[n-1]+climbStairs(n-2);
        }
        else if(arr[n-2]!=0){
            answer=climbStairs(n-1)+arr[n-2];
        }
        else{//이미 저장된 값이 없다면 재귀 수행
            answer=climbStairs(n-1)+climbStairs(n-2);
        }
        arr[n]=answer;
        return answer;
    }
}