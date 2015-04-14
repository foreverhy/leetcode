#include "leet.h"




#include <algorithm>
#include <cstring>

static const int INF = 0x7fffffff;


class Solution{
  public:

    TreeNode* clone(TreeNode *h){
        if (!h){
            return nullptr;
        }
        auto h_ = new TreeNode(h->val);
        h_->left = clone(h->left);
        h_->right = clone(h->right);
        return h_;
    }


    vector<TreeNode*> generateTrees(int n){
        vector<TreeNode*> ans;
        ans.push_back(nullptr);

        for (int i = 1; i <= n; ++i){
            vector<TreeNode*> tmp;
            for (auto &h : ans){
                // new node will be root
                auto old_tree = clone(h);
                auto new_node = new TreeNode(i);
                new_node->left = old_tree;
                tmp.push_back(new_node);

                // otherwise
                if (old_tree){
                    auto parent = old_tree;

                    while (parent){
                        int pvalue = parent->val;

                        auto tmphead = clone(old_tree);
                        auto p = tmphead;
                        for (; p && p->val != pvalue; p = p->right);
                        auto nn = new TreeNode(i);
                        nn->left = p->right;
                        p->right = nn;
                        tmp.push_back(tmphead);
                            
                        parent = parent->right;
                    }

                }
            }
            ans = std::move(tmp);
        }


            return ans;
    }
};



int main(){
    Solution slu;

    auto ans = slu.generateTrees(4);

    cout << ans.size() << endl;



    return 0;
}


