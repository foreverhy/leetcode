#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        int lenA = 0, lenB = 0;
        for (auto p = headA; p; ++lenA, p = p->next);
        for (auto p = headB; p; ++lenB, p = p->next);
        auto p = headA, q = headB;
        auto diff = abs(lenA - lenB);
        if (lenA < lenB) {
            for (int i = 0; i < diff; ++i, q = q->next);
        } else {
            for (int i = 0; i < diff; ++i, p = p->next);
        }
        for (; p; p = p->next, q = q->next) {
            if (p == q) {
                return p;
            }
        }
        return nullptr;
    }
};



int main(){
    Solution slu;


    return 0;
}


