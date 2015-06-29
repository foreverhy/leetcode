#include "leet.h"




#include <algorithm>
#include <cstring>


class Solution{
  public:
    bool isOneEditDistance(string s, string t) {
        int lens = s.length(), lent = t.length();
        if (std::abs(lens - lent) > 1) {
            return false;
        }
        int i = 0, j = 0;
        int diff = 0;
        while (i < lens && j < lent) {
            if (lens == lent) {
                if (s[i] != t[j]) {
                    if (++diff > 1) return false; 
                }
                ++i, ++j;
            } else {
                if (s[i] == t[j]) {
                    ++i, ++j;
                } else {
                    if (++diff > 1) return false;
                    if (lens - i > lent - j) {
                        ++i;
                    } else {
                        ++j;
                    }
                }

            }
        }
        if (i < lens || j < lent) ++diff;
        return diff == 1;
    }
};



int main(){
    Solution slu;

    auto s = "teacher";
    auto t = "tacker";
    cout << slu.isOneEditDistance(s, t) << endl;
    s = "ba"; t = "a";
    cout << slu.isOneEditDistance(s, t) << endl;

    return 0;
}


