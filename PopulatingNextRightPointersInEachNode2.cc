#include "leet.h"


struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int v): val(v), left(nullptr), right(nullptr), next(nullptr){}
};



#include <algorithm>
#include <cstring>
#include <queue>

class Solution{
  public:

    void connect(TreeLinkNode *root){
        if (!root){
            return;
        }
        std::queue<TreeLinkNode*> q;
        std::queue<TreeLinkNode*> tmp;
        q.push(root);
        TreeLinkNode *prev = nullptr;
        int tot = 1;
        int cnt = 0;
        while (!q.empty()){
            auto now = q.front(); 
            q.pop();
            if (prev){
                prev->next = now;
            }

            if (now->left){
                ++cnt;
                q.push(now->left);
            }
            if (now->right){
                ++cnt;
                q.push(now->right);
            }
            if (0 == --tot){
                prev = nullptr;
                tot = cnt;
                cnt = 0;
            } else {
                prev = now;
            }
        }

    }
    
};



int main(){
    Solution slu;


    return 0;
}


