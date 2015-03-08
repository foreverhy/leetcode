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
    int N, K;
    void dfs(vector<vector<int> > &ans, vector<int> &now, int idx){
        now.push_back(idx);
        if(K == static_cast<int>(now.size())){
            ans.push_back(now);
            now.pop_back();
            return;
        }
        for(int i = idx + 1; i <= N; ++i){
            dfs(ans, now, i);
        }
        now.pop_back();
    }
    vector<vector<int> > combine(int n, int k){
        N = n; K = k;
        vector<vector<int> > ans;
        vector<int> now;
        for(int i = 1; i <= n; ++i){
            dfs(ans, now, i);
        }
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    int n, k;
    while(cin >> n >> k){
        auto ans = slu.combine(n, k);
        for(auto &v : ans){
            for(auto &a : v){
                cout << a << " ";
            }
            cout << endl;
        }
    }


    return 0;
}


