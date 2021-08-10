import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max=0;
        if(s.length()==0) return max;
        if(s.length()==1) return 1;
        
        for(int i=0;i<s.length()-1;i++){
            Set<Character> set=new HashSet<Character>();
            set.add(s.charAt(i));
            for(int j=i+1;j<s.length();j++){
                set.add(s.charAt(j));
                if(set.size()!=j-i+1){//set에는 동일한 원소는 들어가지 않으므로 add를 했는데 예상되는 크기보다 작다면 동일한 원소가 있다는 것.
                    if(max<j-i) max=j-i;
                    break;
                }
                if(j==s.length()-1){ //j가 맨 끝에 도달한 경우는 max와 substring길이를 비교해서 넣어주면 됨.
                    if(max<j-i+1) max=j-i+1;
                }
            }
            
        }
        return max;
    }
}