#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    using ull = unsigned long long;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        auto p = headA;
        while (p) {
            auto nxt = p->next;
            p->next = (ListNode*)((ull)(p->next) | 1);
            p = nxt;
        }
        p = headB;
        ListNode *ans = nullptr;
        for (; p; p = p->next) {
            if ((ull)(p->next) & 1) {
                ans = p;
                break;
            }
        }
        p = headA;
        while (p) {
            p->next = (ListNode*)((ull)(p->next) & ~1ull);
            p = p->next;
        }
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


