#include "leet.h"




#include <algorithm>
#include <cstring>

TreeNode *st[1010];
int top = 0;

class Solution{
  public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root){
            return {};
        }
        top = 0;

        TreeNode *p = root;
        TreeNode *last = nullptr;
        vector<int> ans;

        for ( ; ;){
            if (p && p != last) {
                st[++top] = p;
                p = p->left;
            } else if (top) {
                auto pre = st[top];
                if (pre->right == p || (!p && !pre->right)) {
                    --top; 
                    ans.push_back(pre->val);
                    last = pre;
                    p = pre;
                } else {
                    p = pre->right;
                }
            } else {
                break;
            }
        }

        return ans;
    }
};



int main(){
    Solution slu;

    auto root = Serialize::treenode({1,inf,2,3});

    cout << slu.postorderTraversal(root) << endl;

    return 0;
}


