#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

class Solution{
  public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root){
        std::queue<TreeNode*> q;
        std::stack<TreeNode*> st;
        vector<vector<int> > ans;
        int level = 0;
        if (!root){
            return ans;
        }
        q.push(root);
        while (!q.empty()){
            while (!q.empty()){
                st.push(q.front());
                q.pop();
            }
            std::vector<int> tmp;
            while (!st.empty()){
                auto now = st.top();
                tmp.push_back(now->val);
                if (level & 1){
                    if (now->right){
                        q.push(now->right);
                    }
                    if (now->left){
                        q.push(now->left);
                    }
                } else {
                    if (now->left){
                        q.push(now->left);
                    }
                    if (now->right){
                        q.push(now->right);
                    }
                }
                st.pop();
            }
            ++level;
            ans.push_back(std::move(tmp));
        }
        return ans;
    }
};



int main(){
    Solution slu;

    auto root = Serialize::treenode({3, 9, 20, inf, inf, 15, 7});

    auto ans = slu.zigzagLevelOrder(root);
    for (auto &a : ans){
        cout << a << endl;
    }

    return 0;
}


