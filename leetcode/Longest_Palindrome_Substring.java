class Solution {
  public String longestPalindrome(String s) {
      if (s.trim().isEmpty())
          return s;
      
      int len = s.length();
      int start = 0; 
      int maxLen = 0;
      
      for (int i = 0; i < len - maxLen/2; ++i) {
          int begin = i; int end = i; // initialize
          
          while (end < len-1 && s.charAt(end) == s.charAt(end+1)) // duplicate value with s[i], always a palindrome
              ++end;
          while (begin > 0 && end < len-1 && s.charAt(begin-1) == s.charAt(end+1)) { // check both ends
              --begin;
              ++end;
          }
          
          int newLen = end - begin + 1;
          if (maxLen < newLen) {
              maxLen = newLen;
              start = begin; // store starting point
          }
      }
      
      return s.substring(start, start + maxLen);
  }
}