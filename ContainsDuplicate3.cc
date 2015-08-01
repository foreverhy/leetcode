#include "leet.h"




#include <algorithm>
#include <cstring>
#include <set>

class Solution{
  public:
    typedef long long i64;
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        std::set<i64> set;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }
            i64 left = static_cast<i64>(nums[i]) - t;
            i64 right = static_cast<i64>(nums[i]) + t;
            auto iter = set.lower_bound(left);
            if (iter != set.end() && *iter <= right) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};



int main(){
    Solution slu;

    vector<int> a {1, 2};
    a = {0, 2147483647};
    a = {0,10,22,15,0,5,22,12,1,5};
    cout << slu.containsNearbyAlmostDuplicate(a, 3, 3) << endl;

    return 0;
}


