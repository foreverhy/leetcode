#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int s = m ^ n;
        s |= s >> 1; s |= s >> 2; s |= s >> 4; s |= s >> 8; s |= s >> 16;
        return m & ~s;
    }
};



int main(){
    Solution slu;


    return 0;
}


