class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = {}
        
        start = max_len = 0
        
        for idx, char in enumerate(s):
            if char in used.keys() and start <= used[char]:
                start = used[char] + 1
            else:
                max_len = max(max_len, idx - start + 1)
            used[char] = idx
        
        return max_len

# print(lengthOfLongestSubstring(input()))