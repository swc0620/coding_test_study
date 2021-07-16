class Solution {
    public boolean isValid(String s) {
        HashMap<Character,Character> pair = new HashMap<>();
        pair.put(')','('); pair.put('}','{'); pair.put(']','[');
        Stack<Character> stack = new Stack<>();
        
        for (int i=0; i<s.length(); ++i) {
            char c = s.charAt(i);
            
            // opening bracket
            if (pair.containsValue(c)) {
                stack.push(c);
                continue;
            }
            
            // no opening bracket
            if (stack.isEmpty()) 
                return false;
            
            // closing bracket
            char opening = stack.pop();
            if (opening != pair.get(c))
                return false;
        }
        return stack.isEmpty();
    }
}