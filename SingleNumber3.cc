#include "leet.h"




#include <algorithm>
#include <cstring>
#include <functional>

class Solution{
  public:
    vector<int> singleNumber(vector<int> &nums){
        int x = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        x &= -x;
        vector<int> ret {0, 0};
        for (auto a : nums) {
            if (a & x) {
                ret[0] ^= a;
            } else {
                ret[1] ^= a;
            }
        }
        return ret;
    }
};



int main(){
    Solution slu;


    return 0;
}


