#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int height;

    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        height = 0;
        for (auto now = root; now; now = now->left) ++height;
        int mark = 1;
        int ans = 1;
        auto now = root;
        const int hint = 1 << (height - 1);
        for (;;) {
            if (mark >= hint) {
                ans = mark;
            }
            if (!now || !now->left) break;
            auto mk = mark << 1;
            auto n = now->left;
            while (n->right) {
                n = n->right;
                mk = mk << 1 | 1;
            }

            if (mk < hint) {
                now = now->left; 
                mark <<= 1;
            } else {
                ans = mk;
                if (now->right) {
                    now = now->right;
                    mark = mark << 1 | 1;
                } else {
                    break;
                }

            }
        }
        return ans;
    }
};



int main(){
    Solution slu;

    auto root = Serialize::treenode({1,2,3});

    cout << slu.countNodes(root) << endl;


    return 0;
}


