#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:

    typedef vector<int>::iterator iter;
    int N;

    TreeNode* build(iter pb, iter pe, iter ib, iter ie){
        if (pb >= pe || ib >= ie){
            return nullptr;
        }
        auto root = new TreeNode(*pb);
        
        iter in_mid = ib;
        iter p_mid = pb;
        for (; in_mid < ie && *in_mid != *pb; ++in_mid, ++p_mid);
        root->left = build(pb + 1, p_mid + 1, ib, in_mid); 
        root->right = build(p_mid + 1, pe, in_mid + 1, ie);

        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};



int main(){
    Solution slu;
    vector<int> pre = {1,2,4,5,3,6,8,7};
    vector<int> in = {4,2,5,1,6,8,3,7};

    auto root = slu.buildTree(pre, in);
    cout << root << endl;

    return 0;
}


