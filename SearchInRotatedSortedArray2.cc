
#include <algorithm>


class Solution{
  public:
    int offset, N;
    inline int trans(int x){
        return (x + offset) % N;
    }
    bool search(int A[], int n, int target){
        int last = -0x7fffffff;
        offset = 0;
        N = n;
        for(offset = 0; offset < n; ++offset){
            if(A[offset] < last){
                break;
            }else{
                last = A[offset];
            }
        }
        int l = 0, r = N - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int tx = trans(mid);
            if(target == A[tx]){
                return true;
            }
            if(target < A[tx]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return false;
    }
};

