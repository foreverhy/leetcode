#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    static const int INF = 0x7fffffff;
    int ans;
    bool done;
    int nodes(TreeNode *h, int k) {
        if (done || !h) {
            return 0;
        }
        //printf("NODE %d, k %d\n", h->val, k);
        auto lnodes = nodes(h->left, k);
        //printf("LNODES %d\n", lnodes);
        if (k <= lnodes) {
            return 0;
        }
        if (!done && lnodes + 1 == k) {
            done = true;
            ans = h->val;
            return 0;
        }
        auto rnodes = nodes(h->right, k - lnodes - 1);
        return lnodes + rnodes + 1;
    }
    int kthSmallest(TreeNode *root, int k) {
        ans = 0;
        done = false;
        nodes(root, k);
        return ans;
    }
};



int main(){
    Solution slu;

    auto tree = Serialize::treenode({2, 1});
    cout << slu.kthSmallest(tree, 1) << endl;


    return 0;
}


