import java.util.Arrays;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer=new ArrayList<>();
        Arrays.sort(candidates);
        combSum(candidates, answer, new ArrayList<>(), target, 0);
        return answer;
        
    }
    
    private void combSum(int[] candidates, List<List<Integer>> answer, List<Integer> temp, int remain, int idx){
        if(remain==0) answer.add(new ArrayList<>(temp));
        else if(remain<0) return;
        else{
            for(int i=idx; i<candidates.length;i++){
                temp.add(candidates[i]);
                combSum(candidates, answer, temp, remain-candidates[i], i);
                temp.remove(temp.size()-1);
            }
        }
    }
}