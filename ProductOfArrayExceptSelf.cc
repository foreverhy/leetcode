#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> output(nums.size(), 1); 
        int len = nums.size();
        int left = 1, right = 1;
        for (int i = 0; i < len; ++i) {
            output[i] *= left;
            output[len - 1 - i] *= right;
            left *= nums[i];
            right *= nums[len - i - 1];
        }
        return output;
    }
};



int main(){
    Solution slu;

    vector<int> a {1,2,3,4};
    cout << slu.productExceptSelf(a) << endl;

    return 0;
}


