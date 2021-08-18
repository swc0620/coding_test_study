class Solution {
  public List<String> generateParenthesis(int n) {
      List<String> answer = new ArrayList<String>();
      if (n == 0)
          return answer;
      helper(answer, "", n, n);
      return answer;
  }
  
  private void helper(List<String> answer, String curr, int nOpen, int nClose) {
      if (nClose == 0) // used all closing parentheses
          answer.add(curr); // ) is always at the end of string, so basically returns at here
      if (nOpen > 0) // more to go
          helper(answer, curr + "(", nOpen - 1, nClose);
      if (nClose > nOpen)
          helper(answer, curr + ")", nOpen, nClose - 1);
  }
  
  // ((())) nOpen first reaches 0 -> no choice but to continue until nClose == 0
  // (()()) 
  // (())()
  // ()(())
  // ()()()
}