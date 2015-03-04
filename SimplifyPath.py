class Solution:
    def simplifyPath(self, path):
        st = []
        #if path.startswith('/'):
            #st.append('/')
        args = path.split('/')
        for p in args:
            if not p:
                continue
            if p == '.':
                continue
            if p == '..':
                if st:
                    st.pop()
                continue
            st.append(p)
             
        ans = "/".join(st)
        return "/" + ans

