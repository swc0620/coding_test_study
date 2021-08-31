class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        wordbook = {}
        for s in strs:
            key = tuple(sorted(s))
            wordbook[key] = wordbook.get(key, []) + [s]
        return list(wordbook.values())