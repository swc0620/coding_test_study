import java.util.Arrays;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        boolean[] visited=new boolean[nums.length];
        List<List<Integer>> a=new ArrayList<>();
        ArrayList<Integer> temp=new ArrayList<>();
        perm(nums, visited, a, temp, 0);
        return a;
        
    }
    public void perm(int[] nums, boolean[] visited, List<List<Integer>> a, ArrayList<Integer> temp, int n){
        if(n==nums.length){
            //a.add(temp);
            a.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(!visited[i]){
                temp.add(nums[i]);
                visited[i]=true;
                perm(nums, visited, a, temp, n+1);
                visited[i]=false;
                temp.remove(temp.size()-1);
            }          
        }
        
    }
}