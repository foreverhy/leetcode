#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:

    int solve(int ret, int n) {
        for (; n >= 0; --n) {
            if (n % 5 == 0) break;
        }
        if (n <= 0) return ret;
        int times = n / 5;
        return solve(ret + times, times);

    }
    int trailingZeroes(int n) {
        return solve(0, n);
    }
};



int main(){
    Solution slu;

    int x;
    while (cin >> x) {
        cout << slu.trailingZeros(x) << endl;
    }

    return 0;
}


