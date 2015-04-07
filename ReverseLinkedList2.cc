#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode* reverseBetween(ListNode *head, int m, int n){
        if (!head){
            return nullptr;
        }
        ListNode H(0);
        auto h = &H;
        h->next = head;

        auto p = h;
        auto left = p;
        int cnt = 0;
        for( ; cnt < m; ++cnt){
            left = p;
            p = p->next;
        }
        auto last = p;
        p = p->next;

        for( ; cnt < n; ++cnt){
            auto tmp = p->next; 
            p->next = last;
            last = p;
            p = tmp;
        }
        left->next->next = p;
        left->next = last;

        return h->next;
    }

};



int main(){
    Solution slu;

    //auto head = new ListNode({1,2,3,4,5});
    auto head = new ListNode({1,2,3,4,5});

    head = slu.reverseBetween(head, 2, 4);

    while(head){
        cout << head->val << endl;
        head = head->next;
    }


    return 0;
}


