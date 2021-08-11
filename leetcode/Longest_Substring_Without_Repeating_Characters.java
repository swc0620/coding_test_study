class Solution {
  public int lengthOfLongestSubstring(String s) {
      int answer = 0;
      Map<Character,Integer> charMap = new HashMap<>(); // char and its index
      
      for (int i=0, start=0; i<s.length; ++i) {
          char c = s.charAt(i);
          if (charMap.containsKey(c))
              start = Math.max(charMap.get(c)+1, start);
          answer = Math.max(answer, i-start+1); // length of substr
          charMap.put(c, i);
      }
      
      return answer;
  }
}