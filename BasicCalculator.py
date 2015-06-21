
OPS = {
    '+' : lambda x, y: x + y,
    '-' : lambda x, y: x - y,
    '*' : lambda x, y: x * y,
    '/' : lambda x, y: x / y,
}

PRI = {
    '+' : 1,
    '-' : 1,
    '*' : 3,
    '/' : 3,
    '(' : 4,
}


def higher(op1, op2):
    if op2 == '(' or op2 == ')':
        return True
    if op1 == '(':
        return False
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
                if item == ')':
                    while self.ost[-1] != '(':
                        self.cal()
                    self.ost.pop()
                elif item == '(':
                    self.ost.append(item)
                elif self.ost and not higher(item, self.ost[-1]):
                    self.cal()
                    self.ost.append(item)
                else:
                    self.ost.append(item)
        while self.ost:
            self.cal()
        return self.nst[0]

if __name__ == '__main__':
    slu = Solution()
    print slu.calculate("(1+(4 + 5 + 2)-3)+(6+8)")
    print slu.calculate("1+(1+2)+3")
