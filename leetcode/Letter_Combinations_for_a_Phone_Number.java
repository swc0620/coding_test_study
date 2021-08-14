class Solution {
  String[] tele = new String[]{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      
  public List<String> letterCombinations(String digits) {        
      List<String> answer = new ArrayList<>();
      if (digits.isEmpty())
          return answer;
      
      // problem: we cannot specify nested for loops (depends on digits.length())
      // -> do this in a recursive fashion
      backtrack(new StringBuilder(), digits, answer, 0);
      return answer;
  }
  
  // 그림 그리며 공부해보기
  public void backtrack(StringBuilder sb, String digits, List<String> answer, int index) {
      if (index == digits.length()) {
          answer.add(sb.toString()); // add "ad"
          return;
      }
      
      String letters = tele[digits.charAt(index) - '0']; // "abc" then "def"
      for (char letter: letters.toCharArray()) { // 'a' 'b' 'c' then 'd' 'e' 'f'
          backtrack(sb.append(letter), digits, answer, index + 1); // `a` -> `ad`
          sb.deleteCharAt(sb.length() - 1); // `ad -> `a`
      }
      
  }
  
  
}