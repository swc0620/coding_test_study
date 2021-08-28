class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
      Map<String, List<String>> map = new HashMap<>();
      
      for (String str : strs) {
          // identify characters in str
          char[] ch = str.toCharArray();
          Arrays.sort(ch);
          String key = String.valueOf(ch);
          
          // if specified combination of characters exists as a key, str is an anagram for the group
          if (map.containsKey(key)) {
              map.get(key).add(str);
          } else {
              List<String> val = new ArrayList<String>();
              val.add(str);
              map.put(key, val);
          }
      }
      
      return new ArrayList(map.values());
  }
}