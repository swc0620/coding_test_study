class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for idx in range(len(s)):
            res = max(self.helper(s,idx,idx), self.helper(s,idx,idx+1), res, key=len)
        return res
       
    def helper(self, s, left, right):
        while left >= 0 and right < len(s) and s[left]==s[right]:
                left -= 1
                right += 1
        return s[left+1:right]