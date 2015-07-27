#include "leet.h"




#include <algorithm>
#include <cstring>

#include <set>

class Solution{
  public:
    bool isHappy(int n) {
        std::set<int> set;
        while (true) {
            if (1 == n) {
                return true;
            }
            if (set.find(n) != set.end()) {
                return false;
            }
            set.insert(n);
            int n_ = 0;
            while (n) {
                int tmp = n % 10;
                n_ += tmp * tmp;
                n /= 10;
            }
            n = n_;
        }
    }
};



int main(){
    Solution slu;


    return 0;
}


