#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool hasPathSum(TreeNode* root, int sum){
        if (!root){
            return false;
        }
        if (!root->left && !root->right){
            return root->val == sum;
        }
        return hasPathSum(root->left, sum - root->val) || 
            hasPathSum(root->right, sum - root->val);
    }
};



int main(){
    Solution slu;


    return 0;
}


