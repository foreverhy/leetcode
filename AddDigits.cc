#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int addDigits(int num) {
        if (num < 10) return num;
        int ret = num % 9;
        return ret ? ret : 9;
    }
};



int main(){
    Solution slu;


    return 0;
}


