import java.util.Arrays;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        String[] newStrs=new String[strs.length];
        for(int i=0;i<strs.length;i++){
            String STR = strs[i]; 
            char[] StringtoChar = STR.toCharArray();
            Arrays.sort(StringtoChar);
            String SortedString = new String(StringtoChar);
            newStrs[i]=SortedString+" "+String.valueOf(i);         
        }//string들을 sort해서 string + " " +index를 newStrs에 저장
        Arrays.sort(newStrs);
        List<List<String>> answer=new ArrayList<>();
        List<String> temp=new ArrayList<>();
        int prev_idx=0;
        for(int i=0;i<newStrs.length;i++){
            int idx=0;//숫자가 시작되는 인덱스 저장.
            for(int j=newStrs[i].length()-1;j>=0;j--){
                if(newStrs[i].charAt(j)>='0'&&newStrs[i].charAt(j)<='9'){
                    idx=j;
                }
                else break;
            }
            if(temp.isEmpty()) temp.add(strs[Integer.parseInt(newStrs[i].substring(idx))]);
            else{
                
                if(idx==0||newStrs[i].substring(0,idx).equals(newStrs[i-1].substring(0,prev_idx))){
                    temp.add(strs[Integer.parseInt(newStrs[i].substring(idx))]);
                }
                else{
                    answer.add(temp);
                    temp=new ArrayList<>();
                    temp.add(strs[Integer.parseInt(newStrs[i].substring(idx))]);
                }
            }
            prev_idx=idx;
        }
        answer.add(temp);
        return answer;
        
    }
}