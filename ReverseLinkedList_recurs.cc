#include "leet.h"

#include <cassert>



#include <algorithm>
#include <cstring>

class Solution{
  public:
    ListNode *solve(ListNode *head, ListNode* &last) {
        if (!head) {
            return nullptr;
        }
        if (head->next) {
            ListNode *tmp = nullptr;
            auto ret = solve(head->next, tmp);
            assert(tmp);
            tmp->next = head;
            last = head;
            last->next = nullptr;
            return ret;
        }
        last = head;
        head->next = nullptr;
        return head;
    }
    ListNode *reverseList(ListNode *head) {
        if (!head) return nullptr;
        auto last = head;
        return solve(head, last);
    }
};



int main(){
    Solution slu;

    auto list = Serialize::listnode({1,2,3});
    cout << slu.reverseList(list) << endl;

    return 0;
}


