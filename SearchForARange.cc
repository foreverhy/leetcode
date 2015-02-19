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

    int L(int A[], int l, int r, int target){
        if(l > r){
            return -1;
        }
        if(l == r){
            return A[l]==target? l: -1;
        }
        //cout << "l:" << l << " r:" << r;
        int mid = (l + r) >> 1;
        //cout << " mid:" << mid << endl;
        if(target <= A[mid]){
            return L(A, l, mid, target);
        }else{
            return L(A, mid + 1, r, target);
        }

    }

    int R(int A[], int l, int r, int target){
        if(l > r){
            return -1;
        }
        if(l == r){
            return A[l]==target? l: -1;
        }
        //cout << "l:" << l << " r:" << r;
        int mid = (l + r + 1) >> 1;
        //cout << " mid:" << mid << endl;
        if(target >= A[mid]){
            return R(A, mid, r, target);
        }else{
            return R(A, l, mid - 1, target);
        }

    }


    vector<int> searchRange(int A[], int n, int target){
        return {L(A, 0, n - 1, target), R(A, 0, n - 1, target)};
        //return {L(A, 0, n - 1, target)};
    }

};



int main(){
    Solution slu;
    using std::cin;

    vector<int>a = {8, 8, 8, 8, 8, 8};
    auto ans = slu.searchRange(a.data(), a.size(), 8);
    for(auto &a: ans){
        cout << a << " ";
    }

    cout << endl;
    return 0;
}


