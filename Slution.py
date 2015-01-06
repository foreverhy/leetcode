
R = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

SUB = {
    "I": ("V", "X"),
    "X": ("L", "C"),
    "C": ("D", "M"),
}


class Solution:
    # @return an interger
    def romanToInt(self, s):
        ans = 0
        l = len(s)
        i = 0
        while i < l:
            if s[i] != "I" and s[i] != "X" and s[i] != "C" or i >= l - 1:
                ans += R[s[i]]
                i += 1
            elif s[i+1] in SUB[s[i]]:
                ans += R[s[i+1]] - R[s[i]]
                i += 2
            else:
                ans += R[s[i]]
                i += 1
        return ans


