#include "leet.h"


#include <stdio.h>


#include <algorithm>
#include <cstring>

class Solution{
  public:
    int strStr(string txt, string pat) {
        int lent = txt.length();
        int lenp = pat.length();
        int fail[lenp + 2];
        fail[0] = -1;
        for (int i = 1; i < lenp; ++i) {
            int k = fail[i - 1];
            for (k = fail[i - 1]; k >=0 && pat[k + 1] != pat[i]; k = fail[k]);
            fail[i] = (pat[k + 1] == pat[i]) ? (k + 1) : -1;
        }

        int i, k;
        for (i = 0, k = 0; i < lent && k < lenp;) {
            if (txt[i] == pat[k]) {
                ++i; ++k;
            } else if (0 == k){
                ++i;
            } else {
                k = fail[k - 1] + 1;
            }
        }
        if (k >= lenp) {
            return i - k;
        } else {
            return -1;
        }

    }
};



int main(){
    Solution slu;

    string s, t;
    while (cin >> s >> t) {
        cout << slu.strStr(s, t) << endl;
    }


    return 0;
}


