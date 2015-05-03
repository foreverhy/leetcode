#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> nodes;
    typedef vector<int>::iterator it;
    TreeNode* build(it begin, it end){
        if (begin >= end){
            return nullptr;
        }
        auto mid = begin + (end - begin) / 2;
        auto root = new TreeNode(*mid);
        root->left = build(begin, mid);
        root->right = build(mid + 1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head){
        nodes.clear();
        for(auto p = head; p; p = p->next){
            nodes.push_back(p->val);
        }
        return build(nodes.begin(), nodes.end());
    }
};



int main(){
    Solution slu;

    auto list = Serialize::listnode({1,2,3,4,5,6,7});
    auto ans = slu.sortedListToBST(list);
    cout << ans << endl;


    return 0;
}


