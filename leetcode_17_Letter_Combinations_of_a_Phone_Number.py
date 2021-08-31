class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone_digits = {'1': '', '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz', '0': ' '}
        if digits:
            combs = ['']
        else:
            combs = []
        for digit in digits:
            curr_comb = []
            for char in phone_digits[digit]:
                for comb in combs:
                    curr_comb.append(comb + char)
            combs = curr_comb
        return combs