#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    
    vector<vector<int> > ans;
    vector<int> tmp;
    void dfs(TreeNode *h, int sum){
        if (!h){
            return;
        }
        tmp.push_back(h->val);

        if (!h->left && !h->right && sum == h->val){
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }

        dfs(h->left, sum - h->val);
        dfs(h->right, sum - h->val);

        tmp.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum){
        ans.clear();
        tmp.clear();

        dfs(root, sum);

        return ans;
    }
};



int main(){
    Solution slu;

    auto tree = Serialize::treenode({5,4,8,11,inf,13,4,7,2,inf,inf,5,1});

    auto ans = slu.pathSum(tree, 22);

    for(auto &a : ans){
        cout << a << endl;
    }


    return 0;
}


