class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for idx, paren in enumerate(s):
            if paren == '(' or paren == '{' or paren == '[':
                stack.append(paren)
            elif paren == ')':
                if not stack:
                    return False
                if stack.pop() != '(':
                    return False
            elif paren == '}':
                if not stack:
                    return False
                if stack.pop() != '{':
                    return False
            elif paren == ']':
                if not stack:
                    return False
                if stack.pop() != '[':
                    return False
        if stack:
            return False
        return True
        