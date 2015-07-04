#include "leet.h"




#include <algorithm>
#include <cstring>

class Solution{
  public:
    int findPeakElement(vector<int> &nums) {
        int low = 0, high = nums.size();
        while (low < high) {
            auto mid = (low + high) >> 1;
            if (mid > 0 && mid < high - 1) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                if (nums[mid] > nums[mid + 1]) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            if (0 == mid) {
                if (mid == high - 1 || nums[mid] > nums[mid + 1]) return mid;
                low = mid + 1;
            }
            if (high - 1 == mid) {
                if (mid == 0 || nums[mid] > nums[mid - 1]) return mid;
                high = mid;
            }
        }
        return low;
    }
};



int main(){
    Solution slu;

    vector<int> a = {1, 2, 3, 1};
    cout << slu.findPeakElement(a) << endl;

    return 0;
}


