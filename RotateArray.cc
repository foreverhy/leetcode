#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    void rotate(vector<int> &nums, int k) {
        int sz = nums.size();
        k %= sz;
        if (0 == k) return;
        if (k == (sz >> 1)) {
            for (int i = 0; i < k; ++i) {
                std::swap(nums[i], nums[i + k]);
            }
            return;
        }
        int idx = 0;
        int val = nums[0];
        int cnt = sz;
        while(cnt--) {
            auto target = (idx + k) % sz;
            cout << val << " " << nums[target] << endl;
            std::swap(val, nums[target]);
            idx = target;
        }
    }
};



int main(){
    Solution slu;
    vector<int> a {
        1,2,3,4,5,6
    };
    slu.rotate(a, 2);
    cout << a << endl;


    return 0;
}


