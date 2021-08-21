class Solution {
  public List<List<Integer>> combinationSum(int[] candidates, int target) {
      // sort candidates to try them in asc order
      Arrays.sort(candidates);
      // dp[i] stores all combinations that add up to i
      List<List<Integer>>[] dp = new ArrayList[target+1];
      
      for (int i=0; i<=target; ++i) {
          dp[i] = new ArrayList<>();
          List<List<Integer>> combList = new ArrayList<>();
          
          for (int j=0; j<candidates.length && candidates[j] <= i; ++j) {
              // i itself can form a list
              if (candidates[j] == i) {
                  combList.add(Arrays.asList(candidates[j]));
              } else {
                  // search for prevList that can be augmented
                  for (List<Integer> prevList : dp[i-candidates[j]]) {
                      // compare with the last element to form list with its elements in ascending order && prevent andy duplicate
                      // equal is needed since we can choose the same element more than once
                      if (candidates[j] >= prevList.get(prevList.size()-1)) { // compare last element
                          List<Integer> temp = new ArrayList(prevList); // copy prevList
                          temp.add(candidates[j]);
                          combList.add(temp);
                      }
                  }
              }
          }
          dp[i] = combList; 
      }
      
      return dp[target];
  }
}