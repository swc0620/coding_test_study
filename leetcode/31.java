class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        Stack stack = new Stack();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='(') {
                stack.push(i);
            }
            else if(s.charAt(i)==')'){
                if(stack.isEmpty()){
                    stack.push(i);
                }
                else{
                    if(s.charAt((int)stack.peek())=='('){
                        stack.pop();
                    }
                    else{
                        stack.push(i);
                    }
                }
            }
        }
        int mx=0;
        if(stack.empty()) return n;
        else {
            int a = n, b = 0;
            while (!stack.empty()) {
                b = (int)stack.pop();
                mx = Math.max(mx, a-b-1);
                a = b;
            }
            mx = Math.max(mx, a);
        }
        return mx;
    }
}
