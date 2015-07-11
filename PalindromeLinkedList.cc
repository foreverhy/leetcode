#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool isPalindrome(ListNode *head) {
        if (!head) {
            return true;
        }
        int len = 0;
        for (auto p = head; p; p = p->next) {
            ++len;
        }
        auto mid = head;
        ListNode *pre = nullptr;
        int half = len >> 1;
        auto nxt = mid;
        for (int i = 0; i < half; ++i) {
            nxt = mid->next;
            mid->next = pre;
            pre = mid;
            mid = nxt;
        }
        auto mid0 = pre;
        if (len & 1) {
            mid = mid->next;
        }
        while (mid0 && mid) {
            if (mid0->val != mid->val) {
                return false;
            }
            mid0 = mid0->next;
            mid = mid->next;
        }
        return true;
    }
};



int main(){
    Solution slu;

    auto list = Serialize::listnode({1,2,3,2,1});
    cout << slu.isPalindrome(list) << endl;

    return 0;
}


