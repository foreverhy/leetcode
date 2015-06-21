#include "leet.h"




#include <algorithm>
#include <cstring>

#include <queue>

class Solution{
  public:
    TreeNode* invertTree(TreeNode *root) {
        if (!root) {
            return root;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto now = q.front();
            std::swap(now->left, now->right);
            if (now->left) {
                q.push(now->left);
            }
            if (now->right) {
                q.push(now->right);
            }
            q.pop();
        }
        return root;
    }
};



int main(){
    Solution slu;


    return 0;
}


