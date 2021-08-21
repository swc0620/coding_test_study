class Solution {
    public List<List<Integer>> combinationSum(int[] num, int target) {
       List<List<Integer>> list= new ArrayList();
       List<Integer> templist= new ArrayList();
       int remain=target;
       int start=0;
       backtrack(list,templist,num,remain,start);
       return list;
    }  
    public void backtrack(List<List<Integer>> list,List<Integer> templist,int[] num,int remain,int start){
        if(remain<0) return;
        else if(remain==0){
            list.add(new ArrayList<>(templist));
        }
        else{
            for(int i=start;i<num.length;i++){
                templist.add(num[i]);
                backtrack(list, templist, num, remain - num[i], i); // not i + 1 because we can reuse same elements
                templist.remove(templist.size() - 1);
            }
        }
    }
    
}
