#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int ans = 0;
    int sumNumbers(TreeNode *root){
        ans = 0;
        sum(root, 0);

        return ans;
    }

    void sum(TreeNode *h, int val){
        if (!h){
            return;
        }
        bool leaf = true;
        val = val * 10 + h->val;
        if (h->left){
            sum(h->left, val);
            leaf = false;
        }
        if (h->right){
            sum(h->right, val);
            leaf = false;
        }
        if (leaf){
            ans += val;
        }
    }
};



int main(){
    Solution slu;

    auto tree = Serialize::treenode({1,2,3,4});
    auto ans = slu.sumNumbers(tree);
    cout << ans << endl;


    return 0;
}


