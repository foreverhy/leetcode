#include "leet.h"




#include <algorithm>
#include <cstring>
#include <bitset>

unsigned cnt[1097152];
class Solution{
  public:
    void add(std::bitset<20> &state, char nucleotide) {
        unsigned mask = 0;
        switch (nucleotide) {
            case 'A': mask = 0; break;
            case 'C': mask = 1; break;
            case 'G': mask = 2; break;
            case 'T': mask = 3; break;
            default: exit(-1);
        }
        state |= mask;
    }
    void transfer(std::bitset<20> &state, char nucleotide) {
        state.reset(19);
        state.reset(18);
        state <<= 2;
        add(state, nucleotide); 
    }
    vector<string> findRepeatedDnaSequences(string s) {
        std::memset(cnt, 0, sizeof cnt);
        vector<string> ans;
        unsigned len = s.length();
        std::bitset<20> state;
        for (unsigned i = 0; i < len; ++i) {
            transfer(state, s[i]);
            if (i >= 9) {
                ++cnt[state.to_ulong()];
                if (2 == cnt[state.to_ulong()]) {
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


