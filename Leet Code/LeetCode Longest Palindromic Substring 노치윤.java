class Solution {
    int lo;
    int max;
    public String longestPalindrome(String s) {
        if(s.length()<2) return s;
        for(int i=0;i<s.length();i++){
            makePalindromic(s, i,i);//반복 문자열이 홀수개
            makePalindromic(s,i,i+1);//반복 문자열이 짝수개
        }
        return s.substring(lo, lo + max);
        
    }
    
    private void makePalindromic(String s, int j, int k){
        while(j>=0&&k<s.length()&&s.charAt(j)==s.charAt(k)){
            j--;
            k++;
        }
        if(max<k-j-1){
            max=k-j-1;
            lo=j+1;
        }
        
    }
}