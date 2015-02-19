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

using std::pair;
class Solution{
  public:
    int K;
    pair<ListNode *, ListNode *> reverse(ListNode *head, int k){
        if(!head) return {nullptr, nullptr};
        if(1 == k) return {head, head};
        auto pr = reverse(head->next, k - 1);
        if(pr.first){
            auto nxt = pr.second->next;
            if(k == K){
                auto tmp = reverse(nxt, K);
                nxt = tmp.first? tmp.first: nxt;
            }
            head->next =nxt;
            pr.second->next = head;
            pr.second = head;
        }
        return pr;
    }

    ListNode* reverseKGroup(ListNode *head, int k){
        K = k;
        auto ans = reverse(head, k);
        return ans.first? ans.first: head;
    }
};



int main(){
    Solution slu;
    using std::cin;

    auto h = new ListNode(1); 
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);

    auto s = slu.reverseKGroup(h, 2);
    while(s){
        cout << s->val << " ";
        s = s->next;
    }
    cout << endl;

    return 0;
}


