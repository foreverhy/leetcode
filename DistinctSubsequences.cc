#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int numDistinct(string &s, string &t){
        int lens = s.length(), lent = t.length();
        
        if (!lens || !lent || lent > lens){
            return 0;
        }

        int dp[lens + 5][lent + 5];

        std::memset(dp, 0, sizeof dp);
        
        dp[0][0] = s[0] == t[0];


        for (int i = 1; i < lens; ++i){
            dp[i][0] = dp[i - 1][0] + ( (s[i] == t[0]) ? 1 : 0);
            for (int j = 1; j < lent; ++j){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += (s[i] == t[j]) ? dp[i - 1][j - 1] : 0;
            }
        }
        return dp[lens - 1][lent - 1];
    }
};



int main(){
    Solution slu;

    string s, t;
    while (cin >> s >> t){
        cout << slu.numDistinct(s, t) << endl;
    }


    return 0;
}


