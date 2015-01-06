
D = {
    "1": None,
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
    "0": " ",
}


class Solution:
    ans = []
    digits = None

    def dfs(self, buff, idx):
        if idx >= len(self.digits):
            self.ans.append(buff)
            return
        for c in D[self.digits[idx]]:
            self.dfs(buff + c, idx + 1)


    # @return a list of strings
    def letterCombinations(self, digits):
        self.ans = []
        self.digits = digits
        self.dfs("", 0)
        return self.ans

