#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
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
    void merge(int A[], int m, int B[], int n){
        int pos2 = m + n - 1;
        if (pos2 < 0){
            return;
        }
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0){
            if (A[i] > B[j]){
                A[pos2--] = A[i--];
            }else{
                A[pos2--] = B[j--];
            }
        }
        while (j >= 0){
            A[pos2--] = B[j--];
        }
    }
};



int main(){
    Solution slu;


    return 0;
}


