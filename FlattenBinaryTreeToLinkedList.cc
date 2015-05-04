#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    TreeNode* slove(TreeNode *h, TreeNode *prev){
        if (!h){
            return nullptr;
        }
        auto t = h, left = h->left, right = h->right;
        if (prev){
            prev->left = nullptr;
            prev->right = h;
        }
        if (!left && !right){
            return h;
        }


        if (left){
            t = slove(left, t);
        }

        if (right){
            t = slove(right, t);
        }

        return t;
    }

    void flatten(TreeNode *root){
        slove(root, nullptr);
    }
};



int main(){
    Solution slu;

    auto tree = Serialize::treenode({1,2,5,3,4,inf,6});
    slu.flatten(tree);
    cout << tree << endl; 
    return 0;
}


