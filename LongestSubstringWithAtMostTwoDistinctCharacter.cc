#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty()) {
            return 0;
        }
        int has[130];
        int cnt = 0;
        std::memset(has, 0, sizeof has);
        int ans = 0;
        int len = s.length();
        int i = 0, j = 0;
        for (i = 0, j = 0; j < len; ++j) {
            unsigned ch = s[j];
            if (!has[ch]) {
                ++cnt;
            }
            ++has[ch];
            if (cnt > 2) {
                ans = std::max(ans, j - i);
                if (0 == --has[int(s[i])]) {
                    --cnt; 
                }
                ++i;

            }
        }
        if (cnt <= 2) {
            ans = std::max(ans, j - i);
        }
        return ans;
    }
};



int main(){
    Solution slu;

    string s;
    while (cin >> s) {
        cout << slu.lengthOfLongestSubstringTwoDistinct(s) << endl;
    }


    return 0;
}


