#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int numDecodings(const string &s){
        if (s.empty())return 0;
        vector<int> dp(s.length() + 10, 0);
        dp[0] = 1;
        for (size_t ii = 0; ii < s.length(); ++ii){
            int i = ii + 1;
            dp[i] = dp[i - 1];
            if ('0' == s[ii]){
                dp[i] = 0;
            }
            if (i > 1 && (s[ii - 1] == '1' || (s[ii - 1] == '2' && s[ii] <= '6'))){
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
};



int main(){
    Solution slu;

    string s;
    while(cin >> s){
        cout << slu.numDecodings(s) << endl;
    }


    return 0;
}


