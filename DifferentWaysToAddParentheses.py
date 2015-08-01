
import re

OPS = {
    '+': lambda x, y: x + y,
    '-': lambda x, y: x - y,
    '*': lambda x, y: x * y,
}

dp = None

lst = None

class Solution(object):
    

    def solve(self, left, right):
        global dp
        if dp[left][right] != None:
            return dp[left][right]
        if left == right:
            dp[left][right] = [int(lst[left])]
            return dp[left][right]
        ret = []
        for i in xrange(left + 1, right, 2):
            op = OPS[lst[i]]
            lret = self.solve(left, i - 1)
            rret = self.solve(i + 1, right)
            for x in lret:
                for y in rret:
                    ret.append(op(x, y))
        dp[left][right] = ret
        return ret 


    def diffWaysToCompute(self, arg):
        global lst, dp
        lst = filter(lambda x: x != " ", re.findall(r"\D|\d+", arg))
        dp = [[None] * len(lst) for i in xrange(len(lst))]
        return self.solve(0, len(lst) - 1)


