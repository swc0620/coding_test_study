class Solution {
  List<List<Integer>> answer;
  boolean[] used;
  
  public List<List<Integer>> permute(int[] nums) {
      answer = new ArrayList<>();
      used = new boolean[nums.length];
      
      if (nums == null || nums.length == 0)
          return answer;
      
      permuteHelper(nums, new ArrayList<>());
      return answer;
  }
  
  private void permuteHelper(int[] nums, List<Integer> curr) {
      if (curr.size() == nums.length) {
          answer.add(new ArrayList<>(curr));
          return;
      }
      
      for (int i=0; i<nums.length; ++i) {
          if (used[i])
              continue;
          
          curr.add(nums[i]);
          used[i] = true;
          
          permuteHelper(nums, curr);
          
          used[i] = false; // after returned, we can make new permutation
          curr.remove(curr.size() - 1);
      }
  }
}