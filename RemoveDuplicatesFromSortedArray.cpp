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
        int k = 0;
        int last = 0x3f3f3f3f;
        for(int i = 0; i < n; ++i){
            if(A[i] != last){
                last = A[k++] = A[i];
            }
        }
        return k;
    }

};



int main(){
    Solution slu;
    using std::cin;

    int A[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 6, 6, 6};

    int k = slu.removeDuplicates(A, 1);

    for(int i = 0; i < k; ++i){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


