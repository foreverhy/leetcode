#include "leet.h"




#include <algorithm>
#include <cstring>

#include <queue>

class Solution{
  public:
    vector<int> rightSideView(TreeNode *root) {
        std::queue<TreeNode*> q, backup;
        q.push(root);
        vector<int> ans;
        for (;;) {
            bool first = true;
            while (!q.empty()) {
                auto now = q.front();
                q.pop();
                if (first) {
                    ans.push_back(now->val);
                    first = false;
                }
                if (now->right) {
                    backup.push(now->right);
                }
                if (now->left) {
                    backup.push(now->left);
                }
            }
            if (backup.empty()) {
                break;
            }
            while (!backup.empty()) {
                q.push(backup.front());
                backup.pop();
            }
        }
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


