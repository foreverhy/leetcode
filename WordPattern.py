class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        m = {}
        str = str.split()
        if len(pattern) != len(str):
            return False
        for i in xrange(len(pattern)):
            token = pattern[i]
            word = str[i]
            if token not in m.keys() and word not in m.values():
                m[token] = word
            elif m.get(token) == word:
                pass
            else:
                return False
        return True
