#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *pre = nullptr;
        auto now = head;
        while (now) {
            auto nxt = now->next;
            now->next = pre;
            pre = now;
            now = nxt;
        }
        return pre;
    }
};



int main(){
    Solution slu;


    return 0;
}


