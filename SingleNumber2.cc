#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    unsigned long long count;

    int singleNumber(vector<int> &nums){
        int ret = 0;
        for (int i = 0; i < 32; ++i){
            int cnt = 0;
            int mask = 1 << i;
            for (auto a : nums)if (a & mask){
                ++cnt;
                if (3 == cnt){
                    cnt = 0;
                }
            }
            if (cnt) ret |= mask;
        }
        return ret;
    }
};



int main(){
    Solution slu;
    vector<int> a = {1, 3, 45,2, 2,45, 1, 45, 2, 3, 3};

    cout << slu.singleNumber(a) << endl;


    return 0;
}


