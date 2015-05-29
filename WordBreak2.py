

dp = None

S = None
ls = None
WD = None

class Solution:

    # @return [[...],[...]] 
    def solve(self, idx):
        if idx >= ls:
            return None
        if None != dp[idx]:
            return dp[idx]
        # ans = [[],]
        ans = []
        for k in xrange(idx + 1, ls + 1):
            base = S[idx : k]
            #print 'BASE', base
            tmp = [] 
            if base in WD:
                tmp.append(base)
            else:
                continue
            more = self.solve(k)
            #print 'MORE', more
            if more or None == more:
                if more:
                    for item in more:
                        ans.append(tmp + item)
                else:
                    ans.append(tmp)
        #print 'ANS', ans
        dp[idx] = ans
        return dp[idx]

    
    def wordBreak(self, s, wordDict):
        global S, ls, WD, dp
        S = s
        ls = len(S)
        WD = wordDict
        dp = [None] * (ls + 10)

        ans = self.solve(0)
        ans = map(lambda x: " ".join(x), ans)
        return ans

if __name__ == '__main__':

    slu = Solution()
    s = "catsanddog"
    wd = {'cat', 'cats', 'and', 'sand', 'dog'}

    s = "a"
    wd = {"a"}

    s = "aaaaaaa"
    wd = {'aaaa', 'aa', 'a'}

    ans = slu.wordBreak(s, wd)
    for item in ans:
        print repr(item)


