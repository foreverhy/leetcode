#include "leet.h"




#include <algorithm>
#include <cstring>

const int MAXN = 1010;
TreeNode* stack[MAXN];
int top = 0;

class Solution{
  public:
    vector<int> preorderTraversal(TreeNode *root){
        if (!root){
            return {};
        }
        vector<int> ans;
        top = 0;

        //stack[++top] = root;
        TreeNode *p = root;

        while (true){
            if (p){
                ans.push_back(p->val);
                stack[++top] = p;
                p = p->left;
            } else if (top){
                p = stack[top--]->right;
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

    cout << slu.preorderTraversal(root) << endl;


    return 0;
}


