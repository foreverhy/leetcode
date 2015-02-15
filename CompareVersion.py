class Solution:
    def compareVersion(self, version1, version2):
        a1 = version1.split('.')
        a2 = version2.split('.')
        i = 0
        while i < (min(len(a1), len(a2))):
            x = int(a1[i])
            y = int(a2[i])
            if x > y:
                return 1
            if x < y:
                return -1
            i += 1
        if i >= len(a2):
            for item in map(int, a1[i:]):
                if item > 0:
                    return 1
        if i >= len(a1):
            for item in map(int, a2[i:]):
                if item > 0:
                    return -1
        return 0


