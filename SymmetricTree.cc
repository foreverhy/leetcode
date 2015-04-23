#include "leet.h"




#include <algorithm>
#include <cstring>
#include <stack>

class Solution{
  public:
    bool isSymmetric(TreeNode *lhs, TreeNode *rhs){
        if (!lhs && !rhs){
            return true;
        }
        if (!lhs || !rhs){
            return false;
        }
        if (lhs->val != rhs->val){
            return false;
        }
        return isSymmetric(lhs->left, rhs->right) && isSymmetric(lhs->right, rhs->left);

    }

    bool isSymmetric(TreeNode *root){
        if (!root){
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

};



int main(){
    Solution slu;

    //auto root = Serialize::treenode({1,2,2,inf,3,inf,3});
    auto root = Serialize::treenode({1,2,2,3,4,4,3});

    cout << slu.isSymmetric(root) << endl;

    return 0;
}


