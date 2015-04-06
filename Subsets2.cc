#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    typedef vector<vector<int> > VII;
    static const int inf = 0x3f3f3f3f;

    void dfs(VII &ans, vector<int> &now, vector<int> &S, size_t idx, int justleft){
        if(idx >= S.size() || justleft == S[idx]){
            return;
        }
        now.push_back(S[idx]);
        if(now.size() <= S.size()){
            ans.push_back(now);
        }
        for(size_t i = idx + 1; i < S.size(); ++i){
            if (i != idx + 1){
                dfs(ans, now, S, i, S[i - 1]);
            } else{
                dfs(ans, now, S, i, inf);
            }
        }
        now.pop_back();

    }

    VII subsetsWithDup(vector<int> &S){
        std::sort(S.begin(), S.end(), [](const int &x, const int &y){return x < y;});
        VII ans;
        vector<int> now;
        //for(size_t i = 0; i < S.size(); ++i)if (!i || S[i] != S[i - 1]){
        for(size_t i = 0; i < S.size(); ++i){
            if (i){
                dfs(ans, now, S, i, S[i - 1]);
            }else{
                dfs(ans, now, S, i, inf);
            }
        }
        ans.push_back({});
        return ans;
    }

};



int main(){
    Solution slu;

    vector<int> S = {1, 2, 2};
    auto ans = slu.subsetsWithDup(S);
    for(auto &v : ans){
        for(auto &a : v){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}


