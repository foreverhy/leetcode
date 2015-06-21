#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    // merge sort
    ListNode* sortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode H(0);
        H.next = head;
        int len = 0;
        for (auto p = head; p; p = p->next) {
            ++len;
        }

        if (len <= 1) {
            return H.next;
        }

        if (2 == len) {
            if (head->val > head->next->val) {
                auto tmp = head->next->next;
                H.next = head->next;
                head->next->next = head;
                head->next = tmp;
                
            }
            return H.next;
        }

        ListNode *mid = &H;
        int mpos = len >> 1;
        for (int i = 0; i < mpos; mid = mid->next, ++i);
        auto nxt = mid->next;
        mid->next = nullptr;
        auto l1 = sortList(head);
        auto l2 = sortList(nxt);
        auto p = l1, q = l2;
        H.next = l1;
        auto pre = &H;
        while (p && q) {
            if (p->val > q->val) {
                auto nxt = q->next; 
                q->next = p;
                pre->next = q;
                pre = q;
                q = nxt;
            } else {
                pre = p;
                p = p->next;
            }
        }
        if (q) {
            pre->next = q;
        }

        return H.next;
    }
};



int main(){
    Solution slu;

    auto lst = Serialize::listnode({3,2,1,5,2,4});
    //auto lst = Serialize::listnode({3,2,4});
    cout << slu.sortList(lst) << endl;

    return 0;
}


