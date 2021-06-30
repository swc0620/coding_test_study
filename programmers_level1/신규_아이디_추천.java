class Solution {
    
    public String solution(String new_id) {
        // 1단계: 소문자화
        String answer = new_id.toLowerCase();
        
        // 2단계: 부적격 문자 제거
        answer = answer.replaceAll("[^a-z0-9-_.]", "");
        
        // 3단계: 연속 마침표 하나로 치환
        answer = answer.replaceAll("[.]{2,}", ".");
        
        // 4단계: 처음또는 끝 마침표 제거
        answer = answer.replaceAll("^[.]|[.]$", "");
        
        // 5단계: 빈 문자열이면 a 대입
        if (answer.isEmpty())
            answer = "a";
        
        // 6단계: 길이 16자 이상이면 초과 문자 제거, 끝 마침표 제거
        if (answer.length() > 15) {
            answer = answer.substring(0,15);
            answer = answer.replaceAll("[.]$", "");
        }
        
        // 7단계: 길이 2자 이하이면 마지막 문자 반복 추가
        if (answer.length() < 3) {
            while (answer.length() != 3) {
                answer += answer.charAt(answer.length()-1);
            }
        }
        
        return answer;
    }
}