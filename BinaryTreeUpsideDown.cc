#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    TreeNode* solve(TreeNode *h, TreeNode *parent) {
        if (!h) {
            return h;
        }
        auto p = solve(h->left, h);
        if (p) {
            p->right = h;
        }
        if (!parent) {
            h->left = h->right = nullptr;
            return h;
        }
        h->left = parent->right;
        h->right = parent;
        return h->right;
    }

    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        auto now = root;
        if (!now) {
            return now;
        }
        while (now->left) {
            now = now->left;
        }
        solve(root, nullptr);
        return now;
    }
};



int main(){
    Solution slu;
    auto root = Serialize::treenode({1,2,3,4,5,inf,9});
    cout << slu.upsideDownBinaryTree(root) << endl;


    return 0;
}


