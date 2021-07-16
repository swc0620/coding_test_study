class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {')':'(', ']':'[', '}':'{'}
        stack = []
        
        for char in s:
            if char not in mapping: # (, [, {
                stack.append(char)
            else:
                if not stack: # 처음에 ), ], } 가 들어온 경우
                    return False

                tmp = stack.pop()
                if mapping[char] != tmp:
                    return False

        if stack: # 스택이 남아있는 경우
            return False
        return True
