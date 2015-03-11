#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


#include <cstdlib>
using std::atoi;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};




#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode* deleteDuplicates(ListNode *head){
        if(!head)return nullptr;
        ListNode tmp(0x3f3f3f3f);
        ListNode *pre = &tmp;
        pre->next = head;
        for(auto p = head; p; p = p->next){
            if(pre->val != p->val){
                pre->next = p;
                pre = p;
            }
        }
        pre->next = nullptr;
        return head;
    }

};



int main(){
    Solution slu;
    using std::cin;

    auto h1 = new ListNode(1);
    h1->next = new ListNode(1);
    h1->next->next = new ListNode(2);
    h1->next->next->next = new ListNode(3);
    h1->next->next->next->next = new ListNode(3);

    auto ans = slu.deleteDuplicates(h1);
    for(; ans; ans = ans->next){
        cout << ans->val << endl;
    }

    return 0;
}


