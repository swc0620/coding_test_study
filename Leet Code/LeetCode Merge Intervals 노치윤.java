class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] o1, int [] o2){
                if(o1[0]!=o2[0]){
                    return o1[0]-o2[0];
                }else{
                    return o1[1]-o2[1];
                }
            }
        });
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> temp=new ArrayList<>();
        int start=intervals[0][0];
        int finish=intervals[0][1];
        for(int i=1;i<intervals.length;i++){
            if(finish<intervals[i][1]){
                if(finish<intervals[i][0]){//finish보다 첫번째 원소가 크면 추가해야함.
                    temp.add(start);
                    temp.add(finish);
                    ans.add(temp);
                    temp=new ArrayList<>();
                    start=intervals[i][0];                    
                }
                finish=intervals[i][1];
            }

        }
        temp.add(start);
        temp.add(finish);
        ans.add(temp); 
        int [][]answer=new int[ans.size()][2];
        for(int i=0;i<ans.size();i++){
            answer[i][0]=ans.get(i).get(0);
            answer[i][1]=ans.get(i).get(1);
        }
        return answer;
    }
}