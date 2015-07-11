#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return nullptr;
        }
        int dp = root->val - p->val;
        int dq = root->val - q->val;

        if (dp * dq <= 0) {
            return root;
        } else if (dp < 0) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};



int main(){
    Solution slu;


    return 0;
}


