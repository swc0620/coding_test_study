class Solution {
    
    public List<String> letterCombinations(String digits) {
        LinkedList<String> res = new LinkedList<String>();
        if(digits.isEmpty()) return res;
        String[] mapping={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.add("");
        for(int i=0;i<digits.length();i++){
            int num=Character.getNumericValue(digits.charAt(i));
            while(res.peek().length()==i){ 
                String h=res.poll();
                for(char s : mapping[num].toCharArray())
					res.add(h+s);
            }
        }
        return res;
    }
}17.ㅓㄴ
