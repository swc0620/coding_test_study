class Solution {
    String [][] letter={{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
    List<String> answer=new ArrayList<String>();
    String temp="";
    
    public List<String> letterCombinations(String digits) {      
        if(digits.length()==0) return answer;
        
        Recur(digits, 0);
        return answer;
        
    }
    
    public void Recur(String digits, int n){
        if(n==digits.length()) return;
        for(int i=0;i<letter[digits.charAt(n)-'0'-2].length;i++){
            temp=temp.concat(letter[digits.charAt(n)-'0'-2][i]);//temp+ new letter
            Recur(digits, n+1);
            if(temp.length()==digits.length()){
                answer.add(temp);
            }
            temp=deleteIdx(temp,n); // ex. ad, ae, af 를 만든 후에는 a대신 b로 진행해야 하므로 a 삭제
        }
    }
    
    public String deleteIdx(String a, int idx){
        String remake=a.substring(0,idx)+a.substring(idx+1);
        return remake;
    }
}