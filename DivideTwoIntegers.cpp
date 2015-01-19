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
#include <climits>
#include <cstdint>

class Solution{
  public:
    int abs(int x){
        return x > 0? x: -x;
    }
    int divide(int dividend, int divisor){
        std::int64_t ans = 0;
        std::int64_t dvd = dividend;
        std::int64_t dvi = divisor;
        int positive = 1;
        if(dvd < 0){
            positive = -positive;
            dvd = -dvd;
        }

        if(dvi < 0){
            positive = -positive;
            dvi = -dvi;
        }

        for(int i = 31; i >= 0; --i){
            if((dvd >> i) >= dvi){
                ans += (1LL << i);
                dvd -= (dvi) << i;
            }
        }
        if(positive < 0)ans = -ans;
        return (ans > INT_MAX || ans < INT_MIN)? INT_MAX: ans;
    }

};



int main(){
    Solution slu;
    using std::cin;
    int x, y;
    while(cin >> x >> y){
        cout << slu.divide(x, y) << endl;
    }

    return 0;
}


