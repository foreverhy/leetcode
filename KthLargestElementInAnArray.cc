#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int low = 0, high = nums.size();
        --k;
        while (low < high) {
            auto pivot = nums[low];
            int i = low + 1, j = high - 1;
            for (;;) {
                for (; i <= j && nums[i] >= pivot; ++i);
                for (; j >= i && nums[j] <= pivot; --j);
                if (i >= j) break;
                std::swap(nums[i], nums[j]);
            }
            std::swap(nums[low], nums[j]);
            if (k == j) {
                return nums[j];
            }
            if (k < i) {
                high = j;
            } else {
                low = j + 1;
            }
        }
        return nums[low];
    }
};



int main(){
    Solution slu;

    vector<int> a = {3, 2, 1, 5, 6, 4};
    cout << slu.findKthLargest(a, 5) << endl;

    return 0;
}


