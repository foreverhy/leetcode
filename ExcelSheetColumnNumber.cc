#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int titleToNumber(string s) {
        int ans = 0;
        int mul = 1;
        for (auto iter = s.crbegin(); iter != s.crend(); ++iter) {
            int num = *iter - 'A' + 1;
            ans += num * mul;
            mul *= 26;
        }
        return ans;
    }
};



int main(){
    Solution slu;

    string s;
    while (cin >> s) {
        cout << slu.titleToNumber(s) << endl;
    }


    return 0;
}


