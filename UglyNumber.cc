#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    bool isUgly(int num) {
        while (num > 1) {
            if (!(num & 1)) {
                num >>= 1;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                break;
            }
        }
        return num == 1;
    }
};



int main(){
    Solution slu;


    return 0;
}


