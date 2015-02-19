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
    ListNode* swapPairs(ListNode *head){
        auto h = new ListNode(0);
        h->next = head;
        auto pre = h;
        auto p = head;

        while(p && p->next){
            auto q = p->next;
            auto c = q->next;
            pre->next = q;
            q->next = p;
            p->next = c;
            pre = p;
            p = c;
        }


        auto ans = h->next;
        delete h;
        return ans;
    }

};



int main(){
    Solution slu;
    using std::cin;

    auto h = new ListNode(1); 
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);

    auto s = slu.swapPairs(h);
    while(s){
        cout << s->val << " ";
        s = s->next;
    }
    cout << endl;

    return 0;
}


