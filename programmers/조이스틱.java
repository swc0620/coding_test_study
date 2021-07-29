class Solution {
    public int solution(String name) {
        int answer = 0;
        char[] namearr= name.toCharArray();
        for(int i=0;i<namearr.length;i++){
            if(namearr[i]=='A') continue;
            if(namearr[i]<'N') answer+=(namearr[i]-'A');
            else{
            answer+=('Z'-namearr[i]+1);
            }
            if(i!=namearr.length-1){
                answer++;
            }
        }
        return answer;
    }
}
