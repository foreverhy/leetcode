#include "leet.h"




#include <algorithm>
#include <cstring>

#include <queue>

class Solution{
  public:

    vector<vector<int> > levelOrder(TreeNode *root){
        std::queue<TreeNode*> q;
        std::queue<TreeNode*> tmp;
        vector<vector<int> > ans;
        if (root){
            q.push(root);
        }
        std::vector<TreeNode*> last;
        while (!q.empty()){
            std::vector<int> tvec;
            while (!q.empty()){
                tmp.push(q.front());     
                tvec.push_back(q.front()->val); 
                q.pop();
            }
            ans.push_back(std::move(tvec));
            while (!tmp.empty()){
                auto now = tmp.front();
                if (now->left){
                    q.push(now->left);
                }
                if (now->right){
                    q.push(now->right);
                }
                tmp.pop();
            }
        }


        return ans;
    }
};



int main(){
    Solution slu;

    auto root = Serialize::treenode({3,9,20,inf,inf,15,7});

    auto ans = slu.levelOrder(root);

    for (auto &a : ans){
        for (auto &t : a){
            cout << t << " ";
        }
        cout << endl;
    }


    return 0;
}


