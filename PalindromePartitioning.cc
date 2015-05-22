#include "leet.h"




#include <algorithm>
#include <cstring>

const int MAXN = 1000;
typedef vector<vector<string> > vvs; 

int is_pal[MAXN][MAXN];
int ispal(const string &v, int first, int last){
    if (first > last){
        return 0;
    }
    if (-1 != is_pal[first][last]){
        return is_pal[first][last];
    }
    for (int i = first, j = last; i <= j; ++i,--j){
        if (v[i] != v[j]){
            return is_pal[first][last] = 0;
        }
    }
    return is_pal[first][last] = 1;
}


class Solution{
  public:

    string s;
    int N;
    vvs ans;
    void dfs(vector<string> &vs, int first, int last){
        if (ispal(s, first, last)){
            vs.push_back(s.substr(first, last - first + 1));
        } else {
            return;
        }
        if (last == N - 1){
            if (!vs.empty()){
                ans.push_back(vs);
                vs.pop_back();
            }
            return;
        }
        int nstart = last + 1;
        for (int e = nstart; e < N; ++e){
            dfs(vs, nstart, e);
        }

        vs.pop_back();
    }

    vvs partition(string s){
        N = s.length();
        this->s = std::move(s);
        std::memset(is_pal, -1, sizeof is_pal);
        vector<string> vs;
        ans.clear();
        for (int i = 0; i < N; ++i){
            dfs(vs, 0, i);

        }
        return ans;
    }
};



int main(){
    Solution slu;

    string s = "aab";
    auto ans = slu.partition(s);

    for (auto &a : ans){
        cout << a << endl;
    }


    return 0;
}


