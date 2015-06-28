def divide(x, y):
    sign = 1
    if x * y < 0:
        sign = -1
    ret = abs(x) / abs(y)
    return sign * ret

OPS = {
    '+' : lambda x, y: x + y,
    '-' : lambda x, y: x - y,
    '*' : lambda x, y: x * y,
    #'/' : divide,
    '/' : lambda x, y: x / y,
}

PRI = {
    '+' : 1,
    '-' : 1,
    '*' : 3,
    '/' : 3,
}


def higher(op1, op2):
    return PRI[op1] > PRI[op2]

import re

class Solution:

    def cal(self):
        op = self.ost[-1]
        self.ost.pop()
        result = OPS[op](self.nst[-2], self.nst[-1])
        self.nst.pop();
        self.nst.pop();
        self.nst.append(result)

    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        lst = filter(lambda x : x != " ", re.findall(r"\D|\d+", s))
        self.nst = []
        self.ost = []
        for item in lst:
            if item.isdigit():
                self.nst.append(int(item))
            else:
                while True:
                    if self.ost and not higher(item, self.ost[-1]):
                        self.cal()
                    else:
                        self.ost.append(item)
                        break
        while self.ost:
            self.cal()
        return self.nst[0]


if __name__ == '__main__':
    slu = Solution()
    print slu.calculate("1*2-3/4+5*6-7*8+9/10")
    print slu.calculate("1 + 1")
   

