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
    int removeElement(int A[], int n, int elem){
        int i = 0, j = n;
        while(i < j){
            if(A[i] == elem){
                std::swap(A[i], A[--j]);
            }else{
                ++i;
            }
        }
        return j;
    }

};



int main(){
    Solution slu;
    using std::cin;

    int A[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 6, 6, 6};

    int k = slu.removeElement(A, 14, 2);

    for(int i = 0; i < k; ++i){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


