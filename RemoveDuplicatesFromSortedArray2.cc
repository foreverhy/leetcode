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
    int removeDuplicates(int A[], int n){
        int left = 0, right = 0;
        int dup = 0;
        int last = 0x3f3f3f3f;
        for(right = 0; right < n; ++right){
            if(last != A[right]){
                dup = 1;
                last = A[left++] = A[right];
            }else if(++dup <= 2){
                A[left++] = A[right];
            }
        }
        return left;
    }

};



int main(){
    Solution slu;
    using std::cin;

    int A[] = {1, 1, 1, 2, 2, 3};
    int k = slu.removeDuplicates(A, 6);
    cout << k << endl;
    for(int i = 0; i < k; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
    int B[] = {1, 1, 1, 1, 3, 3};
    k = slu.removeDuplicates(B, 6);
    cout << k << endl;
    for(int i = 0; i < k; ++i){
        cout << B[i] << " ";
    }
    cout << endl;


    return 0;
}


