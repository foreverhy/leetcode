#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int maximalSquare(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int dp[rows + 1][cols + 1];
        std::memset(dp, 0, sizeof dp);
        int ret = 0;
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = (matrix[i][0] == '0') ? 0 : 1;
            ret = std::max(ret, dp[i][0]);
        }
        for (int i = 0; i < cols; ++i) {
            dp[0][i] = (matrix[0][i] == '0') ? 0 : 1;
            ret = std::max(ret, dp[0][i]);
        }
        for (int x = 1; x < rows; ++x) {
            for (int y = 1; y < cols; ++y) {
                if (matrix[x][y] == '1') {
                    dp[x][y] = 1 + std::min(dp[x - 1][y - 1], std::min(dp[x - 1][y], dp[x][y - 1]));
                    //cout << x << ", " << y << ":  " << dp[x][y] << endl;
                    ret = std::max(ret, dp[x][y]);
                }
            }
        }

        return ret * ret;
    }
};



int main(){
    Solution slu;

    vector<vector<char> > a {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    vector<vector<char> > b {
        {'0', '1'},
    };

    vector<vector<char> > c {
        {'1','1','1','1'},
        {'1','1','1','1'},
        {'1','1','1','1'},
    };

    cout << slu.maximalSquare(a) << endl;
    cout << slu.maximalSquare(b) << endl;
    cout << slu.maximalSquare(c) << endl;

    return 0;
}


