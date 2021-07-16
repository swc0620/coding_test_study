def solution(s):
    answer = len(s)
    for i in range(1, len(s) // 2 + 1):
        compressed = ''
        prev = s[0:i]
        count = 1
        for j in range(i, len(s), i):
            if prev == s[j:j+i]:
                count += 1
            else:
                if count >= 2:
                    compressed += str(count) + prev
                else:
                    compressed += prev
                # 다시 상태 초기화
                prev = s[j:j+i]
                count = 1
        
        # 남아 있는 문자열 처리
        if count >= 2:
            compressed += str(count) + prev
        else:
            compressed += prev
            
        answer = min(answer, len(compressed))
    return answer
