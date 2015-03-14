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
    ListNode(int x):val(x), next(nullptr){}
    
    ListNode(std::initializer_list<int> vals):val(0), next(nullptr){
        if(0 == vals.size()){
            return;
        }
        auto p = vals.begin();
        this->val = *p;
        auto last = this;
        for(++p; p != vals.end(); ++p){
            last->next = new ListNode(*p);
            last = last->next;
        }
    }

};

std::ostream& operator<<(std::ostream& os, ListNode *head){
    for(; head; head = head->next){
        os << head->val << " ";
    }
    return os;
}




#include <algorithm>
#include <cstring>

class Solution{
  public:

    void freelist(ListNode *head){
        if(!head){
            return;
        }
        while(head){
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    ListNode *deleteDuplicates(ListNode *head){
        if(!head){
            return nullptr;
        }
        ListNode HEAD(0);
        auto h = &HEAD;
        auto pre = h;
        h->next = head;

        auto left = head, right = head;

        while(right->next){
            auto nxt = right->next;
            if(nxt->val != left->val){
                if(left == right){
                    pre = right;
                }else{
                    pre->next = nxt;
                    right->next = nullptr;
                    freelist(left);
                }
                left = right = nxt;
            }else{
                right = nxt;
            }
        }
        if(left != right){
            pre->next = right->next;
            right->next = nullptr;
            freelist(left);
        }
        return h->next;
    }

};



int main(){
    Solution slu;
    using std::cin;

    //auto h = new ListNode({1,2,3,3,4,4,5});
    auto h = new ListNode({1,1,1,2,3});
    cout << h << endl;

    h = slu.deleteDuplicates(h);
    cout << h << endl;



    return 0;
}


