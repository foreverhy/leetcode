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
    ListNode* mergeTwoLists(ListNode *l1, ListNode * l2){
        ListNode h(0);
        auto head = &h;
        head->next = l1;
        auto pre = head;
        auto p1 = l1, p2 = l2;
        while(p1 && p2){
            if(p1->val <= p2->val){
                pre = p1;
                p1 = p1->next;
            }else{
                auto next = p2->next;
                pre->next = p2;
                p2->next = p1;
                pre = p2;
                p2 = next;
            }
        }
        if(p2){
            pre->next = p2;
        }
        return head->next;
    }

};



int main(){
    Solution slu;
    using std::cin;

    auto l1 = new ListNode(2);
    auto l2 = new ListNode(1);

    auto ans = slu.mergeTwoLists(l1, l2);
    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;


    return 0;
}


