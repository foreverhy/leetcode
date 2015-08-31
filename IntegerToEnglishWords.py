Single = [
    "", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve",
]

Decades = [
    "", "", "", "Thir", "Four", "Fif", "Six",
    "Seven", "Eigh", "Nine"
]

Unit = [
    "", "Thousand", "Million", "Billion"
]

def convert(num, unit):
    '''0 <= num <= 999'''
    ret = []
    if num >= 100:
        ret.append(Single[num / 100] + " Hundred")
        num %= 100
    if num >= 20:
        left = ""
        if num / 10 == 2:
            left = "Twenty"
        elif num / 10 == 4:
            left = "Forty"
        else:
            left = Decades[num / 10] + "ty"
        right = Single[num % 10]
        ret.append(left)
        ret.append(right)
    elif num >= 13:
        ret.append(Decades[num % 10] + "teen")
    else:
        ret.append(Single[num])
    ret = filter(lambda x: x!= "", ret)
    if ret:
        ret.append(Unit[unit])
    return ret

class Solution(object):

    # @param {int}num
    # @return str
    def numberToWords(self, num):
        ret = []
        unit = 0
        while num != 0:
            ret = convert(num % 1000, unit) + ret
            num /= 1000
            unit += 1
        ret = filter(lambda x: x != "", ret)
        if not ret:
            ret = ["Zero"]
        return " ".join(ret)



import sys
slu = Solution()
for line in sys.stdin:
    line = line.strip()
    print slu.numberToWords(int(line))
