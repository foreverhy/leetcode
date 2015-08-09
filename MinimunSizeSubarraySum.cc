#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int ret = 0x7fffffff;
        auto left = nums.begin();
        auto right = nums.begin();
        int sum = *left;
        if (sum >= s) {
            return 1;
        }
        for (++right; right != nums.end(); ++right) {
            sum += *right;
            while (sum >= s && left <= right) {
                ret = std::min(ret, static_cast<int>(right - left) + 1);
                sum -= *left;
                ++left;
            }
            if (left > right) {
                return ret;
            }
        }
        while (sum >= s && left != nums.end()) {
            ret = std::min(ret, static_cast<int>(nums.end() - left));
            sum -= *left;
            ++left;
        }
        return ret == 0x7fffffff ? 0 : ret;
    }
};



int main(){
    Solution slu;

    vector<int> a {
        2, 3, 1, 2, 4, 3
    };

    cout << slu.minSubArrayLen(7, a) << endl;

    return 0;
}


