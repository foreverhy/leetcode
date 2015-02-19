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
    ListNode* rotateRight(ListNode *head, int k){
        if(!head)return nullptr;
        ListNode *p1 = head, *p2 = head;
        int len = 0;
        for(; p2; p2 = p2->next, ++len);
        k %= len;
        p2 = head;
        for(int i = 0; i < k; ++i, p2 = p2->next);
        for(p1 = head; p2->next; p1 = p1->next, p2 = p2->next);
        p2->next = head;
        head = p1->next;
        p1->next = nullptr;
        return head;
    }

};



int main(){
    Solution slu;
    using std::cin;
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);

    auto ans = slu.rotateRight(h, 1);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }


    return 0;
}


