#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int lastmax = nums[0];
        int lastmin = nums[0];
        int ans = lastmax;
        for (auto iter = nums.begin() + 1; iter != nums.end(); ++iter) {
            if (*iter >= 0) {
                auto tmp1 = *iter * lastmax;
                auto tmp2 = *iter * lastmin;
                lastmax = std::max(*iter, tmp1);
                lastmin = std::min(*iter, tmp2);
            } else {
                auto tmp1 = *iter * lastmin;
                auto tmp2 = *iter * lastmax;
                lastmax = std::max(*iter, tmp1);
                lastmin = std::min(*iter, tmp2);
            }
            ans = std::max(ans, lastmax);
        }
        return ans;
    }
};



int main(){
    Solution slu;

    vector<int> a = {2, 3, -2, 4};
    a = {-2,3,-4};
    a = {-4,-3,-2};
    cout << slu.maxProduct(a) << endl;

    return 0;
}


