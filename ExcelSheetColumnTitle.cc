#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    string convertToTitle(int n) {
        string ret("");
        while (n) {
            auto r = n % 26;
            n /= 26;
            if (r) {
                ret = static_cast<char>('A' - 1 + r) + ret;
            } else {
                ret = 'Z' + ret;
                if (n) --n;
            }
        }
        return ret;
    }
};



int main(){
    Solution slu;

    int x;
    while (cin >> x) {
        cout << slu.convertToTitle(x) << endl;
    }

    return 0;
}


