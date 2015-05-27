#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int singleNumber(vector<int> &nums){
        int ret = 0;
        for (auto a : nums){
            ret ^= a;
        }
        return ret;
    }
};



int main(){
    Solution slu;


    return 0;
}


