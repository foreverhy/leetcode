#include "leet.h"




#include <algorithm>
#include <cstring>

unsigned cnt[1097152];
class Solution{
  public:
    unsigned add(unsigned state, char nucleotide) {
        unsigned mask = 0;
        switch (nucleotide) {
            case 'A': mask = 0; break;
            case 'C': mask = 1; break;
            case 'G': mask = 2; break;
            case 'T': mask = 3; break;
            default: exit(-1);
        }
        state |= mask;
        return state;
    }
    unsigned transfer(unsigned state, char nucleotide) {
        state &= ~(3u << 18);
        state <<= 2;
        return add(state, nucleotide); 
    }
    vector<string> findRepeatedDnaSequences(string s) {
        std::memset(cnt, 0, sizeof cnt);
        vector<string> ans;
        unsigned len = s.length();
        unsigned state = 0;
        for (unsigned i = 0; i < len; ++i) {
            state = transfer(state, s[i]);
            if (i >= 9) {
                ++cnt[state];
                if (2 == cnt[state]) {
                    ans.push_back(s.substr(i - 9, 10));
                }
            }
        }
        return ans;
    }
};



int main(){
    Solution slu;

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    cout << slu.findRepeatedDnaSequences(s) << endl;


    return 0;
}


