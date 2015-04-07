
class Solution:

    def valid(self, s):
        if not s:
            return False
        if s[0] == '0' and len(s)==1:
            return True
        if s[0] == '0':
            return False
        if 0 <= int(s) <= 255:
            return True

    def simple(self, s):
        return str(int(s))

    def deal(self, s_lst):
        s_lst = map(self.simple, s_lst)



    def dfs(self, s, place, dotcnt):
        if dotcnt == 3:
            if self.valid(s[place[-1]:]):
                tmp = [s[place[0]:place[1]],s[place[1]:place[2]],s[place[2]:place[3]],s[place[3]:]]
                tmp = map(self.simple, tmp)
                tmp = ".".join(tmp)
                if tmp not in self.plist:
                    self.plist.append(tmp)
                # get a solution
            return
        st = place[-1]
        for ls in xrange(1, 4):
            ed = st + ls
            if self.valid(s[st:ed]):
                place.append(ed)
                self.dfs(s, place,dotcnt+1)
                place.pop()



    # @param s, a string
    # @return a list of strings
    def restoreIpAddresses(self, s):
        self.plist = []
        self.dfs(s, [0],0)
        return self.plist
