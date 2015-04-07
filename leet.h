#ifndef LEET_H
#define LEET_H
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

const int inf = 0x7fffffff;

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
        if (inf == *pval){
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

std::ostream& operator<<(std::ostream &os, const vector<int> &vec){
    for(auto &a : vec){
        os << a << " ";
    }
    return os;
}

class Serialize{
  private:
    static TreeNode* tnode(const std::vector<int> &vals, size_t cnt){
        int val = vals[cnt];
        if (inf == val){
            return nullptr;
        }

        auto head = new TreeNode(val);
        size_t leftpos = (cnt << 1) | 1;
        if (leftpos < vals.size()){
            head->left  = tnode(vals, leftpos);
        }
        size_t rightpos = (cnt << 1) | 2;
        if (rightpos < vals.size()){
            head->right = tnode(vals, rightpos);
        }
        return head;
    }

  public:
    static ListNode* listnode(const std::initializer_list<int> &vals){
        return new ListNode(vals); 
    }

    static TreeNode* treenode(const std::vector<int> &vals){
        return tnode(vals, 0);
    }



};






#endif
