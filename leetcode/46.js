class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        help(res,temp,nums);
        return res;
    }
    public void help(List<List<Integer>> res,List<Integer> temp,int nums[]){
        if(temp.size()==nums.length) res.add(new ArrayList<>(temp));
        else{
            for(int i=0;i<nums.length;i++){
                if(temp.contains(nums[i])) continue;
                temp.add(nums[i]);
                help(res,temp,nums);
                temp.remove(temp.size()-1);
            }
        }
    }
}
