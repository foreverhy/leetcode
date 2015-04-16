#include "leet.h"




#include <algorithm>
#include <cstring>

static const int MAXN = 1000;
static int dp[MAXN][MAXN];

class Solution{
  public:
    bool isInterleave(string &s1, string &s2, string &s3){
        if (s1.length() + s2.length() != s3.length()){
            return false;
        }
        int len1 = s1.length(), len2 = s2.length();
        //memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int j = 1; j <= len2; ++j){
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        int k;
        for (int i = 1; i <= len1; ++i){
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= len2; ++j){
                k = i + j;
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[k - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[k - 1]);
            }
        }

        return dp[len1][len2];

    }


};



int main(){
    Solution slu;

    string s1, s2, s3;
    while (cin >> s1 >> s2 >> s3){
        cout << slu.isInterleave(s1, s2, s3) << endl;
    }


    return 0;
}


