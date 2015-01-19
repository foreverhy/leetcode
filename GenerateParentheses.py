
class Solution:

    ans = []
    n = 0

    def dfs(self, s, lp, rp, ch, leftopen):
        if lp > self.n or rp > self.n:
            return
        s += ch
        if ch == '(':
            lp += 1
            leftopen += 1
        else:
            rp += 1
            leftopen -= 1
        if leftopen < 0:
            return
        if lp == rp and lp == self.n and leftopen == 0:
            self.ans.append(s)
            return
        self.dfs(s, lp, rp, '(', leftopen)
        self.dfs(s, lp, rp, ')', leftopen)

    # @param an integer
    # @return a list of strings
    def generateParenthesis(self, n):
        self.ans = []
        self.n = n
        self.dfs("", 0, 0, '(', 0)
        return self.ans
