#ifndef LEET_H
#define LEET_H
#include <vector>
#include <string>
#include <iostream>
//#include <map>
#include <queue>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;

const int inf = 0x7fffffff;
const int null = 0x7fffffff;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

    TreeNode(std::initializer_list<int> vals):val(0), left(nullptr), right(nullptr){
        if (0 == vals.size()){
            return ;
        }
        auto pval = vals.begin();
        if (null == *pval){
            return;
        }
        val = *pval;
    }
};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
    
    ListNode(const std::initializer_list<int> &vals):val(0), next(nullptr){
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

template<typename T>
std::ostream& operator<<(std::ostream &os, const vector<T> &vec){
    for(auto &a : vec){
        os << a << " ";
    }
    return os;
}

namespace {


}

std::ostream& operator<< (std::ostream &os, TreeNode *h){
    std::queue<TreeNode*> q;
    q.push(h);

    while (!q.empty()){
        auto now = q.front();
        if (now){
            os << now->val << ",";
            q.push(now->left);
            q.push(now->right);
        }else {
            os << "#,";
        }

        q.pop();

    }
    return os;
}



class Serialize{
  private:

  public:
    static ListNode* listnode(const std::initializer_list<int> &vals){
        return new ListNode(vals); 
    }

    static TreeNode* treenode(const std::initializer_list<int> &vals){
        std::queue<TreeNode*> q;
        if (0 == vals.size()){
            return nullptr;
        }
        auto root = new TreeNode(*vals.begin());

        q.push(root);

        for (auto ptr = vals.begin() + 1; ptr < vals.end(); ptr += 2){
            if (q.empty()){
                break;
            }
            auto now = q.front();
            auto lval = *ptr, rval = null;
            if (ptr + 1 != vals.end()){
                rval = *(ptr + 1);
            }
            if (null != lval){
                now->left = new TreeNode(lval);
                q.push(now->left);
            }
            if (null != rval){
                now->right = new TreeNode(rval);
                q.push(now->right);
            }
            q.pop();

        }

        return root;
    }



};






#endif
