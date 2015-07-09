#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{

  public:
    using ll = long long;
    int countDigitOne(int n) {
        ll ret = 0;
        for (ll e = 1; e <= n; e *= 10) {
            ll lhs = n / e;
            ll rhs = n % e;
            ll now = lhs % 10;
            if (now == 0) {
                ret += (lhs / 10) * e;
            } else if (now == 1) {
                ret += rhs + 1;
                ret += (lhs / 10) * e;
            } else {
                ret += (lhs / 10 + 1) * e;
            }
        }
        return ret;
    }
};



int main(){
    Solution slu;

    int x;
    x = 1410065408;
    cout << slu.countDigitOne(x) << endl;
    while (cin >> x) {
        cout << slu.countDigitOne(x) << endl;
    }

    return 0;
}


