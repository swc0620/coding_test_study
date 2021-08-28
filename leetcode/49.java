class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,ArrayList<String>> map = new HashMap<>();
        for(String s:strs){
            char[] keychar = s.toCharArray();
            Arrays.sort(keychar);
            String key = String.valueOf(keychar);
            if(!map.containsKey(key)) map.put(key,new ArrayList<>());
            map.get(key).add(s);
        }
        return new ArrayList<>(map.values());
    }  
}
