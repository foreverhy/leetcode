#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
    
    ListNode(std::initializer_list<int> vals):val(0), next(nullptr){
        if(0 == vals.size()){
            return;
        }
        auto p = vals.begin();
        this->val = *p;
        auto last = this;
        for(++p; p != vals.end(); ++p){
            last->next = new ListNode(*p);
            last = last->next;
        }
    }

};

std::ostream& operator<<(std::ostream& os, ListNode *head){
    for(; head; head = head->next){
        os << head->val << " ";
    }
    return os;
}



#include <algorithm>
#include <cstring>
#include <map>


class Solution{
    static const int inf = 0x3f3f3f3f;
  public:
    int ans;
    int maxpath(TreeNode *h){
        if (!h){
            return 0;
        }
        auto l = maxpath(h->left);
        auto r = maxpath(h->right);
        auto tmp = std::max(l, r) + h->val;

        ans = std::max(ans, l + r + h->val);

        auto ret = std::max(tmp, h->val);
        return std::max(ret, 0);
    }

    int maxPathSum(TreeNode *root){
        ans = -inf;
        maxpath(root);
        return ans;
    }
};



int main(){
    Solution slu;
    auto root = new TreeNode(2);
    root->left = new TreeNode(-1);
    root->right = new TreeNode(-2);

    cout << slu.maxPathSum(root) << endl;


    return 0;
}


