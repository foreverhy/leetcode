#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    typedef unsigned long long ull;

    ListNode* detectCycle(ListNode *head){
        auto p1 = head;
        auto nxt = p1;
        ListNode* ans = nullptr;
        while (p1){
            nxt = p1->next;
            if ((ull)(nxt) & 1){
                ans = p1;
                break;
            }
            p1->next = (ListNode*)((ull)(nxt) | 0x1);
            p1 = nxt;
        }
        p1 = head;
        while (p1){
            nxt = p1->next;
            if (((ull)(nxt) & 1) == 0){
                break;
            }
            p1->next = (ListNode*)((ull)(nxt) & 0xfffffff8);
            p1 = p1->next;
        }
        return ans;
    }
};



int main(){
    Solution slu;


    return 0;
}


