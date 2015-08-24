#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int missingNumber(vector<int> &nums) {
        int ret = 0;
        int i = 0;
        for (auto a : nums) {
            ret ^= a ^ (i++);
        }
        ret ^= i;
        return ret;
    }
};



int main(){
    Solution slu;
    std::vector<int> a = {2, 1, 3};
    cout << slu.missingNumber(a) << endl;


    return 0;
}


