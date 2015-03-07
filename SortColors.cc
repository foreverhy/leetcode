
#include <algorithm>
#include <cstring>



class Solution{
  public:
    void sortColors(int A[], int n){
        int left = 0, lf = 0;
        int right = n - 1;
        while(left <= right){
            for(; lf < left && A[lf] == 0; ++lf);
            for(; right > left && A[right] > 1; --right);
            if(A[left] > 1){
                A[left] = A[right];
                A[right] = 2;
                --right;
            }else if(A[left] < 1){
                if(left != lf){
                    A[left] = A[lf];
                    A[lf] = 0;
                }
                ++lf;
                ++left;
            }else{
                ++left;
            }
        }
    }
};
