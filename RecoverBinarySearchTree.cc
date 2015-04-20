#include "leet.h"




#include <algorithm>
#include <cstring>

const int INF = 0x7fffffff;

class Solution{
  public:
    TreeNode *first, *second;
    TreeNode *prev;
    void recoverTree(TreeNode *root){
        first = second = prev = nullptr;
        auto infinite = new TreeNode(-INF);
        prev = infinite;
        find(root);
        if (first && second){
            std::swap(first->val, second->val);
        }
        delete infinite;
    }

    void find(TreeNode *h){
        if (!h){
            return;
        }

        find(h->left);

        if (h->val < prev->val){
            if (!first){
                first = prev;
            }
            second = h;
        } else if (first && h->val >= first->val){
            return;
        }
        prev = h;

        find(h->right);
    }
};



int main(){
    Solution slu;

    auto root = Serialize::treenode({146, 71, -13, 55, inf, 231, 399, 321 , inf, inf, inf, inf, inf, -33});

    slu.recoverTree(root);
    cout << root << endl;
    //cout << root->left->val  << "  " << root->right->val << endl;


    return 0;
}


