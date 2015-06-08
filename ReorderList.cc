#include "leet.h"




#include <algorithm>
#include <cstring>
#include <queue>

using std::deque;

class Solution{
  public:

    void reorderList(ListNode *head){
        if (!head){
            return;
        }
        deque<ListNode*> q;
        for (auto p = head; p; p = p->next) {
            q.push_back(p);
        }
        ListNode *front, *back, *prev;
        ListNode H(0);
        H.next = head; 
        prev = &H;
        while (!q.empty()){
            front = q.front();
            q.pop_front();
            back = nullptr;
            if (!q.empty()){
                back = q.back();
                q.pop_back();
            }
            prev->next = front;
            prev = front;
            prev->next = nullptr;
            if (back){
                front->next = back;
                prev = back;
                back->next = nullptr;
            } 
        }
    }
};



int main(){
    Solution slu;

    ListNode *a = Serialize::listnode({1,2,3,4});

    slu.reorderList(a);

    cout << a << endl;


    return 0;
}


