#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool isIsomorphic(string s, string t) {
        size_t len = s.length();
        if (len != t.length()) {
            return false;
        }
        char map[128];
        bool vst[128];
        std::memset(map, 0, sizeof map);
        std::memset(vst, false, sizeof vst);
        for (size_t i = 0; i < len; ++i) {
            int chs = s[i];
            int cht = t[i];
            if (vst[cht]) {
                if (map[chs] != cht) {
                    return false;
                }
            } else if (map[chs]) {
                return false;
            } else {
                vst[cht] = true;
                map[chs] = cht;
            }
        }
        return true;
    }
};



int main(){
    Solution slu;

    string s, t;
    while (cin >> s >> t) {
        cout << slu.isIsomorphic(s, t) << endl;
    }


    return 0;
}


