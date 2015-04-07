#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root){
        ans.clear();
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root){
        if (!root){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

};



int main(){
    Solution slu;

    auto root = Serialize::treenode({1,inf,2,inf,inf,3});

    auto ans = slu.inorderTraversal(root);
    
    cout << ans << endl;


    return 0;
}


