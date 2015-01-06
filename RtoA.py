
ROMAN = {
    1: ('I', "V", "X"),
    10: ('X', "L", "C"),
    100: ('C', "D", "M"),
    1000: ('M', "", ""),
}

CONVERT = {
    0: "",
    1: "a",
    2: "aa",
    3: "aaa",
    4: "ab",
    5: "b",
    6: "ba",
    7: "baa",
    8: "baaa",
    9: "ac",
}
class Solution:
    def trans(self, string, pw):
        A, B, C = ROMAN[pw]
        return string.replace('a', A).replace('b', B).replace('c', C)

    # @return a string
    def intToRoman(self, num):
        res = ""
        pw = 1
        while num != 0:
            t = num % 10 
            sym = CONVERT[t]
            res = self.trans(sym, pw) + res
            pw *= 10
            num /= 10
        return res

