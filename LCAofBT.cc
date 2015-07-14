#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    TreeNode *ans;

    int solve(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) {
            return 0;
        }
        //cout << root->val << endl;
        int left = solve(root->left, p, q);

        //cout << "left: " << left << endl;
        if (2 == left) {
            return 2;
        }
        if (1 == left && (root == p || root == q)) {
            ans = root;
            return 2;
        }

        int right = solve(root->right, p, q);
        //cout << "right: " << right << endl;

        if (2 == right) {
            return 2;
        }

        if (1 == right && (root == p || root == q || 1 == left)) {
            ans = root;
            return 2;
        }
        return left + right + ((root == p || root == q) ? 1 : 0);

    }


    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        ans = nullptr;
        solve(root, p, q);
        return ans;
    }
};



int main(){
    Solution slu;

    auto tree = Serialize::treenode({1,2,3});
    auto p = tree->left;
    auto q = tree->right;

    cout << slu.lowestCommonAncestor(tree, p, q)->val << endl;

    return 0;
}


