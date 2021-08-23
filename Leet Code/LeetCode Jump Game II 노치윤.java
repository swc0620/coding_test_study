class Solution {
    public int jump(int[] nums) {
        int jump=0;
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        for(int i=0;i<nums.length-1;i++){
            ArrayList<Integer> temp=new ArrayList<>();
            boolean check=false;
            for(int j=i+1;j<=i+nums[i];j++){
                temp.add(j);
                if(j==nums.length-1){//i번째 인덱스에서 마지막 인덱스에 도달할 수 있다.
                    jump++;
                    check=true;
                    break;
                }
            }
            if(check) break;
            arr.add(temp);
        }
        int idx=arr.size();
        while(true){
            for(int k=0;k<=idx-1;k++){
                if(arr.get(k).contains(idx)){//0번 인덱스부터~ idx-1번 인덱스까지중 idx에 도달할 수 있는 최소 인덱스를 찾는다. (arr.get(k) 리스트에는 k번째 인덱스에서 갈 수 있는 인덱스들이 저장되어 있음)
                    idx=k;
                    jump++;
                    break;
                }
            }
            if(idx==0) break;
        }
        return jump;
    }
}