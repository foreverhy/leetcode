#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:

    typedef vector<int>::reverse_iterator iter;
    int N;

    TreeNode* build(iter pb, iter pe, iter ib, iter ie){
        if (pb >= pe || ib >= ie){
            return nullptr;
        }
        auto root = new TreeNode(*pb);
        
        iter in_mid = ib;
        iter p_mid = pb;
        for (; in_mid < ie && *in_mid != *pb; ++in_mid, ++p_mid);
        root->right = build(pb + 1, p_mid + 1, ib, in_mid); 
        root->left = build(p_mid + 1, pe, in_mid + 1, ie);

        return root;
    }
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postoreder){
        return build(postoreder.rbegin(), postoreder.rend(), inorder.rbegin(), inorder.rend());
    }
};



int main(){
    Solution slu;
    vector<int> pre = {1,2,4,5,3,6,8,7};
    vector<int> in = {4,2,5,1,6,8,3,7};
    vector<int> post = {4,5,2,8,6,7,3,1};

    auto root = slu.buildTree(in, post);
    cout << root << endl;

    return 0;
}


