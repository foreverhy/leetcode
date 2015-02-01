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

    int target;

    void dfs(vector<vector<int> > &ans, vector<int> &candidates, vector<int> &res, unsigned idx, int sum){
        if(idx >= candidates.size()){
            return;
        }
        //cout << "idx: " << idx << endl;
        
        sum += candidates[idx];
        res.push_back(candidates[idx]);
        if(sum == target){
            ans.push_back(res);
            res.pop_back();
            return;
        }
        if(sum > target){
            res.pop_back();
            return;
        }

        for(unsigned i = idx; i < candidates.size(); ++i){
            dfs(ans, candidates, res, i, sum);
        }
        res.pop_back();

    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        vector<vector<int> > ans;
        vector<int> res;
        this->target = target;

        sort(candidates.begin(), candidates.end());

        for(unsigned i = 0; i < candidates.size(); ++i){
            dfs(ans, candidates, res, i, 0);
        }

        return ans;
    }


};



int main(){
    Solution slu;
    using std::cin;

    vector<int> a = {2, 3, 6, 7};

    auto ans = slu.combinationSum(a, 7);
    for(auto &v: ans){
        for(auto &i: v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}


