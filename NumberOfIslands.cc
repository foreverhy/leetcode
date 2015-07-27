#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>


int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

class Solution{
  public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        bool vst[m + 2][n + 2];
        std::memset(vst, false, sizeof vst);

        int ret = 0;

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                auto ch = grid[x][y];
                if ('0' == ch || vst[x][y]) {
                    continue;
                }
                ++ret;
                std::queue<std::pair<int, int> > q;
                vst[x][y] = true;
                q.push({x, y});
                while (!q.empty()) {
                    auto now = q.front();
                    q.pop();
                    auto x_ = now.first;
                    auto y_ = now.second;
                    for (int i = 0; i < 4; ++i) {
                        auto nx = x_ + dx[i];
                        auto ny = y_ + dy[i];
                        if (nx >=0 && nx < m && ny >=0 && ny < n && !vst[nx][ny] && '1' == grid[nx][ny]) {
                            q.push({nx, ny});
                            vst[nx][ny] = true;
                        }
                    }

                }

            }
        }


        return ret;
    }
};



int main(){
    Solution slu;

    vector<vector<char>> a {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };

    cout << slu.numIslands(a) << endl;


    return 0;
}


