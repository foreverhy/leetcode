#include <cstring>
#include <algorithm>
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        auto m = grid.size(), n = grid[0].size();
        int s[m+2][n+2];
        std::memset(s, 0x3f3f3f3f, sizeof s);
        s[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-1; i >=0; --i){
            for(int j = n-1; j >= 0; --j){
                if(i == m-1 && j == n-1)continue;
                s[i][j] = grid[i][j] + std::min(s[i+1][j], s[i][j+1]);
            }
        }
        return s[0][0];
    }
};
