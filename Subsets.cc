#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>

class Solution{
  public:

    typedef vector<vector<int> > VII;

    void dfs(VII &ans, vector<int> &now, vector<int> &S, size_t idx){
        if(idx >= S.size()){
            return;
        }
        now.push_back(S[idx]);
        if(now.size() <= S.size()){
            ans.push_back(now);
        }
        for(size_t i = idx + 1; i < S.size(); ++i){
            dfs(ans, now, S, i);
        }
        now.pop_back();

    }

    VII subsets(vector<int> &S){
        std::sort(S.begin(), S.end(), [](const int &x, const int &y){return x < y;});
        VII ans;
        vector<int> now;
        for(size_t i = 0; i < S.size(); ++i){
            dfs(ans, now, S, i);
        }
        ans.push_back({});
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    vector<int> S = {4, 1, 0};
    auto ans = slu.subsets(S);
    for(auto &v : ans){
        for(auto &a : v){
            cout << a << " ";
        }
        cout << endl;
    }


    return 0;
}


