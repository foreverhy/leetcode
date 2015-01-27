
class Solution:
    
    def conv(self, s):
        start = 0
        last = s[0]
        ans = ""
        for i in xrange(len(s)):
            if s[i] != last:
                ans += str(i-start) + last
                start = i
            last = s[i]
        ans += str(len(s) - start) + last
        return ans
    # @return a string
    def countAndSay(self, n):
        ans = "1"
        i = 1
        while i < n:
            ans = self.conv(ans)
            i += 1
        return ans

            

