#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode* insertionSortList(ListNode *head) {
        
        if (!head) {
            return nullptr;
        }
        ListNode H(0);
        H.next = head;

        // 3 2 1
        for (auto pp = &H; pp->next;) {
            auto pos = pp->next;
            auto nxt = pp->next;
            bool done = false;
            for (auto p = &H; p->next && p->next != pos; p = p->next) {
                if (pos->val < p->next->val) {
                    pp->next = pos->next;
                    if (!pp->next) {
                        done = true;
                    } 
                    nxt = pp;
                    pos->next = p->next;
                    p->next = pos;
                    break;
                }
            }
            if (done) {
                break;
            }
            pp = nxt;
        }

        return H.next;    
    }
};



int main(){
    Solution slu;


    //auto ls = Serialize::listnode({3,2,5,1,6,3});
    //auto ls = Serialize::listnode({3,2,1});
    //auto ls = Serialize::listnode({3,2,1});
    auto ls = Serialize::listnode({3,2});
    
    cout << slu.insertionSortList(ls) << endl;



    return 0;
}


