#include "leet.h"


struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr){}
};



#include <algorithm>
#include <cstring>

class Solution{
  public:

    void connect(TreeLinkNode *root){
        if (!root){
            return;
        }

        auto left = root->left, right = root->right;

        while (left && right){
            left->next = right;
            left = left->right;
            right = right->left;
        }
        
        connect(root->left);
        connect(root->right);
    }
    
};



int main(){
    Solution slu;


    return 0;
}


