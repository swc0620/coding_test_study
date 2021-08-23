class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(p, left, right, parens=[]):
            if left > 0:
                generate(p + '(', left-1, right)
            if right > left:
                generate(p + ')', left, right-1)
            if right == 0:
                parens.append(p)
            return parens
        return generate('', n, n)