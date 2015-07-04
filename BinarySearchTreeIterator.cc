#include "leet.h"




#include <algorithm>
#include <cstring>
#include <stack>

class BSTIterator {
    std::stack<TreeNode*> stack;
  public:
    
    BSTIterator(TreeNode *root) {
        while(root) {
            stack.push(root);
            root = root->left;
        }
    }

    bool hasNext() {
        return !stack.empty();
    }

    int next() {
        auto retptr = stack.top(); 
        stack.pop();
        TreeNode *ptr = nullptr;
        if (retptr->right) {
            ptr = retptr->right;
        }
        while (ptr) {
            stack.push(ptr);
            ptr = ptr->left;
        }
        return retptr->val;
    }

};



int main(){
    auto root = Serialize::treenode({41,37,44,24,39,42,48,1,35,38,40,null,43,46,49,0,2,30,36,null,null,null,null,null,null,45,47,null,null,null,null,null,4,29,32,null,null,null,null,null,null,3,9,26,null,31,34,null,null,7,11,25,27,null,null,33,null,6,8,10,16,null,null,null,28,null,null,5,null,null,null,null,null,15,19,null,null,null,null,12,null,18,20,null,13,17,null,null,22,null,14,null,null,21,23 });
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << " ";
    cout << endl;


    return 0;
}


