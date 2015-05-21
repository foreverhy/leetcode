#include "leet.h"




#include <algorithm>
#include <cstring>

#include <queue>

using std::pair;
using std::queue;

const int MAXN = 1000;
bool vst[MAXN][MAXN];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class Solution{
  public:
    void solve(vector<vector<char> > &board){
        if (board.empty()){
            return;
        }
        std::memset(vst, false, sizeof vst);
        int lenx = board.size();
        int leny = board[0].size();
        queue<pair<int, int> > q;
        queue<pair<int, int> > tmp;
        for (int x = 0; x < lenx; ++x){
            for (int y = 0; y < leny; ++y) if (!vst[x][y] && 'O' == board[x][y]){
                vst[x][y] = true;
                q.push({x, y});
                bool is_surrounded = true;
                while (!q.empty()){
                    auto now = q.front();
                    for (int i = 0; i < 4; ++i){
                        auto nx = now.first + dx[i];
                        auto ny = now.second + dy[i];
                        if (nx < 0 || nx >= lenx || ny < 0 || ny >= leny){
                            is_surrounded = false;
                        }else if (!vst[nx][ny] && 'O' == board[nx][ny]){
                            q.push({nx, ny});
                            vst[nx][ny] = true;
                        }
                    }
                    tmp.push(now);
                    q.pop();
                }
                while (!tmp.empty()){
                    auto now = tmp.front();
                    if (is_surrounded) board[now.first][now.second] = 'X';
                    tmp.pop();
                }
            }
        }

    }
};



int main(){
    Solution slu;

    vector<vector<char> > a = {
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
    };

    slu.solve(a);
    for (auto &item : a){
        for (auto &v : item){
            cout << v ;
        }
        cout << endl;
    }


    return 0;
}


