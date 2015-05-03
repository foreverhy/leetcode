#include "leet.h"




#include <algorithm>
#include <cstring>


class Solution{
  public:
    bool ok = true;
    int depth(TreeNode* root){
        if (!ok){
            return 0;
        }
        if (!root){
            return 0;
        }
        int ld = depth(root->left);
        int rd = depth(root->right);
        if (std::abs(ld - rd) > 1){
            ok = false;
        }
        return std::max(ld, rd) + 1;
    }

    bool isBalanced(TreeNode* root){
        depth(root); 
        return ok;
    }
};



int main(){
    Solution slu;


    return 0;
}


