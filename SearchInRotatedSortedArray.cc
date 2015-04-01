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
    int search(int A[], int n, int target){
        int left = 0, right = n - 1;
        if(target < A[left] && target > A[right]){
            return -1;
        }

        while (left <= right){
            int mid = (left + right) >> 1;
            if (A[mid] == target){
                return mid;
            }

            if (A[mid] >= A[left]){
                if (target > A[mid]){
                    left = mid + 1;
                }else if (target >= A[left]){
                    right =  mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if (target < A[mid]){
                    right = mid - 1;
                }else if (target <= A[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }

        }
        return -1;
    }
};



int main(){
    Solution slu;
    //vector<int> a = {6,7,0,1,2,3,4,5};
    vector<int> a = {4,5,6,7,8,1,2,3};

    cout << slu.search(a.data(), a.size(), 8) << endl;


    return 0;
}


