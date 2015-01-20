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
    int searchInsert(int A[], int n, int target){
        int left = 0, right = n;
        while(left < right){
            int mid = (left + right) >> 1;
            if(target == A[mid]){
                return mid;
            }else if (target < A[mid]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

};



int main(){
    Solution slu;
    using std::cin;

    int a[] = {1, 3, 5, 6};
    cout << slu.searchInsert(a, 4, 0) << endl;

    int b[] = {};
    cout << slu.searchInsert(b, 0, 9) << endl;

    return 0;
}


