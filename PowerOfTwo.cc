#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        int r = 0;
        while (n) {
            n = n & (n - 1); 
            if (++r > 1) return false;
        }
        return r == 1;
    }
};



int main(){
    Solution slu;


    return 0;
}


